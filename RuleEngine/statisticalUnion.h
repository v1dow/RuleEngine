#ifndef STATISTICALUNION_H
#define STATISTICALUNION_H

#include <string>
#include <list>

#include "statistical.h"

class statistical;

class statisticalUnion
{
	int CID;
	statistical* _statistical;
	int windowSize;
	int streamID;
	int period;
	double value;
	list<string>* ACList;
	
public:
	statisticalUnion();
	statisticalUnion(const int CID,statistical* _statistical,const int windowSize,const int streamID,const int period,const double value);
	~statisticalUnion();

	int GetCID();
	statistical* GetStat();
	int GetWindowSize();
	int GetStreamID();
	int GetPeriod();
	double GetValue();

	void SetCID(int CID);
	void SetStat(statistical* _statistical);
	void SetWindowSize(int windowSize);
	void SetStreamID(int streamID);
	void SetPeriod(int period);
	void SetValue(double value);

	bool isEqual(statisticalUnion& SU);
	void trim(string& str);
	string GetSUStr();
	list<string>* GetACList();
	bool isInACList(string& AC);
};

#endif // !STATISTICALUNION_H
