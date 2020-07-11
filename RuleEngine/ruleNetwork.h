#ifndef RULENETWORK_H
#define RULENETWORK_H

//#include "preprocessing.h"
#include "ruleTree.h"
#include "reason.h"

#include <string>

using namespace std;

class ruleTree;

typedef vector<ruleTree*> RULETREES;

class ruleNetwork
{

	RULETREES* RuleTrees;
public:
	ruleNetwork();
	~ruleNetwork();
	//void Init();
	void trim(string& str);
	RULETREES* GetRuleTrees();
	void genTrees(reason* re);
	bool isEqual(ruleTree* rt1, ruleTree* rt2);
	bool isExist(ruleTree* rt);
};

#endif // !RULENETWORK_H
