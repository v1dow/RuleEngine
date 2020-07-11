#include "statisticalUnion.h"

statisticalUnion::statisticalUnion()
{
	CID = -1;
	_statistical = new statistical();
	windowSize = 0;
	streamID = -1;
	period = 0;
	value = 0.0;
	ACList = new list<string>();
}

statisticalUnion::statisticalUnion(const int CID, statistical* _statistical, const int windowSize, const int streamID, const int period, const double value)
{
	this->CID = CID;
	this->_statistical = _statistical;
	this->windowSize = windowSize;
	this->streamID = streamID;
	this->period = period;
	this->value = value;
	ACList = new list<string>();
}

statisticalUnion::~statisticalUnion()
{
	delete _statistical;
	delete ACList;
}

int statisticalUnion::GetCID()
{
	return this->CID;
}

statistical* statisticalUnion::GetStat()
{
	return this->_statistical;
}

int statisticalUnion::GetWindowSize()
{
	return this->windowSize;
}

int statisticalUnion::GetStreamID()
{
	return this->streamID;
}

int statisticalUnion::GetPeriod()
{
	return this->period;
}

double statisticalUnion::GetValue()
{
	return this->value;
}

void statisticalUnion::SetCID(int CID)
{
	this->CID=CID;
}

void statisticalUnion::SetStat(statistical* _statistical)
{
	this->_statistical = _statistical;
}

void statisticalUnion::SetWindowSize(int windowSize)
{
	this->windowSize = windowSize;
}

void statisticalUnion::SetStreamID(int streamID)
{
	this->streamID = streamID;
}

void statisticalUnion::SetPeriod(int period)
{
	this->period = period;
}

void statisticalUnion::SetValue(double value)
{
	this->value = value;
}

bool statisticalUnion::isEqual(statisticalUnion& SU)
{
	if ((strcmp(this->_statistical->GetStatName().c_str(),SU.GetStat()->GetStatName().c_str()) == 0) && 
		this->streamID == SU.GetStreamID() && 
		this->windowSize == SU.GetWindowSize() && 
		this->period == SU.GetPeriod())
		return true;
	return false;
}

void statisticalUnion::trim(string& str)
{
	if (!str.empty())
	{
		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);
	}
}

string statisticalUnion::GetSUStr()
{
	string SUStr = this->_statistical->GetStatName();
	SUStr += "(S" + to_string(streamID) + "," + to_string(windowSize) + ")";
	return SUStr;
}

list<string>* statisticalUnion::GetACList()
{
	return this->ACList;
}

bool statisticalUnion::isInACList(string& AC)
{
	for (auto ACit = ACList->begin(); ACit != ACList->end(); ACit++)
	{
		trim(*ACit);
		trim(AC);
		if (strcmp((ACit)->c_str(), AC.c_str())==0)
			return true;
	}
	return false;
}