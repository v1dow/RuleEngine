#ifndef SLIDINGWINDOW_H
#define SLIDINGWINDOW_H

#include "basicWindow.h"



class basicWindow;

class slidingWindow
{
	int BWSize;
	basicWindow* head;
	int capacity;
	int length;

public:
	slidingWindow(int BWSize);
	slidingWindow(int BWSize,int capacity);
	~slidingWindow();

	int Length();
	basicWindow* Find(int pos) const;
	void insert(basicWindow* window, int pos);
	void insertBack(basicWindow* window);
	void insertFront(basicWindow* window);
	void remove(int pos);
	void popFront();
	void popBack();

	//void init();
	bool isFull();
	basicWindow* GetHead();
	map<string, double>* GetDigest(set<string>* SS, int start, int end);
	//deque<double>* GetData();
	void updateData(double value);
	void testDigest(map<string, double>* m);
};

#endif
