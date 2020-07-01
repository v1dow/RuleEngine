#ifndef SQLITEFUNC_H
#define SQLITEFUNC_H

#include <iostream>

#include <sqlite3.h>

using namespace std;

bool addData(sqlite3* db, const string& tName, const string& data);

char** selData(sqlite3* db, const string& tName, const string& limit, const string& offset);

bool clrData(sqlite3* db, const string& tName);

#endif
