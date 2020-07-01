#include "optimize.h"

optimize::optimize()
{
	opList = new OPLIST();
	opTable = new array<int,6>{0,0,0,0,0,0};
	ops = new vector<string>();
	opNum = 0;
}

optimize::~optimize()
{
	delete opList; 
	opList = NULL;
	delete opTable;
	delete ops;
}

int optimize::whichOp(string rule)
{
	size_t found;

	int opFlag = -1;

	string op[6]{"MAX", "MIN", "MEAN", "MEDIAN", "VAR", "STD"};

	for(int i=0;i<6;i++)
	{
		found = rule.find(op[i]);
		if(found != string::npos)
			opFlag = i;
	}
	
	return opFlag;
}

string optimize::medString(string s)
{
    string med;
    const auto start = find(cbegin(s), cend(s), '(');
    const auto finish = find_if(start, cend(s), [count = 0](const char i) mutable {
    if (i == '('){
        count++;
    }
    else if (i == ')'){
        count--;
    }
    return count <= 0; });
    med = string(next(start), finish);
    return med;
}

int optimize::isExist(statOp* op,string medName)
{
	int flag = 1;
	MIDLIST* mList = op->GetMidList();
	MIDLIST::iterator mit;
	string medstring;
	for(mit = mList->begin();mit!=mList->end();mit++)
	{
		medstring = (*mit)->GetString();
		if(medstring.compare(medName) == 0)
		{
			flag = -1;
		}
	}
	return flag;
}

void optimize::setOpTable(reason* re)
{
	int opFlag = -1;

	RULELIST* rList = re->GetRuleList();
	RULELIST::iterator rit;
	
	string rstring;
	string op[6]{"MAX", "MIN", "MEAN", "MEDIAN", "VAR", "STD"};

	for(rit = rList->begin();rit != rList->end();rit++)
	{
		rstring = (*rit)->GetAntecedent();
		opFlag = whichOp(rstring);
		if(opFlag != -1 && this->opTable->at(opFlag) != 1)
			this->opTable->at(opFlag) = 1;
	}
	for(int i=0;i<6;i++)
	{
		if(opTable->at(i) == 1)
		{
			this->opNum++;
			ops->push_back(op[i]);
		}
	}
	for(auto opit = ops->begin();opit != ops->end();opit++)
	{
		CreateOp(re,(*opit));	
	}
}

statOp* optimize::CreateOp(reason* re,const string name)
{
	statOp* op = new statOp(name);
	RULELIST* rList = re->GetRuleList();
	RULELIST::iterator rit;
	string rstring;
	string medstring;
	int index = 0;

	for(rit = rList->begin();rit != rList->end();rit++)
	{
		rstring = (*rit)->GetAntecedent()+" ";
		if(rstring.find("AND")!=string::npos)
    	{
        	size_t found = rstring.find("AND");
        	rstring.erase(found,4);
    	}
    	if(rstring.find("OR")!=string::npos)
    	{
        	size_t found = rstring.find("OR");
        	rstring.erase(found,3);
    	}
    	size_t first = 0;
    	size_t last = 0;

		while(1)
    	{
        	first = rstring.find(name);
        	if(first==string::npos)
            	break;
        	rstring = rstring.substr(first);
        	last = rstring.find_first_of(' ');
        	medstring = rstring.substr(first,last-first);
        	medstring = medString(medstring);
			if(isExist(op,medstring)!=-1)
			{
				op->CreateMid(name,medstring,index);
				index += 1;
			}
        	if(last==rstring.length()-1)
            	break;
        	rstring = rstring.substr(last);

    	}	
		}
	opList->push_back(op);
	return op;
}

void optimize::testOp()
{
	OPLIST::iterator opit = opList->begin();
	
	for(;opit!=opList->end();opit++)
	{
		cout<<(*opit)->GetName()<<": "<<endl;
		MIDLIST* mList = (*opit)->GetMidList();
		MIDLIST::iterator mit;
		for(mit = mList->begin();mit!=mList->end();mit++)
			cout<<(*mit)->GetString()<<":"<<(*mit)->GetValue()<<endl;
	}
}

OPLIST* optimize::GetOpList()
{
	return this->opList;
}
