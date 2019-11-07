#include "intermediate.h"

intermediate::intermediate()
{
	intermediateString = "Defalt String";
	intermediateValue = 0;
}

intermediate::intermediate(const string name)
{
	intermediateString = name;
	intermediateValue = 0;
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

