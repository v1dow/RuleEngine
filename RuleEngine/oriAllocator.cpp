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
    SQLCounter = 0;
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

/* append sqlite3 table 
** db: sqlite3 database opend 
** tName: table name that prepare to append to 
** value: data want to append */
bool oriAllocator::appendSQL(sqlite3* db, const string& tName, const string& value)
{
    if(SQLCounter == roundLength * inferRound)
    {
        SQLCounter = 0;
        return true;
    }
    addData(db,tName,value);
    return false;
}

void oriAllocator::loadFromDisk()
{
    double value;
    lengthCounter = 0;
    roundCounter = 0;
    
    
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

/* load memData from sqlite3 table 
** row represents how many data item in the table
** there row is roundLength * inferRound 
** column represents how many attributes in the table 
** there is 2, id and data respectively
** and we ignore the data item of id so we mutiply by column 
** db: sqlite3 database opend 
** tName: table name that prepare to append to */
void oriAllocator::loadFromSQL(sqlite3* db, const string& tName)
{
    double value = 0;
    lengthCounter = 0;
    roundCounter = 0;
    int row = roundLength * inferRound;
    int column = 2;
    char** result = selData(db,tName,to_string(roundLength * inferRound),"0");
    for(int i = 1;i <= row;i++)
    {
        value = atof(result[i*column + 1]);
        genMemData(value);
    }
    // when sqlite3_get_table, don't forget sqlite3_free_table
    sqlite3_free_table(result);
    clrData(db,tName);
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