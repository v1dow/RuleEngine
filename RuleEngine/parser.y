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
#include "reason.h"
#include "calc.h"
#include "optimize.h"
#include "oriAllocator.h"
#define RAND_M 32767
using namespace calc;
calc::calc_parser *parser;

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
	| ID					{ $$= parser->GetIDValue($1);}

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
	printf("Error Message:%s\n",msg);
}


string ConvertToString(double value) 
{
	stringstream ss;
	ss << value;
	return ss.str();
}

string ConvertListToString(LISTDOUBLE* lb)
{
	string s = "[";
    for(auto it = lb->begin();it != lb->end();it++)
    {
        double d;
        d = *it;
        s += to_string(d);
        if(it != lb->end()-1)
            s += ",";
    }
    s += "]";
    return s;
}

void updatePara(oriALlocator* oa, PARALIST* pl, int index)
{
	string pstring;
	string value;
	double dvalue = 0;
	LISTDOUBLE* lv;
	PARALIST::iterator pit;
	for(pit = pl->begin();pit != pl->end();pit++)
	{
		lv = oa->getMemData()->at(index);
		// for(double d = 0;d < oa->roundLength;d++)
		// {
		// 	fin>>dvalue;
		// 	lv->push_back(dvalue);
		// }
		(*pit)->SetListValue(lv);
		value = ConvertListToString(lv);
        pstring = (*pit)->GetName() + "=" + value+"\n";
        scan_string(pstring.c_str());
        cout<<"The info of para is : "<< pstring<<endl;
        yyparse();
	}
}

void initReasonwork(reason *re,calc::calc_parser *parser)
{
	PARALIST *pl = re->GetParaList();
	TOKENLIST *tl = re->GetTokenList();
	PARALIST::iterator pit;
	TOKENLIST::iterator tit;
	string value;
	string pstring;
		
	string tstring;
	double dvalue=0;
	LISTDOUBLE* lvalue = new deque<double>();
	/*
	for(pit = pl->begin();pit!=pl->end();pit++)
	{
		dvalue = 0.0;
		value = ConvertToString(dvalue);
		pstring = (*pit)->GetName() + "=" + value+"\n";
		scan_string(pstring.c_str());
		yyparse();
	}
	*/
	lvalue->push_back(1);
	for(pit = pl->begin();pit!=pl->end();pit++)
	{
		value = ConvertListToString(lvalue);
		pstring = (*pit)->GetName() + "=" + value+"\n";
		scan_string(pstring.c_str());
		yyparse();
	}
	/*
	for(tit = tl->begin();tit!=tl->end();tit++)
	{
		tstring = (*tit)->GetTokenName() + "=" + (*tit)->GetTokenContent()+"\n";
		scan_string(tstring.c_str());
		yyparse();
	}
	*/
	delete lvalue;
}

void dataProduce(reason *re)
{
        PARALIST *pl = re->GetParaList();
        PARALIST::iterator pit;
        string value;
        double dvalue=0;
        string pstring;
        for(pit= pl->begin();pit!=pl->end();pit++)
        {
                dvalue = (int)(((rand()%RAND_M+1)*1.0/(RAND_M+1)*100.0)*100.0)/100.0;
                value = ConvertToString(dvalue);
                pstring = (*pit)->GetName() + "=" + value+"\n";
                scan_string(pstring.c_str());
//                cout<<"The info of para is : "<< pstring<<endl;
                yyparse();
        }
}

//change
void changeParaValue(reason *re,rule *tmpRule)
{
    double value;

    string conStr=tmpRule->GetConsequent();
    int index=conStr.find('=');

    string name=conStr.substr(0,index);
    string sValue=conStr.substr(index+1);
    value=atof(sValue.c_str());

//独立规则没有后件参数??
//    PARALIST *CPList=(tmpRule)->GetConParaList();
//    PARALIST::iterator prit;
//    for(prit = CPList->begin();prit!=CPList->end();prit++)
//    {
//        (*prit)->SetValue(value);
//        cout<<"(改变的参数:"<<(*prit)->GetName()<<":"<<(*prit)->GetValue()<<")"<<endl;
//    }

    //遍历所有参数 找到该参数再改变
    PARALIST *pl = re->GetParaList();
    PARALIST::iterator pit;
    for(pit= pl->begin();pit!=pl->end();pit++)
    {

        if( (*pit)->GetName()==name )
        {
            (*pit)->SetValue(value);
            cout<<"(改变的参数:"<<(*pit)->GetName()<<":"<<(*pit)->GetValue()<<")"<<endl;
        }

    }
}
//change

