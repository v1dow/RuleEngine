#include "rule.h"
para::para()
{ 
	value = 0.0;
	lvalue = new deque<double>();
	QuotedRuleList = new RULELIST();
	QuotedTokenList = new TOKENLIST();
}
para::para(const string &name,const string &type)
{
	Name = name;
	Type = type;
	value = 0.0;
	lvalue = new deque<double>();
	QuotedRuleList = new RULELIST();
	QuotedTokenList = new TOKENLIST();
	AssignParaID();
}
para::~para()
{
    delete QuotedRuleList;
	QuotedRuleList= NULL;
	delete QuotedTokenList;
	QuotedTokenList = NULL;
	delete lvalue;
}
int para::Pcount = 0;
void para::AssignParaID()
{
      this->Pcount++;
      this->PID = Pcount;
}

para::para(const para &oldPara)
{
    	Name = oldPara.Name;
    	Type = oldPara.Type;
    	PID = oldPara.PID;
}
string para::GetName()
{
    	return Name;
}
string para::GetType()
{
    	return Type;
}
int  para::GetParaID()
{
     	return PID;
}

RULELIST *para::GetQuotedRuleList()
{
    	return QuotedRuleList;
}
TOKENLIST *para::GetQuotedTokenList()
{
	return QuotedTokenList;
}
void para::AddQuotedRule(rule* rule)
{
    	this->QuotedRuleList->push_back(rule);
}
void para::AddQuotedToken(token *t)
{
	this->QuotedTokenList->push_back(t);
}
void para::SetName(string &name)
{
    	this->Name = name;
}
void para::SetType(string  &type)
{
    	this->Type = type;
}
void para::SetValue(double v)
{
        this->value = v;
}
double para::GetValue()
{
        return this->value;
}
void para::SetListValue(LISTDOUBLE* lv)
{
	delete lvalue;	
	this->lvalue = new deque<double>(*lv);
}
LISTDOUBLE* para::GetListValue()
{
	return this->lvalue;
}
