#include "ruleNetwork.h"


ruleNetwork::ruleNetwork()
{
	RuleTrees = new RULETREES();
}

ruleNetwork::~ruleNetwork()
{
	delete RuleTrees;
}

//void ruleNetwork::Init()
//{
//
//}

void ruleNetwork::trim(string& str)
{
	if (!str.empty())
	{
		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);
	}
}

bool ruleNetwork::isEqual(ruleTree* rt1, ruleTree* rt2)
{
	vector<TNode*>* chidr1 = rt1->GetChildren();
	vector<TNode*>* chidr2 = rt2->GetChildren();
	vector<TNode*>::iterator it1;
	vector<TNode*>::iterator it2;
	it1 = chidr1->begin();
	it2 = chidr2->begin();
	while (it1 != chidr1->end() && it2 != chidr2->end() && (*it1)->element == (*it2)->element)
	{
		if ((*it1)->element != (*it2)->element)
			return false;
		++it1;
		++it2;
	}
	return true;
}

bool ruleNetwork::isExist(ruleTree* rt)
{
	for (auto rtit = RuleTrees->begin(); rtit != RuleTrees->end(); rtit++)
	{
		if (isEqual(rt, *rtit))
		{
			return true;
		}
	}
	return false;
}

RULETREES* ruleNetwork::GetRuleTrees()
{
	return this->RuleTrees;
}

void ruleNetwork::genTrees(reason* re)
{
	ruleTree* rt;
	vector<string>* acs;
	RULELIST* rList = re->GetRuleList();
	string ant;
	string con;

	string AC;
	size_t found = 0;
	int idx = 0;

	for (auto rit = rList->begin(); rit != rList->end(); rit++)
	{
		ant = (*rit)->GetAntecedent();
		con = (*rit)->GetConsequent();
		rt = new ruleTree(con);
		acs = new vector<string>();
		while (1)
		{
			if (ant.find("AND") != string::npos)
			{
				idx = 0;
				found = ant.find("AND");
				AC = ant.substr(idx, found - idx);
				trim(AC);
				acs->push_back(AC);
				ant.erase(0, found + 3);
			}
			else {
				idx = 0;
				found = ant.length() - 1;
				AC = ant;
				trim(AC);
				acs->push_back(AC);
				break;
			}
		}
		if (!isExist(rt))
		{
			rt->SetChildren(con, acs);
			//delete acs;
			RuleTrees->push_back(rt);
		}
		else {
			delete acs;
			delete rt;
		}
	}
}

