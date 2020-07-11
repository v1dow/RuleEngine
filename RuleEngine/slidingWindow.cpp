#include "slidingWindow.h"
#include "basicWindow.h"
#include "func.h"

#include <iostream>

// generate one basic window with size %BWSize%
slidingWindow::slidingWindow(int BWSize)
{
	this->BWSize = BWSize;
	capacity = 1;
	length = 1;
	head = new basicWindow(0,BWSize);
}

/* generate %capacity% basic windows with size %BWSize%
   %BWSize%: size of basic windows
   %capacity%: number of basic window
*/
slidingWindow::slidingWindow(int BWSize,int capacity)
{
	this->BWSize = BWSize;
	head = new basicWindow(0,BWSize);
	this->capacity = capacity;
	length = 1;
	
	while (length < capacity)
	{
		
		insertBack(new basicWindow(length,BWSize));
	}
}

slidingWindow::~slidingWindow()
{
	basicWindow* tmpWindow;
	for (int i = 0; i < length; i++)
	{
		tmpWindow = head;
		head = head->GetNextWindow();
		delete tmpWindow;
	}
}

int slidingWindow::Length()
{
	return this->length;
}

// return basic window at %pos%
basicWindow* slidingWindow::Find(int pos) const
{
	if (pos < 0 || pos > length - 1)
	{
		cout << "pos out of range." << endl;
		exit(1);
	}
	basicWindow* target = head;
	int index = 0;
	while (index < pos)
	{
		target = target->GetNextWindow();
		index++;
	}
	return target;
}

// insert %window% at %pos%
void slidingWindow::insert(basicWindow* window, int pos)
{
	if (pos < 0)
	{
		cout << "pos should be greater than 0" << endl;
		return;
	}
	int index = 1;
	basicWindow* tmpWindow = head;
	basicWindow* newWindow = window;

	if (pos == 0)
	{
		newWindow->SetNextWindow(tmpWindow);
		head = newWindow;
		length++;
		return;
	}
	while (tmpWindow != NULL && index < pos)
	{
		tmpWindow = tmpWindow->GetNextWindow();
		index++;
	}
	if (tmpWindow == NULL)
	{
		cout << "insert failed" << endl;
		return;
	}
	newWindow->SetNextWindow(tmpWindow->GetNextWindow());
	tmpWindow->SetNextWindow(newWindow);
	length++;
}

void slidingWindow::insertBack(basicWindow* window)
{
	insert(window, length);
}


void slidingWindow::insertFront(basicWindow* window)
{
	insert(window, 0);
}

// remove basic window at %pos% 
void slidingWindow::remove(int pos)
{
	basicWindow* target, * pre, * tmp;
	if (pos < 0 || pos > length - 1)
	{
		cout << "pos out of range." << endl;
		return;
	}
	if (pos == 0)
	{
		tmp = head;
		head = head->GetNextWindow();
		delete tmp;
	}
	pre = Find(pos - 1);
	target = pre->GetNextWindow();
	pre->SetNextWindow(target->GetNextWindow());
	delete target;
}

void slidingWindow::popFront()
{
	remove(0);
}

void slidingWindow::popBack()
{
	remove(length - 1);
}

bool slidingWindow::isFull()
{
	bool isfull = true;
	basicWindow* curr = head;
	while (curr != NULL)
	{
		if (!curr->isFull())
			return false;
		curr = curr->GetNextWindow();
	}
	return isfull;
}

basicWindow* slidingWindow::GetHead()
{
	return this->head;
}

/* get digest of sub sliding window
   Input: op set %SS%, slidingWindow[%start%,%end%]
   Output: digest of slidingWindow[%start%,%end%] 
   */
map<string, double>* slidingWindow::GetDigest(set<string>* SS, int start, int end)
{
	map<string, double>* digest = new map<string, double>();
	basicWindow* curr;
	basicWindow* endpos = Find(end)->GetNextWindow();
	double tmp = 0.0;
	double BWDigest;
	map<string,double>* tmpDigest;
	deque<double>* tmpDQ;
	
	for (auto SSit = SS->begin();SSit != SS->end();SSit++)
	{
		curr = Find(start);
		while (curr != endpos)
		{
			tmpDigest = curr->GetDigest();
			for (auto it = tmpDigest->begin(); it != tmpDigest->end(); it++)
			{
				if (it->first == (*SSit))
				{
					BWDigest = it->second;
					tmpDQ = new deque<double>();
					tmpDQ->push_back(tmp);
					tmpDQ->push_back(BWDigest);
					tmp = digestGenerator(*SSit, tmpDQ);
					delete tmpDQ;
				}
			}
			curr = curr->GetNextWindow();
		}
		digest->insert(pair<string, double>(*SSit, tmp));
	}

	return digest;
}

//deque<double>* slidingWindow::GetData()
//{
//
//}

/* update data of sliding window
   */
void slidingWindow::updateData(double value)
{
	basicWindow* curr = head;
	deque<double>* data;
	double tmp = value;

	while (curr != NULL)
	{
		data = curr->GetData();
		//curr not full
		if (!curr->isFull())
		{
			data->push_front(tmp);
			break;
		}
		// curr full 
		if (curr->isFull())
		{
			data->push_front(tmp);
			tmp = data->back();
			data->pop_back();
		}
		
		curr = curr->GetNextWindow();
	}
	
}

void slidingWindow::testDigest(map<string, double>* m)
{
	cout << "digest of sliding window:" << endl;
	for (auto it = m->begin(); it != m->end(); it++)
	{
		cout << it->first << ": " << it->second << endl;
	}
}