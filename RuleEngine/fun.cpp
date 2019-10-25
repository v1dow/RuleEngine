#include "fun.h"

#include <sstream>
#include <fstream>

#define RAND_M 32767


using namespace calc;

//change
extern calc::calc_parser *parser;
reason *re;

extern "C"
{
extern int yylex(void);
extern void yyerror(const char *);
extern void scan_string(const char* str);
extern void delete_buffer();
}

void UpdatePara(double t, ifstream& fin, PARALIST* pl)
{
	string pstring;
	string value;
	double dvalue = 0;
	LISTDOUBLE* lv;
	PARALIST::iterator pit;
	for(pit = pl->begin();pit != pl->end();pit++)
	{
		for(double d = 0;d < t;d++)
		{
			fin>>dvalue;
			lv->push_back(dvalue);
		}
		(*pit)->SetListValue(lv);
		value = ConverListToString(lv);
        pstring = (*pit)->GetName() + "=" + value+"\n";
        scan_string(pstring.c_str());
        cout<<"The info of para is : "<< pstring<<endl;
        yyparse(); 
	}
}

string ConvertToString(double value) 
{
	stringstream ss;
	ss << value;
	return ss.str();
}

string ConverListToString(LISTDOUBLE lb)
{
	string s = "[";
    for(auto it = lb.begin();it != lb.end();it++)
    {
        double d;
        d = *it;
        s += to_string(d);
        if(it != lb.end()-1)
            s += ",";
    }
    s += "]";
    return s;
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
	LISTDOUBLE* lvalue;
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
	for(pit = pl->begin();pit!=pl->end();pit++)
	{                                                                                                                                                                               
		lvalue = new deque<double>();
		value = ConverListToString(lvalue);
		pstring = (*pit)->GetName() + "=" + value+"\n";
		scan_string(pstring.c_str());
		yyparse();
	}

	for(tit = tl->begin();tit!=tl->end();tit++)
	{
		tstring = (*tit)->GetTokenName() + "=" + (*tit)->GetTokenContent()+"\n";
		scan_string(tstring.c_str());
		yyparse();
	}
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

void initReason()
{
    parser= new calc::calc_parser();
    if (parser->create(0)!=1) {
        printf("Create calc_parser failed!\n");
    }
    re = new reason();
    re->InitReasonNetwork();
    initReasonwork(re,parser);
}

void endReason()
{
    delete re;
    delete parser;
}