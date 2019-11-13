#include "intermediate.h"

intermediate::intermediate()
{
	intermediateString = "Defalt String";
	intermediateValue = 0;
	oldStr = "Default OldStr";
	newStr = "Default NewStr";
}

intermediate::intermediate(const string name)
{
	intermediateString = name;
	intermediateValue = 0;
	oldStr = "Default OldStr";
	newStr = "Default NewStr";
}

intermediate::~intermediate()
{

}

void intermediate::SetString(string name)
{
	this->intermediateString = name;
}

string intermediate::GetString()
{
	return this->intermediateString;
}

void intermediate::SetValue(double value)
{
	this->intermediateValue = value;
}

double intermediate::GetValue()
{
	return this->intermediateValue;
}

void intermediate::SetOldStr(string s)
{
	this->oldStr = s;
}
string intermediate::GetOldStr()
{
	return this->oldStr;
}

void intermediate::SetNewStr(string s)
{
	this->newStr = s;
}

string intermediate::GetNewStr()
{
	return this->newStr;
}


