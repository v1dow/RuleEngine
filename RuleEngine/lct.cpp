#include "lct.h"



lct::lct()
{
	TSA = new set<int>();
	TSB = new set<int>();
	TS = new set<int>();
	ND = new vector<int>();
	SS = new set<string>();
	btu = 1;

	NDColumns = new COLUMNS();
	TSAColumns = new COLUMNS();
}

lct::~lct()
{
	delete TSA;
	delete TSB;
	delete TS;
	delete ND;
	delete SS;

	delete NDColumns;
	delete TSAColumns;
}

void lct::lctInit(preprocessing* prep)
{
	SULIST* SUList = prep->GetSUList();
	genTSA(SUList);
	genTSB(SUList);
	genTS();
	genND(SUList);
	genSS(SUList);
	
	//btu = multiGcd(TS);
}

void lct::genTSA(SULIST* SUList)
{
	for (auto SUit = SUList->begin(); SUit != SUList->end(); SUit++)
	{
		if ((*SUit)->GetStat()->GetIsIncremental())
		{
			TSA->insert((*SUit)->GetWindowSize());
		}
	}
}

void lct::genTSB(SULIST* SUList)
{
	for (auto SUit = SUList->begin(); SUit != SUList->end(); SUit++)
	{
		if ((*SUit)->GetStat()->GetIsIncremental())
		{
			TSB->insert((*SUit)->GetWindowSize());
		}
	}
}

void lct::genTS()
{
	set_union(TSA->begin(), TSA->end(), TSB->begin(), TSB->end(), inserter(*TS, TS->begin()));
}

void lct::genND(SULIST* SUList)
{
	int tmp = 0;
	for (auto it = TSA->begin(); it != TSA->end(); it++)
	{
		ND->push_back((*it) - tmp);
		tmp = (*it);
	}
}

void lct::genSS(SULIST* SUList)
{
	for (auto SUit = SUList->begin(); SUit != SUList->end(); SUit++)
	{
		if ((*SUit)->GetStat()->GetIsIncremental())
		{
			SS->insert((*SUit)->GetStat()->GetStatName());
		}
	}
}

void lct::updateSS(preprocessing* prep,int windowSize)
{
	SS->clear();
	SULIST* SUList = prep->GetSUList();
	for (auto SUit = SUList->begin(); SUit != SUList->end(); SUit++)
	{
		if (windowSize <= (*SUit)->GetWindowSize() && (*SUit)->GetStat()->GetIsIncremental())
		{
			SS->insert((*SUit)->GetStat()->GetStatName());
		}
	}
}

map<string, double>* lct::GetDigest(map<string, double>* base, map<string, double>* incremental)
{
	map<string, double>* digest = new map<string, double>();
	deque<double>* tmpDQ;
	double tmp = 0;
	for (auto it1 = base->begin(); it1 != base->end(); it1++)
	{
		for (auto it2 = incremental->begin(); it2 != incremental->end(); it2++)
		{
			if (it1->first == it2->first)
			{
				tmpDQ = new deque<double>();
				tmpDQ->push_back(it1->second);
				tmpDQ->push_back(it2->second);
				tmp = digestGenerator(it1->first, tmpDQ);
				delete tmpDQ;
				digest->insert(pair<string, double>(it1->first, tmp));
			}
		}
	}
	return digest;
}

// generate digest of entry in columns 
map<string, double>* lct::CreateEntry(slidingWindow* SW, int start, int end)
{
	map<string, double>* entry;
	entry = SW->GetDigest(SS, start, end);
	return entry;
}

// construct ND column of ND columns
COLUMN* lct::CreateNDColumn(preprocessing* prep, slidingWindow* SW, int windowSum, int attr)
{
	COLUMN* Column = new COLUMN();
	updateSS(prep, attr);
	map<string, double>* tmp;
	for (int i = 0;i < windowSum +1;i++)
	{
		tmp = CreateEntry(SW, i, i + attr - 1);
		Column->push_back(tmp);
	}
	return Column;
}

/* construct ND Columns in lct 
   complete NDColumns */
