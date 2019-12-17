
#ifndef ORIALLOCATOR_H
#define ORIALLOCATOR_H

#include <deque>
#include <iostream>
#include <fstream>
#include "sqliteFunc.h"

using namespace std;

class oriAllocator
{
    double roundLength;
    int inferRound;
    int lengthCounter;
    int roundCounter;
    int fileCounter;
    int SQLCounter;
    deque<deque<double>* >* memData;
    int isReady;

public:
    oriAllocator();
    oriAllocator(const double roundLength_,const int inferRound_);
    ~oriAllocator();

    int isready();

    void loadFromDisk();
    void loadFromSQL(sqlite3* db, const string& tName);
    bool genMemData(double value);
    bool appendFile(double value);
    bool appendSQL(sqlite3* db, const string& tName, const string& value);
    void upgradeDisk();
    void testMemData();
    void testFile();
    deque<deque<double>* >* GetMemData();
    double GetRoundLength();
    int GetInferRound();
};

#endif
