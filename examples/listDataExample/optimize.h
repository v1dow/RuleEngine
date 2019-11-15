#ifndef OPTIMIZE_H
#define OPTIMIZE_H

#include <array>
#include <algorithm>
#include "statOp.h"
#include "reason.h"

class optimize
{
	int whichOp(string rule);
	string medString(string s); 
	int isExist(statOp* op,string medName);
public:
	OPLIST* opList;
	array<int,6>* opTable;
	vector<string>* ops;
	int opNum;

	optimize();
	~optimize();
	void setOpTable(reason* re);
	OPLIST* GetOpList();
	statOp* CreateOp(reason* re,const string name);
	int CreateReplacedRule();

	void testOp();
};


#endif