void reasonRules(reason *re,calc::calc_parser* parser)
{
	TOKENLIST *tl = re->GetTokenList();
	RULELIST *rlist = re->GetRuleList();
	TOKENLIST::iterator tit;
	RULELIST::iterator rit;
    PARALIST *ptmplist = NULL;
    PARALIST::iterator ptmpit;
	string value;

	string rstring;
	string tstring;

	for(rit = rlist->begin();rit!=rlist->end();rit++)
	{
		rstring = (*rit)->GetAntecedent()+"\n";
		scan_string(rstring.c_str());
		yyparse();
		if(parser->GetResult()==1)
        {
            cout<<"Trigger rule: "<<(*rit)->GetRuleName()<<"---"<<(*rit)->GetAntecedent()<<" THEN "<<(*rit)->GetConsequent()<<endl;
        }
	}
}

void reasonIndeRules(reason *re,calc::calc_parser *parser)
{

	TOKENLIST *tl = re->GetTokenList();
	RULELIST *inderlist = re->GetIndeRules();
	TOKENLIST::iterator tit;
	RULELIST::iterator rit;
        PARALIST *ptmplist = NULL;
        PARALIST::iterator ptmpit;
	string value;

		
	string rstring;
	string tstring;
			
	for(tit = tl->begin();tit!=tl->end();tit++)
	{
		tstring = (*tit)->GetTokenName() + "=" + (*tit)->GetTokenContent()+"\n";
		scan_string(tstring.c_str());
		yyparse();
	}

	for(rit = inderlist->begin();rit!=inderlist->end();rit++)
	{
		rstring = (*rit)->GetReplacedRule()+"\n";
		scan_string(rstring.c_str());
		yyparse();
		if(parser->GetResult()==1)
                {
                    //cout<<"Trigger indepedent rule: "<<(*rit)->GetRuleName()<<"---"<<(*rit)->GetAntecedent()<<endl;
                    cout<<"触发独立规则: "<<(*rit)->GetRuleName()<<"---"<<(*rit)->GetAntecedent()<<" THEN "<<(*rit)->GetConsequent()<<endl;

                    //change
                    //rule *tmpRule=*rit;
                    changeParaValue(re,*rit);
                    //change

                }
		
	}


			
}


void reasonNestedRules(reason *re,calc::calc_parser *parser)
{
	NESTEDRULELIST *nrlist = re->GetNestedRules();
	TOKENLIST *tl = re->GetTokenList();
	
	RULELIST::iterator nrit;
		
	PARALIST *ptmplist = NULL;
	
	PARALIST::iterator ptmpit;
	TOKENLIST *ttmplist;
	TOKENLIST::iterator ttmpit;
	TOKENLIST::iterator tit;	
	NESTEDRULELIST::iterator neit;
			
	
	
	string tstring;
	string ntstring;
	string constring;
	string ptokenstring;
	
	
	
	
	for(tit = tl->begin();tit!=tl->end();tit++)
	{
		tstring = (*tit)->GetTokenName() + "=" + (*tit)->GetTokenContent()+"\n";
		scan_string(tstring.c_str());
		yyparse();
	}

	for (neit=nrlist->begin();neit!=nrlist->end();neit++)
        {
            for (nrit = (*neit)->begin();nrit!=(*neit)->end();nrit++)
            {
                ntstring = (*nrit)->GetReplacedRule()+"\n";
                //cout<<ntstring<<endl;
                scan_string(ntstring.c_str());
                yyparse();
                if(parser->GetResult()==1)
                {
                    //cout<<"Trigger nested rule: "<<(*nrit)->GetRuleName()<<"---"<<(*nrit)->GetAntecedent()<<endl;
                    cout<<"触发嵌套规则: "<<(*nrit)->GetRuleName()<<"---"<<(*nrit)->GetAntecedent()<<endl;

                    //change
                    changeParaValue(re,*nrit);
                    //change

                    constring = (*nrit)->GetConsequent()+"\n";
                    //cout<<constring<<endl;
                    //cout<<parser->GetResult()<<endl;
                    scan_string(constring.c_str());
                    yyparse();
                    //cout<<parser->GetResult()<<endl;


                    ptmplist = (*nrit)->GetConParaList();
                    for(ptmpit=ptmplist->begin();ptmpit!=ptmplist->end();ptmpit++)
                    {

                        ttmplist = (*ptmpit)->QuotedTokenList;
                        for(ttmpit=ttmplist->begin();ttmpit!=ttmplist->end();ttmpit++)
                        {
                            //cout<<"No!!!!"<<endl;
                            ptokenstring = (*ttmpit)->GetTokenName() + "="+(*ttmpit)->GetTokenContent()+"\n";
                            scan_string(ptokenstring.c_str());
                            yyparse();
                        }
                    }
                    cout<<endl;

                }

            }

	}	
}

