#include "oriAllocator.h"

oriAllocator::oriAllocator()
{
    samplingRate = 0.1;
    inferPeriod = 1;
    roundLength = inferPeriod / samplingRate;
    inferRound = 5;
    lengthCounter = 0;
    roundCounter = 0;
    fileCounter = 0;
    isReady = 0;
    memData = new deque<deque<double> *>();
    for (int i = 0; i < inferRound; i++)
        memData->push_back(new deque<double>(roundLength, 0));
}

oriAllocator::oriAllocator(const double samplingRate_, const double inferPeriod_)
{
    samplingRate = samplingRate_;
    inferPeriod = inferPeriod_;
    roundLength = inferPeriod / samplingRate;
    inferRound = 100 * 1024 * 1024 / (8 * roundLength);
    lengthCounter = 0;
    roundCounter = 0;
    isReady = 0;
    memData = new deque<deque<double> *>();
    for (int i = 0; i < inferRound; i++)
        memData->push_back(new deque<double>(roundLength, 0));
}

oriAllocator::~oriAllocator()
{
    delete memData;
}

int oriAllocator::isready()
{
    return this->isReady;
}

bool oriAllocator::genMemData(double value)
{
    if (lengthCounter == roundLength)
    {
        lengthCounter = 0;
        roundCounter++;
    }
    if (roundCounter == inferRound)
    {
        roundCounter = 0;
        return true;
    }
    if (roundCounter < inferRound)
    {
        if (lengthCounter < roundLength)
        {
            (memData->at(roundCounter))->at(lengthCounter) = value;
            cout << "deque[" << roundCounter << "][" << lengthCounter << "] update: " << value << endl;
        }
    }
    lengthCounter++;
    return false;
}

bool oriAllocator::appendFile(double value)
{
    ofstream fout("test.txt",ios_base::out | ios_base::app);

    if (fileCounter == roundLength * inferRound)
    {
        fileCounter = 0;
        fout.close();
        return true;
    }
    if (fout.is_open())
    {
        fout<<value<<" ";
        cout<<"file append value: "<<value<<endl;
        fileCounter++;
        return false;
    }
    else
    {
        cout << "Create file test.txt failed." << endl;
    }
    return false;
}

void oriAllocator::loadFromDisk()
{
    double value;
    cout<<"lengthCounter:"<<lengthCounter<<endl;
    cout<<"roundCounter:"<<roundCounter<<endl;
    
    
    ifstream fin("test.txt");
    if (fin.is_open())
    {
        if (fin.good())
        {
            // for (int i = 0; i < inferRound; i++)
            // {
            //     for (int j = 0; j < roundLength; j++)
            //     {
            //         while (fin>>value)
            //         {
            //             memData->at(i)->at(j) = value;
            //         }
            //         ofstream fout("test.txt");
            //         fout.close();
            //     }
            // }
            while(fin>>value){
                cout<<"file data:"<<value<<endl;
                genMemData(value);
                cout<<"read file value:"<<value<<endl;
            }
        }
    }
    ofstream fout("test.txt");
    fout.close();
    fin.close();
}

void oriAllocator::testMemData()
{
    /*
    for(int i = 0;i < memData->size();i++)
    {
        for(int j = 0;j < memData->at(i)->size();j++)
        {
            cout<<"deque["<<i<<"]["<<j<<"]: ";
            cout<<memData->at(i)->at(j)<<" ";
        }
        cout<<endl;
    }
    */
    for (auto oit = memData->begin(); oit != memData->end(); oit++)
    {
        for (auto iit = (*oit)->begin(); iit != (*oit)->end(); iit++)
        {
            cout << *iit << " ";
        }
        cout << endl;
    }
}

void oriAllocator::testFile()
{
    double value;
    ifstream fin("test.txt");
    if(fin.is_open()){
        if(fin.good()){
            cout<<"test File."<<endl;
            while(fin>>value)
            {
                cout<<value<<" ";
            }
            cout<<endl;
        }
    }
    fin.close();
}

deque<deque<double>* >* oriAllocator::GetMemData()
{
    return this->memData;
}

double oriAllocator::GetRoundLength()
{
    return this->roundLength;
}

int oriAllocator::GetInferRound()
{
    return this->inferRound;
}