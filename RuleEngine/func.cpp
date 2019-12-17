#include "func.h"

extern calc::calc_parser *parser;
reason *re;



extern "C"
{
extern int yylex(void);
extern void yyerror(const char *);
extern void scan_string(const char* str);
extern void delete_buffer();
}

string ConvertToString(double value)
{
	stringstream ss;
	ss << value;
	return ss.str();
}

string ConvertListToString(LISTDOUBLE *lb)
{
	string s = "[";
	for (auto it = lb->begin(); it != lb->end(); it++)
	{
		double d;
		d = *it;
		s += to_string(d);
		if (it != lb->end() - 1)
			s += ",";
	}
	s += "]";
	return s;
}

double genRandData(double low, double high)
{
	double value = 0;
	value = low + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (high - low)));
	return value;
}

void updateData(double value, oriAllocator* oa)
{
	//unique_lock <mutex> lck(mtx);
	bool fflag = false;
	fflag = oa->appendFile(value);
	if(fflag)
	{
		//oa->loadFromDisk();
		ready = true;
		//fileReady = true;
		//lck.unlock();
		//cv.notify_one();
	}
}

void updateDataSQL(const string& value, oriAllocator* oa, sqlite3* db, const string& tName)
{
	//unique_lock <mutex> lck(mtx);
	bool fflag = false;
	//fflag = oa->appendFile(value);
	fflag = oa->appendSQL(db,tName,value);
	if(fflag)
	{
		//oa->loadFromDisk();
		ready = true;
		//fileReady = true;
		//lck.unlock();
		//cv.notify_one();
	}
}

void updateParaOPT(optimize* opt, oriAllocator *oa, PARALIST *pl, int index)
{
	string pstring;
	string value;
	string oldstring;
	LISTDOUBLE *lv;
	PARALIST::iterator pit;
	OPLIST* opList = opt->GetOpList();

	/* original para assign */
	for (pit = pl->begin(); pit != pl->end(); pit++)
	{
		for(auto opit = opList->begin();opit != opList->end();opit++)
		{
			MIDLIST* mList = (*opit)->GetMidList();
			for(auto mit = mList->begin();mit!=mList->end();mit++)
			{
				if((*pit)->GetName() != (*mit)->GetNewStr())
				{
					lv = oa->GetMemData()->at(index);
					(*pit)->SetListValue(lv);
					value = ConvertListToString(lv);
					pstring = (*pit)->GetName() + "=" + value + "\n";
					scan_string(pstring.c_str());
					//cout << "The info of original para is : " << pstring << endl;
					yyparse();
				}
			}
		}
	}

	/* intermediate para value set */
	for (pit = pl->begin(); pit != pl->end(); pit++)
	{
		for(auto opit = opList->begin();opit != opList->end();opit++)
		{
			MIDLIST* mList = (*opit)->GetMidList();
			for(auto mit = mList->begin();mit!=mList->end();mit++)
			{
				if((*pit)->GetName() == (*mit)->GetNewStr())
				{
					oldstring = (*mit)->GetOldStr() + "\n";
					scan_string(oldstring.c_str());
					//cout << "The info of intermediate para is : " << (*mit)->GetOldStr() << endl;
					yyparse();
					//cout<< "intermediate result: "<<parser->GetResult()<<endl;
					(*pit)->SetValue(parser->GetResult());
				}
			}
		}
	}

	/* intermediate para assign */
	for (pit = pl->begin(); pit != pl->end(); pit++)
	{
		for(auto opit = opList->begin();opit != opList->end();opit++)
		{
			MIDLIST* mList = (*opit)->GetMidList();
			for(auto mit = mList->begin();mit!=mList->end();mit++)
			{
				if((*pit)->GetName() == (*mit)->GetNewStr())
				{
					value = ConvertToString((*pit)->GetValue());
					pstring = (*mit)->GetNewStr() + "=" + value + "\n";
					scan_string(pstring.c_str());
					//cout << "The info of original para is : " << pstring << endl;
					yyparse();
				}
			}
		}
	}
	
}
void updatePara(oriAllocator* oa, PARALIST* pl, int index)
{
	string pstring;
	string value;
	double dvalue = 0;
	LISTDOUBLE* lv;
	PARALIST::iterator pit;
	for(pit = pl->begin();pit != pl->end();pit++)
	{
		lv = oa->GetMemData()->at(index);
		// for(double d = 0;d < oa->roundLength;d++)
		// {
		// 	fin>>dvalue;
		// 	lv->push_back(dvalue);
		// }
		(*pit)->SetListValue(lv);
		value = ConvertListToString(lv);
        pstring = (*pit)->GetName() + "=" + value+"\n";
        scan_string(pstring.c_str());
        //cout<<"The info of para is : "<< pstring<<endl;
        yyparse();
	}
}
void updatePara1(PARALIST *pl, double dvalue)
{
	string pstring;
	string value;
	PARALIST::iterator pit;
	for (pit = pl->begin(); pit != pl->end(); pit++)
	{
		(*pit)->SetValue(dvalue);
		value = ConvertToString(dvalue);
		pstring = (*pit)->GetName() + "=" + value + "\n";
		scan_string(pstring.c_str());
		//cout << "The info of para is : " << pstring << endl;
		yyparse();
	}
}

