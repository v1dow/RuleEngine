#ifndef LCTCOLUMN_H
#define LCTCOLUMN_H
#include <deque>
#include <map>
#include <string>

using namespace std;

typedef deque<map<string, double>*> COLUMN;

class lctColumn
{
	int attr;
	COLUMN* column;

public:
	lctColumn();
	lctColumn(int attr);
	~lctColumn();
	COLUMN* GetColumn();
	int GetAttr();
};

#endif