#include "window.h"

window::window(){
    samplingFreq = 0.1;
    timescale = 10;
    size = timescale/samplingFreq;
    counter = 0;
    rawData = new deque<double>(size,0);
}

window::window(const double samplingFreq_, const double timescale_){
    samplingFreq = samplingFreq_;
    timescale = timescale_;
    size = samplingFreq/timescale;
    counter = 0;
    rawData = new deque<double>(size,0);
}

window::~window(){
    delete rawData;
}

bool window::fillWindow(double value){
    if(counter == size){
        counter = 0;
        return true;
    }
    if(counter < size){
        rawData->at(counter) = value;
    }
    counter++;
    return false;
}

deque<double>* window::getData(){
    return this->rawData;
}