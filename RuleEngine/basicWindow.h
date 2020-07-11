#ifndef BASICWINDOW_H
#define BASICWINDOW_H

#include <map>
#include <string>
#include <deque>
#include <iostream>
#include <set>

using namespace std;

class basicWindow
{
	int size;
	int BWID;
	map<string, double>* digest;
	deque<double>* rawData;
	basicWindow* nextWindow;

public:
	basicWindow();
	~basicWindow();
	basicWindow(int BWID, int size,basicWindow* next = nullptr);

	bool isFull();
	//double updateData(double value);
	void updateDigest(set<string>* SS);
	basicWindow* GetNextWindow();
	deque<double>* GetData();
	map<string, double>* GetDigest();
	void SetNextWindow(basicWindow* window);
	void testDigest();
	void testData();
};

#endif
