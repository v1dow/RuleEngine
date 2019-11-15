%{
/****************************************************************************
parser.y
Parser for a simple calculator. The parser is implemented using a C++ class.
This is specified by selecting the -Tcpp option in AYACC (the "C++"
selection from the Target Language combo box in the AYACC Options dialog
box).


The parser implements the usual floating point arithmetic using the
addition, subtraction, multiplication and division operators, and unary
minus. Expressions can be grouped and simple error recovery is supported. In
addition it is now posssible to assign values to variables, and to use such
values in expressions.
****************************************************************************/
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <time.h>
#include <unistd.h>
#include <vector>
#include <array>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "reason.h"
#include "calc.h"
#include "optimize.h"
#include "oriAllocator.h"
#define RAND_M 32767
using namespace calc;
calc::calc_parser *parser;

mutex mtx;
condition_variable cv;
bool ready = false;
bool processed = false;
bool fileReady = false;

enum StatOpNo
{
    opMAX,
    opMIN,
    opMEAN,
    opMEDIAN,
    opVAR,
    opSTD
};

extern "C"
{
	extern int yylex(void);
	extern void yyerror(const char *);
	extern void scan_string(const char* str);
	extern void delete_buffer();
}
%}

%union {
	symbol* sym;
	double value;
	LISTDOUBLE* listvalue;
	char*	strvalue;
	double* address;
}


%type <value> expr
%type <listvalue> listexpr
%type <value> logexpr
%type <value> stmt
%type <strvalue> strexpr



%left AND,OR
%left '+', '-',MORE,LESS,MEQL,LEQL,EQL,NOTEQL,BING,LIAN
%left '*', '/'
%right UMINUS,NOT


%token <value> NUMBER
%token <listvalue> LISTNUMBER
%token <sym> ID
%token <sym> STRID
%token <sym> LID
%token <strvalue> STRING
%token <address> ADDRESS

%token    IF
%token    AND
%token    OR
%token    NOT
%token    EQL
%token    NOTEQL
%token    LEQL
%token    MEQL
%token    LESS
%token    MORE
%token    LIAN
%token    BING

%token LOG
%token SIN
%token ASIN
%token COS
%token ACOS
%token TAN
%token ATAN
%token STRIN
%token EXP
%token POW
%token SQR
%token MAX
%token MIN
%token MAXS
%token MEAN

%token EMPTY




%%
lines
	: lines line				
	| /* empty */
	;

line
	: expr '\n'					{  parser->m_result = (double)$1; }

	| expr ';'							{  parser->m_result = (double)$1; }
	| expr ';'	'\n'					{  parser->m_result = (double)$1;}
	| '\n'						{;}
	| table '\n'
	| table ';' '\n'
	| strexpr '\n'					{  if(parser->worktype==0){parser->m_strresult = (char*)$1;}  else parser->m_strresult=NULL;}
	| strexpr ';' '\n'					{ if(parser->worktype==0){parser->m_strresult = (char*)$1; } else parser->m_strresult=NULL;}
	| listexpr '\n'					{  parser->m_lresult = (LISTDOUBLE*)$1; }
	| listexpr ';'	'\n'					{  parser->m_lresult = (LISTDOUBLE*)$1;}
	| stmt '\n'					{  parser->m_result = (double)$1;}
	| error '\n'				{  yyerrok; }
	;
stmt
   	 :expr			{ $$=$1; }
   	 | ID '=' stmt			{ $$ = parser->assign($1, $3); }
   	 ;	
logexpr
	: '(' logexpr ')'				{ $$ = $2; }	
	| expr						{ if($1!=0)$$ =1; else $$ =0; }
	;
table
	: expr ',' expr	{;}
	| expr ',' strexpr{;}	
	| strexpr ',' expr{;}	
	| strexpr ',' strexpr{;}	
	| table ',' expr{;}
	| table ',' strexpr{;}
	;				
