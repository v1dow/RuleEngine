#include "preprocessing.h"
#include <stdio.h>
#include <iostream>

preprocessing::preprocessing()
{
	SUList = new SULIST();
}

preprocessing::~preprocessing()
{
	delete SUList;
}

void preprocessing::trim(string& str)
{
	if (!str.empty())
	{
		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);
	}
}

SULIST* preprocessing::GetSUList()
{
	return this->SUList;
}

bool preprocessing::isInSUList(statisticalUnion* SU)
{
	for (auto SUit = SUList->begin(); SUit != SUList->end(); SUit++)
	{
		if ((*SUit)->isEqual(*SU))
			return true;
	}
	return false;
}


statisticalUnion* preprocessing::CreateSU(int CID, string statStr, int windowSize, int streamID, int period, double value,string AC)
{
	statistical* _statistical = new statistical(statStr);
	statisticalUnion* SU = new statisticalUnion(CID, _statistical, windowSize, streamID, period, value);

	if (!isInSUList(SU))
	{
		SUList->push_back(SU);
		list<string>* ACList = SU->GetACList();
		if (!SU->isInACList(AC))
			ACList->push_back(AC);
	}
	else
	{
		for (auto SUit = SUList->begin(); SUit != SUList->end(); SUit++)
		{
			if ((*SUit)->isEqual(*SU))
			{
				list<string>* ACList = (*SUit)->GetACList();
				if (!(*SUit)->isInACList(AC))
					ACList->push_back(AC);
			}
		}
	}

	return SU;
}

statisticalUnion* preprocessing::CreateSU(int CID, string statStr, int windowSize, int streamID, int period, double value)
{
	statistical* _statistical = new statistical(statStr);
	statisticalUnion* SU = new statisticalUnion(CID, _statistical, windowSize, streamID, period, value);

	if (!isInSUList(SU))
		SUList->push_back(SU);

	return SU;
}


//need compatibility modification
/* extract SU from rule set 
** insert SU into SUList */
void preprocessing::SUExtraction(reason* re)
{
	int CID = 0;
	string stat;
	int streamID;
	int windowSize;
	int period = 0;
	double value = 0.0;
	RULELIST* rList = re->GetRuleList();
	string ant;
	string con;

	int idx = 0;
	size_t found = 0;
	size_t tmpFound = 0;
	string AC;
	
	for (auto rit = rList->begin(); rit != rList->end(); rit++)
	{
		ant = (*rit)->GetAntecedent();
		con = (*rit)->GetConsequent();

		while (1)
		{
			CID += 1;
			if (ant.find("AND") != string::npos)
			{
				idx = 0;
				found = ant.find("AND");
				AC = ant.substr(idx, found - idx);
				trim(AC);
				tmpFound = AC.find("(");
				stat = AC.substr(idx, tmpFound - idx);
				idx = tmpFound;
				tmpFound = AC.find(",");
				streamID = atoi(AC.substr(idx + 2, tmpFound - idx).c_str());
				idx = tmpFound;
				tmpFound = AC.find(")");
				windowSize = atoi(AC.substr(idx + 1, tmpFound - idx).c_str());
				trim(stat);
				trim(AC);
				CreateSU(CID, stat, windowSize, streamID, period, value, AC);
				ant.erase(0, found + 3);
			}
			else
			{
				idx = 0;
				found = ant.length() - 1;
				AC = ant;
				trim(AC);
				tmpFound = AC.find("(");
				stat = AC.substr(idx, tmpFound - idx);
				idx = tmpFound;
				tmpFound = AC.find(",");
				streamID = atoi(AC.substr(idx + 2, tmpFound - idx - 1).c_str());
				idx = tmpFound;
				tmpFound = AC.find(")");
				windowSize = atoi(AC.substr(idx + 1, tmpFound - idx).c_str());
				trim(stat);
				trim(AC);
				CreateSU(CID, stat, windowSize, streamID, period, value, AC);
				break;
			}
		}
	}
}

/* create new SU for characteristic reference
** see the paper for detail */
void preprocessing::SUListProcessing()
{
	int CID = -1;
	string stat;
	int streamID;
	int windowSize;
	int period = 0;
	double value = 0.0;
	
	for (auto SUit1 = SUList->begin(); SUit1 != SUList->end(); SUit1++)
	{
		if ((*SUit1)->GetStat()->GetReference() != "NULL")
		{
			for (auto SUit2 = SUList->begin(); SUit2 != SUList->end(); SUit2++)
			{
				if ((*SUit1)->GetStat()->GetReference() == (*SUit2)->GetStat()->GetStatName() && 
					(*SUit2)->GetStat()->GetIsIncremental() &&
					(*SUit1)->GetWindowSize() != (*SUit2)->GetWindowSize() &&
					(*SUit1)->GetStreamID() == (*SUit2)->GetStreamID() &&
					(*SUit1)->GetPeriod() == (*SUit2)->GetPeriod())
				{
					stat = (*SUit2)->GetStat()->GetStatName();
					streamID = (*SUit1)->GetStreamID();
					windowSize = (*SUit1)->GetWindowSize();
					period = (*SUit1)->GetPeriod();
					CreateSU(CID, stat, windowSize, streamID, period, value);
				}
			}
		}
	}
}

void preprocessing::testSUList()
{
	cout << SUList->size() << endl;
	for (auto SUit = SUList->begin(); SUit != SUList->end(); SUit++)
	{
		cout << (*SUit)->GetSUStr() << ": " << (*SUit)->GetStat()->GetIsIncremental()
			<< "," << (*SUit)->GetStat()->GetReference() << endl;
		list<string>* ACList = (*SUit)->GetACList();
		for (auto ACit = ACList->begin(); ACit != ACList->end(); ACit++)
		{
			cout << (*ACit) << " " << endl;
		}
	}
}