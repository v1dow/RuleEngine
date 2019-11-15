
#ifndef ORIALLOCATOR_H
#define ORIALLOCATOR_H

#include <deque>
#include <iostream>
#include <fstream>

using namespace std;

class oriAllocator
{
    double samplingRate;
    double inferPeriod;
    double roundLength;
    int inferRound;
    int lengthCounter;
    int roundCounter;
    int fileCounter;
    deque<deque<double>* >* memData;
    int isReady;

public:
    oriAllocator();
    oriAllocator(const double samplingRate_,const double inferPeriod_);
    ~oriAllocator();

    int isready();

    void loadFromDisk();
    bool genMemData(double value);
    bool appendFile(double value);
    void upgradeDisk();
    void testMemData();
    void testFile();
    deque<deque<double>* >* GetMemData();
    double GetRoundLength();
    int GetInferRound();
};

#endif