void initReasonwork(reason *re, calc::calc_parser *parser)
{
	PARALIST *pl = re->GetParaList();
	TOKENLIST *tl = re->GetTokenList();
	PARALIST::iterator pit;
	TOKENLIST::iterator tit;
	string value;
	string pstring;

	string tstring;
	double dvalue = 0;
	LISTDOUBLE *lvalue = new deque<double>();
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
	for (pit = pl->begin(); pit != pl->end(); pit++)
	{
		value = ConvertListToString(lvalue);
		pstring = (*pit)->GetName() + "=" + value + "\n";
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

void reshapeRulePara(reason *re, calc::calc_parser *parser, optimize* opt)
{
	OPLIST* opList = opt->GetOpList();
	RULELIST* rList = re->GetRuleList();

	string replacedPara;
	string rulestring;
	string oldstring;
	string newstring;
	string newrulestring;
	size_t ifind;

	/* ********************************
	* add new paras for specific ops. *
	******************************** */  
	for(auto opit = opList->begin();opit != opList->end();opit++)
	{
		MIDLIST* mList = (*opit)->GetMidList();
		for(auto mit = mList->begin();mit!=mList->end();mit++)
		{
			replacedPara = (*mit)->GetNewStr();
			re->CreateParas(replacedPara,"NULL");
		}
	}

	/* ***************
	* reshape rules. *
	**************** */ 
	for(auto rit = rList->begin();rit != rList->end();rit++)
	{
		rulestring = (*rit)->GetAntecedent();
		for(auto opit = opList->begin();opit != opList->end();opit++)
		{
			MIDLIST* mList = (*opit)->GetMidList();
			for(auto mit = mList->begin();mit!=mList->end();mit++)
			{
				oldstring = (*mit)->GetOldStr();
				newstring = (*mit)->GetNewStr();

				ifind = rulestring.find(oldstring);
				while(ifind>0 && ifind != string::npos)
    			{
        			newrulestring = rulestring.replace(ifind,oldstring.length(),newstring);
        			ifind = rulestring.find(oldstring,ifind + 1);
    			}
				if(!newrulestring.empty())
					(*rit)->SetAntecedent(newrulestring);
			}
		}
	}
}

void dataProduce(reason *re)
{
	PARALIST *pl = re->GetParaList();
	PARALIST::iterator pit;
	string value;
	double dvalue = 0;
	string pstring;
	for (pit = pl->begin(); pit != pl->end(); pit++)
	{
		dvalue = (int)(((rand() % RAND_M + 1) * 1.0 / (RAND_M + 1) * 100.0) * 100.0) / 100.0;
		value = ConvertToString(dvalue);
		pstring = (*pit)->GetName() + "=" + value + "\n";
		scan_string(pstring.c_str());
		//                cout<<"The info of para is : "<< pstring<<endl;
		yyparse();
	}
}

//change
void changeParaValue(reason *re, rule *tmpRule)
{
	double value;

	string conStr = tmpRule->GetConsequent();
	int index = conStr.find('=');

	string name = conStr.substr(0, index);
	string sValue = conStr.substr(index + 1);
	value = atof(sValue.c_str());

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
	for (pit = pl->begin(); pit != pl->end(); pit++)
	{

		if ((*pit)->GetName() == name)
		{
			(*pit)->SetValue(value);
			cout << "(改变的参数:" << (*pit)->GetName() << ":" << (*pit)->GetValue() << ")" << endl;
		}
	}
}
//change

void testReason(reason *re, calc::calc_parser *parser)
{
	RULELIST *rlist = re->GetRuleList();
	RULELIST::iterator rit;

	string rstring;

	for (rit = rlist->begin(); rit != rlist->end(); rit++)
	{
		rstring = (*rit)->GetAntecedent() + "\n";
		cout << "rstring: " << rstring << endl;
		scan_string(rstring.c_str());
		yyparse();
		cout << "parser result: " << parser->GetResult() << endl;
	}
}

void reasonRules(reason *re, calc::calc_parser *parser)
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

	for (rit = rlist->begin(); rit != rlist->end(); rit++)
	{
		rstring = (*rit)->GetAntecedent() + "\n";
		cout << "rstring: " << rstring << endl;
		scan_string(rstring.c_str());
		cout << "scan success" << endl;
		yyparse();
		cout << "parser success" << endl;
		if (parser->GetResult() == 1)
		{
			cout << "Trigger rule: " << (*rit)->GetRuleName() << "---" << (*rit)->GetAntecedent() << " THEN " << (*rit)->GetConsequent() << endl;
		}
	}
	cout << "reasonRule complete." << endl;
}

void reasonOnce(reason *re, calc::calc_parser *parser, oriAllocator *oa, PARALIST *pl)
{
	//unique_lock <mutex> lck(mtx);
	//cv.wait(lck, [] { return ready; });
	
	oa->loadFromDisk();
	
	//fileReady = false;
	ready = false;
	for (int i = 0; i < oa->GetInferRound(); i++)
	{
		updatePara(oa, pl, i);

		RULELIST *rlist = re->GetRuleList();
		RULELIST::iterator rit;
		string rstring;
		for (rit = rlist->begin(); rit != rlist->end(); rit++)
		{
			rstring = (*rit)->GetAntecedent() + "\n";
			//cout << "rstring: " << rstring << endl;
			scan_string(rstring.c_str());
			yyparse();
			if (parser->GetResult() == 1)
			{
				cout << "Trigger rule: " << (*rit)->GetRuleName() << "---" << (*rit)->GetAntecedent() << " THEN " << (*rit)->GetConsequent() << endl;
			}
		}
	}
	//processed = true;
	//lck.unlock();
	//cv.notify_one();
}

void reasonOnceOPT(optimize* opt, reason *re, calc::calc_parser *parser, oriAllocator *oa, PARALIST *pl)
{
	//unique_lock <mutex> lck(mtx);
	//cv.wait(lck, [] { return ready; });
	
	oa->loadFromDisk();
	
	//fileReady = false;
	ready = false;
	for (int i = 0; i < oa->GetInferRound(); i++)
	{
		updateParaOPT(opt, oa, pl, i);

		RULELIST *rlist = re->GetRuleList();
		RULELIST::iterator rit;
		string rstring;
		for (rit = rlist->begin(); rit != rlist->end(); rit++)
		{
			rstring = (*rit)->GetAntecedent() + "\n";
			//cout << "rstring: " << rstring << endl;
			scan_string(rstring.c_str());
			yyparse();
			if (parser->GetResult() == 1)
			{
				cout << "Trigger rule: " << (*rit)->GetRuleName() << "---" << (*rit)->GetAntecedent() << " THEN " << (*rit)->GetConsequent() << endl;
			}
		}
	}
	//processed = true;
	//lck.unlock();
	//cv.notify_one();
}

void reasonOnceSQL(reason *re, calc::calc_parser *parser, oriAllocator *oa, PARALIST *pl, sqlite3* db, const string& tName)
{
	//unique_lock <mutex> lck(mtx);
	//cv.wait(lck, [] { return ready; });
	
	//oa->loadFromDisk();
	oa->loadFromSQL(db,tName);
	
	//fileReady = false;
	ready = false;
	for (int i = 0; i < oa->GetInferRound(); i++)
	{
		updatePara(oa, pl, i);

		RULELIST *rlist = re->GetRuleList();
		RULELIST::iterator rit;
		string rstring;
		for (rit = rlist->begin(); rit != rlist->end(); rit++)
		{
			rstring = (*rit)->GetAntecedent() + "\n";
			//cout << "rstring: " << rstring << endl;
			scan_string(rstring.c_str());
			yyparse();
			if (parser->GetResult() == 1)
			{
				cout << "Trigger rule: " << (*rit)->GetRuleName() << "---" << (*rit)->GetAntecedent() << " THEN " << (*rit)->GetConsequent() << endl;
			}
		}
	}
	//processed = true;
	//lck.unlock();
	//cv.notify_one();
}
void reasonOnceOPTSQL(optimize* opt, reason *re, calc::calc_parser *parser, oriAllocator *oa, PARALIST *pl, sqlite3* db, const string& tName)
{
	//unique_lock <mutex> lck(mtx);
	//cv.wait(lck, [] { return ready; });
	
	//oa->loadFromDisk();
	oa->loadFromSQL(db,tName);
	
	//fileReady = false;
	ready = false;
	for (int i = 0; i < oa->GetInferRound(); i++)
	{
		updateParaOPT(opt, oa, pl, i);

		RULELIST *rlist = re->GetRuleList();
		RULELIST::iterator rit;
		string rstring;
		for (rit = rlist->begin(); rit != rlist->end(); rit++)
		{
			rstring = (*rit)->GetAntecedent() + "\n";
			//cout << "rstring: " << rstring << endl;
			scan_string(rstring.c_str());
			yyparse();
			if (parser->GetResult() == 1)
			{
				cout << "Trigger rule: " << (*rit)->GetRuleName() << "---" << (*rit)->GetAntecedent() << " THEN " << (*rit)->GetConsequent() << endl;
			}
		}
	}
	//processed = true;
	//lck.unlock();
	//cv.notify_one();
}

void reasonIndeRules(reason *re, calc::calc_parser *parser)
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

	for (tit = tl->begin(); tit != tl->end(); tit++)
	{
		tstring = (*tit)->GetTokenName() + "=" + (*tit)->GetTokenContent() + "\n";
		scan_string(tstring.c_str());
		yyparse();
	}

	for (rit = inderlist->begin(); rit != inderlist->end(); rit++)
	{
		rstring = (*rit)->GetReplacedRule() + "\n";
		scan_string(rstring.c_str());
		yyparse();
		if (parser->GetResult() == 1)
		{
			//cout<<"Trigger indepedent rule: "<<(*rit)->GetRuleName()<<"---"<<(*rit)->GetAntecedent()<<endl;
			cout << "触发独立规则: " << (*rit)->GetRuleName() << "---" << (*rit)->GetAntecedent() << " THEN " << (*rit)->GetConsequent() << endl;

			//change
			//rule *tmpRule=*rit;
			changeParaValue(re, *rit);
			//change
		}
	}
}

