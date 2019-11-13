#ifndef INTERMEDIATE_H
#define INTERMEDIATE_H

#include <string>

using namespace std;

class intermediate
{
	string intermediateString;
	double intermediateValue;
	string oldStr;
	string newStr;
	
public:
	intermediate();
	intermediate(const string name);
	~intermediate();

	void SetString(string name);
	string GetString();
	void SetValue(double value);
	double GetValue();
	void SetOldStr(string s);
	void setNewStr(string s);
	string GetOldStr();
	string GetNewStr();
};


#endif
