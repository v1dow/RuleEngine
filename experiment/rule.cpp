#include "rule.h"
rule::rule()
{

   	NestedRule = false;
  	AntParaList = new PARALIST();
   	ConParaList = new PARALIST();
   	//preQuotedList = new TList;
   	//folQuotedList = new TList;

}
rule::~rule()
{
   	delete AntParaList;
	AntParaList = NULL;
   	delete ConParaList;
	ConParaList = NULL;
}
int rule::RCount = 0;
rule::rule(const rule& oldRule)
{
  	AntParaList = new PARALIST();
   	ConParaList = new PARALIST();
  	RuleName = oldRule.RuleName;
   	Antecedent = oldRule.Antecedent;
   	Consequent = oldRule.Consequent;
   	NestedRule = oldRule.NestedRule;
   	//preQuotedList = new TList;
	//folQuotedList = new TList;
   	this->RCount++;
   	this->RID = RCount;
}
rule::rule(const string &rname,const string &Ant,const string &Con)
{
   	AntParaList = new PARALIST;
   	ConParaList = new PARALIST;
   	//preQuotedList = new TList;
   	//folQuotedList = new TList;
	RuleName = rname;
   	Antecedent = Ant;
   	Consequent = Con;
   	NestedRule = false;
   	this->RCount++;
   	this->RID = RCount;
  	// Assign();
}

void rule::Assign()
{
      	//this->RCount++;
      	//RuleName = "R"+ AnsiString(RCount);
}
bool rule::isNestedRule()
{
        return this->NestedRule;
}
void rule::SetReplacedRule(string as)
{
        this->ReplacedRule = as;
}
void rule::setNestedRuleState(bool flag)
{
        this->NestedRule = flag;
}

PARALIST *rule::GetAntParaList()
{
	return AntParaList;
}
PARALIST *rule::GetConParaList()
{
	return ConParaList;
}

void rule::AddAntPara(para *p)
{
       	this->AntParaList->push_back(p);
}
void rule::AddConPara(para *p)
{
       	this->ConParaList->push_back(p);
}
int  rule::GetRuleID()
{
        return this->RID;
}
string rule::GetRuleName()
{
        return this->RuleName;
}
string rule::GetReplacedRule()
{
        return this->ReplacedRule;
}
string rule::GetAntecedent()
{
	return this->Antecedent;
}
string rule::GetConsequent()
{
	return this->Consequent;
}
void rule::SetRuleName(string rn)
{
        this->RuleName = rn;
}

void rule::SetContent(string Ant,string Con)
{
	this->Antecedent = Ant;
	this->Consequent = Con;
}

void rule::SetAntecedent(string s)
{
	this->Antecedent = s;
}