void reasonNestedRules(reason *re, calc::calc_parser *parser)
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

	for (tit = tl->begin(); tit != tl->end(); tit++)
	{
		tstring = (*tit)->GetTokenName() + "=" + (*tit)->GetTokenContent() + "\n";
		scan_string(tstring.c_str());
		yyparse();
	}

	for (neit = nrlist->begin(); neit != nrlist->end(); neit++)
	{
		for (nrit = (*neit)->begin(); nrit != (*neit)->end(); nrit++)
		{
			ntstring = (*nrit)->GetReplacedRule() + "\n";
			//cout<<ntstring<<endl;
			scan_string(ntstring.c_str());
			yyparse();
			if (parser->GetResult() == 1)
			{
				//cout<<"Trigger nested rule: "<<(*nrit)->GetRuleName()<<"---"<<(*nrit)->GetAntecedent()<<endl;
				cout << "触发嵌套规则: " << (*nrit)->GetRuleName() << "---" << (*nrit)->GetAntecedent() << endl;

				//change
				changeParaValue(re, *nrit);
				//change

				constring = (*nrit)->GetConsequent() + "\n";
				//cout<<constring<<endl;
				//cout<<parser->GetResult()<<endl;
				scan_string(constring.c_str());
				yyparse();
				//cout<<parser->GetResult()<<endl;

				ptmplist = (*nrit)->GetConParaList();
				for (ptmpit = ptmplist->begin(); ptmpit != ptmplist->end(); ptmpit++)
				{

					ttmplist = (*ptmpit)->QuotedTokenList;
					for (ttmpit = ttmplist->begin(); ttmpit != ttmplist->end(); ttmpit++)
					{
						//cout<<"No!!!!"<<endl;
						ptokenstring = (*ttmpit)->GetTokenName() + "=" + (*ttmpit)->GetTokenContent() + "\n";
						scan_string(ptokenstring.c_str());
						yyparse();
					}
				}
				cout << endl;
			}
		}
	}
}
