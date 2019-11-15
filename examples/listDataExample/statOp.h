#ifndef STATOP_H
#define STATOP_H

#include <vector>
#include <list>
#include "intermediate.h"


using namespace std;

class intermediate;
class statOp;

typedef list<intermediate*> MIDLIST;
typedef list<statOp*> OPLIST;

class statOp
{
	string opName;
	int length;
	MIDLIST* mList;

public:
	statOp();
	statOp(const string opName);
	~statOp();
	void SetName(string name);
	string GetName();
	void SetMidList(MIDLIST* list);
	MIDLIST* GetMidList();
	int GetLength();
	intermediate* CreateMid(const string opname, const string intername, const int index);
};

#endif
