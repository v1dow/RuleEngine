#include "statistical.h"

statistical::statistical()
{
	statName = "INIT";
	isIncremental = false;
	reference = "NULL";
}

statistical::statistical(string statName)
{
	this->statName = statName;
	if (strcmp(statName.c_str(), "MAX")==0)
	{
		isIncremental = true;
		reference = "NULL";
	}
	if (strcmp(statName.c_str(), "MIN") == 0)
	{
		isIncremental = true;
		reference = "NULL";
	}
	if (strcmp(statName.c_str(), "AVG") == 0)
	{
		isIncremental = true;
		reference = "NULL";
	}
	if (strcmp(statName.c_str(), "VAR") == 0)
	{
		isIncremental = true;
		reference = "AVG";
	}
	if (strcmp(statName.c_str(), "STD") == 0)
	{
		isIncremental = true;
		reference = "VAR";
	}
}

statistical::~statistical()
{

}

bool statistical::GetIsIncremental()
{
	return this->isIncremental;
}

string statistical::GetReference()
{
	return this->reference;
}

string statistical::GetStatName()
{
	return this->statName;
}