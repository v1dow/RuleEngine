#ifndef WINDOW_H
#define WINDOW_H

#include <deque>
#include <iostream>

using namespace std;

class window{
    double samplingFreq;
    double timescale;
    double size;
    int counter;
    deque<double>* rawData;

public:
    window();
    window(const double samplingFreq_, const double timescale_);
    ~window();

    bool fillWindow(double value);
    deque<double>* getData();
};

#endif