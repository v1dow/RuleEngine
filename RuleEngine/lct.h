#ifndef LCT_H
#define LCT_H

#include "preprocessing.h"
#include "slidingWindow.h"
#include "func.h"
//#include "lctColumn.h"

#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <numeric>

class preprocessing;

typedef deque<map<string, double>*> COLUMN;
typedef map<int,COLUMN*> COLUMNS;

class lct
{
	set<int>* TSA;
	set<int>* TSB;
	set<int>* TS;
	vector<int>* ND;
	set<string>* SS;
	int btu;

private:
	void genTSA(SULIST* SUList);
	void genTSB(SULIST* SUList);
	void genTS();
	void genND(SULIST* SUList);
	void genSS(SULIST* SUList);

	void updateSS(preprocessing* prep, int windowSize);
	COLUMN* CreateNDColumn(preprocessing* prep, slidingWindow* SW, int windowSum, int attr);
	COLUMN* CreateTSAColumn(preprocessing* prep, int attr, map<string, double>* base, map<string, double>* incremental);

public:
	COLUMNS* NDColumns;
	COLUMNS* TSAColumns;

public:
	lct();
	~lct();

	void lctInit(preprocessing* prep);
	map<string, double>* CreateEntry(slidingWindow* SW, int start, int end);
	void CreateNDColumns(preprocessing* prep, slidingWindow* SW);
	void updateNDColumns(preprocessing* prep, slidingWindow* SW);
	void CreateTSAColumns(preprocessing* prep);
	map<string, double>* GetDigest(map<string, double>* base, map<string, double>* incremental);
	void updateTSAColumns(preprocessing* prep);
	void updateSUValue(preprocessing* prep);
	int GetBtu();
	set<string>* GetSS();

	void testTSAColumns(preprocessing* prep);
};

#endif // !LCT_H
