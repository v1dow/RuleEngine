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
#include <chrono>
#include "func.h"
#include "reason.h"
#include "calc.h"
#include "optimize.h"
#include "oriAllocator.h"
#define RAND_M 32767
using namespace calc;
calc::calc_parser *parser;

/*
mutex mtx;
condition_variable cv;
bool ready = false;
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
*/

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
%token MEDIAN
%token VAR
%token STD

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
	| MEDIAN '(' listexpr ')'   { $$ = parser->GetMedian($3); }
	| VAR '(' listexpr ')'		{ $$ = parser->GetVar($3); }
	| STD '(' listexpr ')'		{ $$ = parser->GetStd($3); }
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

int main(int argc, char *argv[])
{
	int n = -1;

	parser = new calc::calc_parser();

	if (parser->create(0) != 1)
	{
		printf("Create calc_parser failed!\n");
	}

	array<int, 6> opTable{0, 0, 0, 0, 0, 0};

	if (argc == 1)
	{
		cout << "现在用随机产生的数据进行规则推理:"
			 << "(每隔三秒推理一次)" << endl
			 << endl
			 << endl;
		sleep(3);

		reason *re = new reason();
		re->InitReasonNetwork();

		srand((unsigned)time(NULL));
		initReasonwork2(re, parser);

		while (1)
		{
			cout << "************" << endl;
			dataProduce(re);
			//reasonIndeRules(re, parser);
			//reasonNestedRules(re, parser);
			reasonRules(re,parser);

			cout << "************" << endl
				 << endl
				 << endl;


			sleep(3);
		}
		delete re;
	}
	if (argc == 2)
	{

		// ifstream fin(argv[1]);
		// if(!fin)
		// {
		//     printf("no file data!\n");
		//     exit(1);
		// }

		//else
		//{
		//cout<<"现在从该文档中读入数据"<<endl;
		//sleep(1);

		// int curIndex = 0;
		// double value = 0;
		// bool mflag = false;
		// bool dflag = false;
		// bool rflag = false;

		// sqlite3* db = NULL;
		// const string tName = "vibration";
		// int rc;
		// rc = sqlite3_open("test.db",&db);
		// if(rc)
		// {
		// 	fprintf(stderr,"Can't open database:%s\n",sqlite3_errmsg(db));
		// 	sqlite3_close(db);
		// 	exit(1);
		// }
		// else
		// 	printf("open database successfully.\n");

		int timeseries[] = {5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130};
		auto timesize = sizeof(timeseries)/sizeof(int);
		double timescale = 0;
		double samplingFreq = 0.01;
		bool flag = false;
		double value = 0;

		reason *re = new reason();
		re->InitReasonNetwork();
		initReasonwork2(re, parser);
		srand((unsigned)time(NULL));


		/* ************************
		* Scheme without optimize *
		************************ */
/*
		auto start = chrono::high_resolution_clock::now();

		window* windows[timesize];
		double tmpscale = 0;
		for(int i = 0;i < timesize;i++){
			timescale = timeseries[i] - tmpscale;
			tmpscale = timeseries[i];
			windows[i] = new window(samplingFreq,timescale);
		}

		for(int k=0;k<1;k++)
		{
			deque<double>* bigwindow[timesize];
			int index = 0;
			while(1)
			{
				if(index == timesize)
				{
					break;
				}
				value = genRandData(0.7,1.5);
				if(!flag){
					flag = windows[index]->fillWindow(value);
				}else{
					bigwindow[index] = combineWindows(windows,index);
					flag = false;
					index++;
				}
			}

			PARALIST *pl = re->GetParaList();

			updateParas1(pl,bigwindow);
			for(int y=0;y<timesize;y++)
			{
				delete bigwindow[y];
			}
			reasonRules(re,parser);
		}

		for(int i=0;i<timesize;i++){
			delete windows[i];
		}


		auto finish = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed = finish - start;
		cout<<"elapsed time: "<<elapsed.count()<<" s"<<endl;
*/

		/* *********************
		* Scheme with optimize *
		********************* */

		auto start = chrono::high_resolution_clock::now();

		window* windowslice;
		deque<double>* tmpdq;

		double buffer[26] = {0};
		size_t buffersize = sizeof(buffer)/sizeof(double);
		double maxbuffer[26] = {0};
		double minbuffer[26] = {0};
		//double meanbuffer[26] = {0};
		//double varbuffer[26] = {0};
		double maxindex[13] = {0,2,4,6,8,10,12,14,16,18,20,22,24};
		double minindex[13] = {1,3,5,7,9,11,13,15,17,19,21,23,25};
		//double meanindex[8] = {2,5,8,11,14,17,20,23};
		//double varindex[10] = {3,7,11,15,19,23,27,31,35,39};

	 	for(int k=0;k<1;k++)
		{   
			int index = 0;
			double tmpscale = 0;
			timescale = timeseries[0] - tmpscale;
			tmpscale = timeseries[0];
			windowslice = new window(samplingFreq,timescale);
			while(1)
			{
				value = genRandData(0.7,1.5);
				if(!flag){
					flag = windowslice->fillWindow(value);
				}else{
					maxbuffer[index] = GetMax(windowslice->getData());
					minbuffer[index] = GetMin(windowslice->getData());
					//meanbuffer[index] = GetMean(windowslice->getData());
					//varbuffer[index] = GetVar(windowslice->getData());
					flag = false;
					index++;
					delete windowslice;
					if(index == timesize)
					{
						break;
					}
					timescale = timeseries[index]-tmpscale;
					tmpscale = timeseries[index];
					windowslice = new window(samplingFreq,timescale);
				}
			}
			
			//makebuffer4(buffer,maxindex,maxbuffer,minindex,minbuffer,meanindex,meanbuffer,varindex,varbuffer,11,11,10,10);
			//makebuffer3(buffer,maxindex,maxbuffer,minindex,minbuffer,meanindex,meanbuffer,9,9,8);
			makebuffer(buffer,maxindex,maxbuffer,minindex,minbuffer,13,13);
			//makebuffer1(buffer,minindex,minbuffer,10);

			PARALIST *pl = re->GetParaList();

			updateParas2(pl,buffer);

			reasonRules(re,parser);

		}
		auto finish = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed = finish - start;
		cout<<"elapsed time: "<<elapsed.count()<<" s"<<endl;


        /* track memory usage. */
		int tSize = 0, resident = 0, share = 0;
    	ifstream fbuffer("/proc/self/statm");
    	fbuffer >> tSize >> resident >> share;
    	fbuffer.close();

    	long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // in case x86-64 is configured to use 2MB pages
    	double rss = resident * page_size_kb;
    	cout << "RSS - " << rss << " kB\n";

    	double shared_mem = share * page_size_kb;
    	cout << "Shared Memory - " << shared_mem << " kB\n";

    	cout << "Private Memory - " << rss - shared_mem << "kB\n";


		// oriAllocator *oa = new oriAllocator(0.01,1);
		// optimize *opt = new optimize();
		// opt->setOpTable(re);
		// reshapeRulePara(re, parser, opt);
		// opt->testOp();

		// cout<<"------------after reshape------------"<<endl;
		// re->testPara();
		// re->testRule();

		// PARALIST *pl = re->GetParaList();
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

		// while (1)
		// {
		// 	value = genRandData(0.8,1.5);
		// 	cout << "value: " << value << endl;
		// 	if (mflag)
		// 	{
		// 		// for(int index = 0;index < oa->GetInferRound();index++){
		// 		// 	updatePara(oa,pl,curIndex);
		// 		// 	reasonRules(re,parser);
		// 		// 	if(index == oa->GetInferRound()-1)
		// 		// 		rflag = true;
		// 		// }
		// 		if (curIndex == oa->GetInferRound())
		// 		{
		// 			curIndex = 0;
		// 			rflag = true;
		// 		}
		// 		if (curIndex < oa->GetInferRound())
		// 		{
		// 			updatePara(oa, pl, curIndex);
		// 			cout << "reason Rule: " << curIndex << endl;
		// 			reasonRules(re, parser);
		// 			curIndex++;
		// 		}
		// 		if (dflag && rflag)
		// 		{
		// 			cout << "loadFromDisk1" << endl;
		// 			oa->loadFromDisk();
		// 			cout << "loadFromDisk2" << endl;
		// 			dflag = false;
		// 			rflag = false;
		// 		}
		// 		// else{
		// 		// 	cout<<"appendfile1"<<endl;
		// 		// 	dflag = oa->appendFile(value);
		// 		// 	cout<<"appendfile2"<<endl;
		// 		// }
		// 	}
		// 	else
		// 	{
		// 		mflag = oa->genMemData(value);
		// 	}
		// }
		// while(1)
		// {
		// 	value = genRandData(0.7,1.5);
		// 	mflag = oa->genMemData(value);
		// 	if(mflag)
		// 		break;
		// }
		// //reasonOnce(re,parser,oa,pl);
//		auto start1 = chrono::high_resolution_clock::now();
		// for(int i=0;i<oa->GetRoundLength()*oa->GetInferRound()*100;i++){
		// 	//thread treason(reasonOnce,opt,re,parser,oa,pl);
		// 	//updateData(oa);
		// 	/*
		// 	{
		// 		unique_lock <mutex> lck(mtx);
		// 		cv.wait(lck, [] { return processed; });
		// 	}
		// 	*/
		// 	//treason.join();
		// 	value = genRandData(0.7,1.5);

		// 	if(ready)
		// 		//reasonOnce(re,parser,oa,pl);
		// 		//reasonOnceOPT(opt,re,parser,oa,pl);
		// 		//reasonOnceOPTSQL(opt,re,parser,oa,pl,db,tName);
		// 		reasonOnceSQL(re,parser,oa,pl,db,tName);
		// 	else
		// 	{
		// 		//thread tupdateData(updateData,value,oa);
		// 		thread tupdateData(updateDataSQL,to_string(value),oa,db,tName);
		// 		//cout<<"start updateDataSQL()"<<endl;
		// 		//updateDataSQL(to_string(value),oa,db,tName);
		// 		tupdateData.join();				
		// 	}
		// }
//		oriAllocator *oa1 = new oriAllocator(100,1);
//		for(int i=0;i<oa1->GetRoundLength()*1000;i++)
//		{
//			value = genRandData(0.7,1.5);
//			mflag = oa1->genMemData(value);
//			//cout<<"value: "<<value<<endl;
//			//cout<<"test1, count i: "<<i<<endl;
//			if(mflag)
//			{
//				//oa1->testMemData();
//				reasonRulesList(opt,re,parser,oa1,pl);
//				mflag = false;
//			}
//		}
//		auto finish1 = chrono::high_resolution_clock::now();
//		chrono::duration<double> elapsed1 = finish1 - start1;

		// auto start2 = chrono::high_resolution_clock::now();
		// oriAllocator *oa2 = new oriAllocator(1000,10);
		// for(int i=0;i<oa2->GetRoundLength()*1000;i++)
		// {
		// 	value = genRandData(0.7,1.5);
		// 	mflag = oa2->genMemData(value);
		// 	//cout<<"value: "<<value<<endl;
		// 	//cout<<"test2, count i: "<<i<<endl;
		// 	if(mflag)
		// 	{
		// 		//oa2->testMemData();
		// 		reasonRulesList(re,parser,oa2,pl);
		// 		mflag = false;
		// 	}
		// }
		// auto finish2 = chrono::high_resolution_clock::now();
		// chrono::duration<double> elapsed2 = finish2 - start2;

		// auto start3 = chrono::high_resolution_clock::now();
		// oriAllocator *oa3 = new oriAllocator(1000,100);
		// for(int i=0;i<oa3->GetRoundLength()*1000;i++)
		// {
		// 	value = genRandData(0.7,1.5);
		// 	mflag = oa3->genMemData(value);
		// 	//cout<<"value: "<<value<<endl;
		// 	//cout<<"test2, count i: "<<i<<endl;
		// 	if(mflag)
		// 	{
		// 		//oa2->testMemData();
		// 		reasonRulesList(re,parser,oa3,pl);
		// 		mflag = false;
		// 	}
		// }
		// auto finish3 = chrono::high_resolution_clock::now();
		// chrono::duration<double> elapsed3 = finish3 - start3;
		// cout<<"when InferRound = 1, elapsed time: "<<elapsed1.count()<<" s"<<endl;
		// cout<<"when InferRound = 10, elapsed time: "<<elapsed2.count()<<" s"<<endl;
		// cout<<"when InferRound = 100, elapsed time: "<<elapsed3.count()<<" s"<<endl;

		// while(1)
		// {
		// 	value = lo + static_cast<double>(rand())/(static_cast<double>(RAND_MAX/(hi-lo)));
		// 	cout<<"value: "<<value<<endl;
		// 	if(mflag){
		// 		break;
		// 	}else{
		// 			mflag = oa->genMemData(value);
		// 		}
		// }
		// for(int i = 0;i<oa->GetMemData()->size();i++){
		// 	updatePara(oa,pl,curIndex);
		// 	//reasonRules(re,parser);
		// 	testReason(re,parser);
		// 	sleep(3);
		// }

		delete re;
		//delete oa1;
		// delete oa2;
		// delete oa3;
		//delete opt;
		//sqlite3_close(db);
		//}
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