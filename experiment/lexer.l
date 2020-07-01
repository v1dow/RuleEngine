%{
/****************************************************************************
lexer.l
Lexical analyser for a simple calculator. The lexical analyser is
implemented using a C++ class. This is specified by selecting the -Tcpp
option in ALex (the "C++" selection from the Target Language combo box in
the ALex Options dialog box).
****************************************************************************/
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <errno.h>
#include "calc.h"
#include "parser.tab.h"

using namespace calc;
extern calc::calc_parser *parser;
extern "C" 
{
	int yylex(void);
	void yyerror(const char *);
	extern void scan_string(const char* str);
	extern void delete_buffer();
}
%}

exponent	([Ee][+-]?[0-9]+)
string '[^\n^']*'
%%


[0-9]+"."[0-9]*{exponent}?	|
"."[0-9]+{exponent}?		|
[0-9]+{exponent}?			{ yylval.value = parser->m_lexer.number(yytext); return NUMBER; }

"0x"[a-z0-9]{12}			{ yylval.address = parser->m_lexer.address(yytext); return ADDRESS; }
"["[a-zA-Z0-9_,.]*"]"				{ yylval.listvalue = parser->m_lexer.listnumber(yytext); return LISTNUMBER; }

{string}					{ yylval.strvalue = parser->m_lexer.stringvalue(yytext); return STRING;} 

"SIN"						{ return SIN; }
"sin"						{ return SIN; }
"ASIN"						{ return ASIN; }
"asin"						{ return ASIN; }
"COS"						{ return COS; }
"cos"						{ return COS; }
"ACOS"						{ return ACOS; }
"acos"						{ return ACOS; }
"TAN"						{ return TAN; }
"tan"						{ return TAN; }
"ATAN"						{ return ATAN; }
"atan"						{ return ATAN; }
"strin"						{ return STRIN; }
"STRIN"						{ return STRIN; }
"LOG"						{ return LOG; }
"log"						{ return LOG; }
"EXP"						{ return EXP; }
"exp"						{ return EXP; }
"SQR"						{ return SQR; }
"sqr"						{ return SQR; }
"POW"						{ return POW; }
"pow"						{ return POW; }
"MAX"						{ return MAX; }
"max"						{ return MAX; }
"MIN"						{ return MIN; }
"min"						{ return MIN; }
"MAXS"                      { return MAXS; }
"maxs"						{ return MAXS; }
"MEAN"						{ return MEAN; }
"mean"						{ return MEAN; }
"MEDIAN"					{ return MEDIAN; }
"median"					{ return MEDIAN; }
"VAR"                       { return VAR; }
"var"                       { return VAR; }
"STD"                       { return STD; }
"std"                       { return STD; }
"IF" 						{;}
"AND" 						{return AND;}
"OR" 						{return OR;}
"NOT" 						{return NOT;}

"EMPTY" 						{return EMPTY;}


[a-zA-Z_][a-zA-Z0-9_.]*			{ yylval.sym = parser->m_lexer.id(yytext);  return ID;}
[a-zA-Z_$][a-zA-Z0-9_.$]*		{ yylval.sym = parser->m_lexer.id(yytext);  return STRID;}
[a-zA-Z_$#][a-zA-Z0-9_.$#]*		{ yylval.sym = parser->m_lexer.id(yytext);  return LID;}

"="							{ return '='; }
"+"							{ return '+'; }
"-"							{ return '-'; }
"*"							{ return '*'; }
"/"							{ return '/'; }
"("							{ return '('; }
")"							{ return ')'; }
","							{ return ','; }
";"							{ return ';'; }
"=="   {return EQL;}
"<>" {return NOTEQL;}
"!=" {return NOTEQL;}
"<=" {return LEQL;}
">=" {return MEQL;}
"<" {return LESS;}
">" {return MORE;}
"&"   {return LIAN;}
"|"   {return BING;}

[ \t]							{ int u=0; }
\n							{ return '\n'; }
.							{ /*printf("invalid character '0x%02d'\n", (int)yytext[0])*/; }
%%

void scan_string(const char* str)
{
	YY_BUFFER_STATE bp;
	bp = yy_scan_string(str);
	yy_switch_to_buffer(bp);
}
void delete_buffer()
{
	//yy_delete_buffer(b);
}
int yywrap(void)
{
	return 1;
}