expr
	: ID '=' expr				{ $$ = parser->assign($1,$3); }
	| ID LIAN STRING			{ $$ = parser->GetLIAN($1,$3); }	
	| STRING LIAN ID			{ $$ = parser->GetLIAN($1,$3); }	
	| ID BING STRING			{ $$ = parser->GetBING($1,$3); }	
	| STRING BING ID			{ $$ = parser->GetBING($1,$3); }	
	| ID '=' EMPTY				{ parser->setnull($1); }
	| ID					{ $$= parser->GetIDValue($1); }

	| expr '+' expr				{ $$ = $1 + $3; }
	| expr '-' expr				{ $$ = $1 - $3; }
	| expr '*' expr				{ $$ = $1 * $3; }
	| expr '/' expr				{ $$ = parser->divide($1, $3);}
	| expr AND expr				{ $$ = parser->GetAnd($1,$3); }
	| expr OR expr				{ $$ = parser->GetOr($1,$3); }
	| expr LEQL expr			{ $$ = parser->GetLEQL($1,$3); }
	| expr MEQL expr			{ $$ = parser->GetMEQL($1,$3); }
	| expr LESS expr			{ $$ = parser->GetLESS($1,$3); }
	| expr MORE expr			{ $$ = parser->GetMORE($1,$3); }
	| expr EQL expr				{ $$ = parser->GetEQL($1,$3); }
	| expr NOTEQL expr			{ $$ = parser->GetNOTEQL($1,$3); }

	| NOT logexpr				{ $$ = parser->GetNot($2); }

	| strexpr EQL strexpr			{ $$ = parser->GetEQL($1,$3); }
	| STRID EQL strexpr			{ $$ = parser->GetEQL($1,$3); }
	| strexpr EQL STRID			{ $$ = parser->GetEQL($1,$3); }
	| STRID EQL STRID			{ $$ = parser->GetEQL($1,$3); }

	| strexpr STRIN strexpr			{ $$ = parser->GetStrIn($1,$3); }
	| STRID STRIN strexpr			{ $$ = parser->GetStrIn($1,$3); }
	| strexpr STRIN STRID			{ $$ = parser->GetStrIn($1,$3); }
	| STRID STRIN STRID			{ $$ = parser->GetStrIn($1,$3); }

	| strexpr NOTEQL strexpr		{ $$ = parser->GetNOTEQL($1,$3); }
	| STRID NOTEQL strexpr			{ $$ = parser->GetNOTEQL($1,$3); }
	| strexpr NOTEQL STRID			{ $$ = parser->GetNOTEQL($1,$3); }
	| STRID NOTEQL STRID			{ $$ = parser->GetNOTEQL($1,$3); }

	| '(' expr ')'				{ $$ = $2; }
	| '-' expr %prec UMINUS			{ $$ = -$2; }
	| NUMBER				{ $$ = $1; }
	| SIN '(' expr ')'			{ $$ = sin($3); }
	| ASIN '(' expr ')'			{ $$ = asin($3); }
	| SQR '(' expr ')'			{ $$ = sqrt($3); }
	| COS '(' expr ')'			{ $$ = cos($3); }
	| ACOS '(' expr ')'			{ $$ = acos($3); }
	| TAN '(' expr ')'			{ $$ = tan($3); }
	| ATAN '(' expr ')'			{ $$ = atan($3); }
	| POW '(' expr ',' expr ')'		{ $$ = parser->exponent2($3,$5); }
	| EXP '(' expr ')'			{ $$ = exp($3); }
	| LOG '(' expr ')'			{ $$ = log($3); }
	| MAX '(' listexpr ')'		{ $$ = parser->GetMax($3); }
	| MAXS '(' ADDRESS ',' expr ')'		{ $$ = parser->GetMaxs($3,$5); }
	| MIN '(' listexpr ')'		{ $$ = parser->GetMin($3); }
	| MEAN '(' listexpr ')'		{ $$ = parser->GetMean($3); }
	;
listexpr
	: LISTNUMBER			{ $$ = $1; }
	| LID '=' listexpr				{ $$ = parser->assignlist($1,$3); }
	| LID '=' EMPTY				{ parser->setlistnull($1); }
	| LID					{ $$ = parser->GetLIDValue($1); }
	;
strexpr
	: STRING 				{ if(parser->worktype==0)$$ = $1; }
	| STRID '=' EMPTY			{ if(parser->worktype==0)parser->setnull($1); }
	| STRID '=' strexpr			{ if(parser->worktype==0)$$ = parser->assignchar($1, $3); }
	| strexpr '+' strexpr			{ if(parser->worktype==0)$$ = parser->AddString($1,$3);}
	| STRID '+' strexpr			{ if(parser->worktype==0)$$ = parser->AddString($1,$3);}
	| strexpr '+' STRID			{ if(parser->worktype==0)$$ = parser->AddString($1,$3);}
	| STRID '+' STRID			{ if(parser->worktype==0)$$ = parser->AddString($1,$3);}
	| STRID					{ if(parser->worktype==0)$$ = parser->GetIDCharValue($1); }
	;	
%%

	void yyerror(const char *msg)
{
	printf("Error Message:%s\n", msg);
}