int main(int argc,char *argv[])
{
    int n = -1;

    parser= new calc::calc_parser();

    if (parser->create(0)!=1) {
        printf("Create calc_parser failed!\n");
    }
	
	array<int,6> opTable{0,0,0,0,0,0};

    if(argc == 1)
    {
        cout<<"现在用随机产生的数据进行规则推理:"<<"(每隔三秒推理一次)"<<endl<<endl<<endl;
        sleep(3);

        reason *re = new reason();
        re->InitReasonNetwork();

        srand((unsigned)time(NULL));
        initReasonwork(re,parser);


        while(1)
        {
            cout<<"************"<<endl;
            dataProduce(re);
            reasonIndeRules(re,parser);
            reasonNestedRules(re,parser);




            cout<<"************"<<endl<<endl<<endl;

            sleep(3);
        }
        delete re;
    }
    if(argc == 2 )
    {

        ifstream fin(argv[1]);
        if(!fin)
        {
            printf("no file data!\n");
            exit(1);
        }


        else
        {
            cout<<"现在从该文档中读入数据"<<endl;
            sleep(1);

			int curIndex = 0;
			double value = 0;
			bool mflag = false;
			bool dflag = false;
			bool rflag = false;

			double lo = 0.8;
			double hi = 1.5;

			srand((unsigned)time(NULL));

            reason *re = new reason();
            re->InitReasonNetwork();
            initReasonwork(re,parser);
			oriAllocator* oa = new oriAllocator();
			optimize* opt = new optimize();
			opt->setOpTable(re);
			opt->testOp();

            PARALIST *pl = re->GetParaList();
			/*
            PARALIST::iterator pit;
            string value;
            double dvalue=0;
            string pstring;
			*/

            //ifstream fin("data.txt");
			/*
            for(pit= pl->begin();pit!=pl->end();pit++)
            {
                    fin>> dvalue;

                    //change
                    (*pit)->SetValue(dvalue);
                    //change

                    value = ConvertToString(dvalue);
                    pstring = (*pit)->GetName() + "=" + value+"\n";
                    scan_string(pstring.c_str());
                    //cout<<"The info of para is : "<< pstring<<endl;
                    yyparse();
            }
			*/

			while(1)
			{
				value = lo + static_cast<double>(rand())/(static_cast<double>(RAND_M/(hi-lo)));
				if(mflag){
					// for(int index = 0;index < oa->GetInferRound();index++){
					// 	updatePara(oa,pl,curIndex);
					// 	reasonRules(re,parser);
					// 	if(index == oa->GetInferRound()-1)
					// 		rflag = true;
					// }
					if(curIndex == oa->GetInferRound()){
						curIndex = 0;
						rflag = true;
					}
					if(curIndex < oa->GetInferRound()){
						updatePara(oa,pl,curIndex);
						reasonRules(re,parser);
						curIndex++;
					}
					if(dflag && rflag){
						tc->loadFromDisk();
						dflag = false;
						rflag = false;
					}else{
						dflag = oa->appendFile(value);
					}
				}else{
					mflag = oa->genMemData(value);
				}
			}

            //reasonIndeRules(re,parser);
            //reasonNestedRules(re,parser);

//            for(pit= pl->begin();pit!=pl->end();pit++)
//            {

//                cout<<(*pit)->GetName()<<":"<<(*pit)->GetValue()<<endl;
//            }

            //cout<<"************"<<endl<<endl;
            //delete pl;
            delete re;
        }
    }
	
	
    delete parser;
    return n;

/*
    int n = -1;
    parser= new calc::calc_parser();

	double* faddress;

	vector<double> v;
	double count = 0;

    if (parser->create(0)!=1) {
        printf("Create calc_parser failed!\n");
    }
    if(argc == 2 )
    {

        ifstream fin(argv[1]);
        if(!fin)
        {
            printf("no file data!\n");
            exit(1);
        }


        else
        {
			while(!fin.eof()){
				string strbuf;
				getline(fin,strbuf);
				v.push_back(atof(strbuf.c_str()));
				count++;
			}
			faddress = &v[0];
		}
		cout<<"address:"<<faddress<<endl;
		cout<<"data:"<<endl;
		for(auto iter=v.begin();iter!=v.end();iter++)
		{
			cout<<*iter<<endl;
		}
		fin.close();
	}

	yyparse();
	delete parser;
	return n;
*/
}

