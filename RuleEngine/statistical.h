#ifndef STAT_H
#define STAT_H

#include <string>

using namespace std;

class statistical
{
	string statName;
	bool isIncremental;
	string reference;

public:
	statistical();
	statistical(string statName);
	~statistical();
	bool GetIsIncremental();
	string GetReference();
	string GetStatName();
};

#endif // !STAT_H
