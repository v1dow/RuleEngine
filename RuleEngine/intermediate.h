#ifndef INTERMEDIATE_H
#define INTERMEDIATE_H

#include <string>

using namespace std;

class intermediate
{
	string intermediateString;
	double intermediateValue;
	
public:
	intermediate();
	intermediate(const string name);
	~intermediate();

	void SetString(string name);
	string GetString();
	void SetValue(double value);
	double GetValue();
};


#endif