void lct::CreateNDColumns(preprocessing* prep, slidingWindow* SW)
{
	deque<int>* loss = new deque<int>();
	int windowSum = accumulate(ND->begin(), ND->end(), 0);
	COLUMN* NDColumn;
	// construct ND columns according to elements of ND, reversely construct
	for (int i = ND->size() - 1; i >= 0; i--)
	{
		windowSum -= ND->at(i);
		// not found
		if (find(loss->begin(), loss->end(), ND->at(i)) == loss->end())
		{
			loss->push_back(ND->at(i));
			NDColumn = CreateNDColumn(prep,SW,windowSum,ND->at(i));
		}
		else {
			continue;
		}
		NDColumns->insert(pair<int, COLUMN*>(ND->at(i),NDColumn));
		if(i == 0)
			TSAColumns->insert(pair<int, COLUMN*>(ND->at(i), NDColumn));
	}
	delete loss;
}

void lct::updateNDColumns(preprocessing* prep,slidingWindow* SW)
{
	map<string, double>* entry;
	int windowSize = 0;
	COLUMN* column;

	for (auto NDCit = NDColumns->begin(); NDCit != NDColumns->end(); NDCit++)
	{
		column = NDCit->second;
		windowSize = NDCit->first;
		updateSS(prep, windowSize);
		entry = SW->GetDigest(SS, 0, windowSize - 1);
		column->pop_back();
		column->push_front(entry);
	}
}

// construct TSA column of TSA columns
COLUMN* lct::CreateTSAColumn(preprocessing* prep, int attr, map<string, double>* base, map<string, double>* incremental)
{
	COLUMN* Column = new COLUMN();
	updateSS(prep, attr);
	map<string, double>* tmp = GetDigest(base,incremental);
	Column->push_back(tmp);
	return Column;
}

/* construct TSA Columns in lct
   complete TSAColumns */
void lct::CreateTSAColumns(preprocessing* prep)
{
	COLUMN* TSAColumn;
	map<string, double>* base;
	map<string, double>* incremental;
	set<int>::iterator pre = TSA->begin();
	int i = 1;

	for (auto it = TSA->begin(); it != TSA->end(); it++)
	{
		if (it == TSA->begin())
		{
			continue;
		}
		if (i == TSA->size())
		{
			break;
		}
		base = (TSAColumns->find(*pre)->second)->at(0);
		incremental = (NDColumns->find(ND->at(i))->second)->at(*pre);
		TSAColumn = CreateTSAColumn(prep,*it,base, incremental);
		pre = it;
		i++;
		TSAColumns->insert(pair<int, COLUMN*>(*it, TSAColumn));
	}
}

void lct::updateTSAColumns(preprocessing* prep)
{
	map<string, double>* entry;
	map<string, double>* base;
	map<string, double>* incremental;
	set<int>::iterator pre = TSA->begin();
	int windowSize = 0;
	COLUMN* column;
	int i = 1;

	for (auto it = TSA->begin(); it != TSA->end(); it++)
	{
		if (it == TSA->begin())
		{
			continue;
		}
		if (i == TSA->size())
		{
			break;
		}
		updateSS(prep, windowSize);
		column = TSAColumns->find(*it)->second;
		base = (TSAColumns->find(*pre)->second)->at(0);
		incremental = (NDColumns->find(ND->at(i))->second)->at(*pre);
		entry = GetDigest(base,incremental);
		column->pop_back();
		column->push_front(entry);
		pre = it;
		i++;
	}
}

void lct::updateSUValue(preprocessing* prep)
{
	SULIST* SUList = prep->GetSUList();
	for (auto SUit = SUList->begin(); SUit != SUList->end(); SUit++)
	{
		for (auto it = TSAColumns->begin(); it != TSAColumns->end(); it++)
		{
			if (it->first == (*SUit)->GetWindowSize())
			{
				for (auto Dit = (it->second)->begin(); Dit != (it->second)->end(); Dit++)
				{
					// assign lct value to SU
					(*SUit)->SetValue((*Dit)->find((*SUit)->GetStat()->GetStatName())->second);
				}
			}
		}
	}
}

int lct::GetBtu()
{
	return this->btu;
}

set<string>* lct::GetSS()
{
	return this->SS;
}

void lct::testTSAColumns(preprocessing* prep)
{
	map<string, double>* entry;
	int windowSize = 0;
	COLUMN* column;

	for (auto it = TSA->begin(); it != TSA->end(); it++)
	{
		updateSS(prep, windowSize);
		column = TSAColumns->find(*it)->second;
		cout << "lct window size: " << *it << endl;
		entry = column->at(0);
		for (auto mit = entry->begin(); mit != entry->end(); mit++)
		{
			cout << mit->first << ": " << mit->second << endl;
		}
	}
}