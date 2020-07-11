#include "basicWindow.h"
#include "func.h"

basicWindow::basicWindow()
{
	size = 0;
	BWID = -1;
	digest = new map<string, double>();
	rawData = new deque<double>();
	nextWindow = nullptr;
}

basicWindow::basicWindow(int BWID, int size,basicWindow* next)
{
	this->BWID = BWID;
	this->size = size;
	digest = new map<string, double>();
	rawData = new deque<double>();
	nextWindow = next;
}

basicWindow::~basicWindow()
{
	delete digest;
	delete rawData;
}

basicWindow* basicWindow::GetNextWindow()
{
	return this->nextWindow;
}

void basicWindow::SetNextWindow(basicWindow* window)
{
	this->nextWindow = window;
}

// check whether the basicWindow is full
bool basicWindow::isFull()
{
	bool isfull = false;
	if (rawData->size() == this->size)
		isfull = true;
	return isfull;
}

//double basicWindow::updateData(double value)
//{
//	double pop = -1;
//	if (isFull() != -1)
//	{
//		pop = rawData->front();
//		rawData->pop_front();
//	}
//	rawData->push_back(value);
//	return pop;
//}

deque<double>* basicWindow::GetData()
{
	return this->rawData;
}

map<string, double>* basicWindow::GetDigest()
{
	return this->digest;
}

/* update digest of basic window 
   Input: op set %SS% */ 
void basicWindow::updateDigest(set<string>* SS)
{
	double tmp = 0.0;

	for (auto it = SS->begin();it != SS->end();it++)
	{
		tmp = digestGenerator(*it, rawData);
		digest->insert(pair<string, double>(*it, tmp));
	}
}

void basicWindow::testDigest()
{
	string name = "BW[";
	name += to_string(BWID);
	name += "]";
	cout << name << "'s digest:" << endl;
	for (auto it = digest->begin(); it != digest->end(); it++)
	{
		cout << it->first << ": " << it->second << endl;
	}
}

void basicWindow::testData()
{
	string name = "BW[";
	name += to_string(BWID);
	name += "]";
	cout << name << "'s data:" << endl;
	for (auto it = rawData->begin(); it != rawData->end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}