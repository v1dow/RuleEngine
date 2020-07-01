#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <sqlite3.h>
#include <time.h>

#include "sqliteFunc.h"

using namespace std;

int main(void)
{
	sqlite3 *db = NULL;
	char* zErrMsg = 0;
	int rc;
	double value = 0;
	srand((unsigned)time(NULL));
	rc = sqlite3_open("test.db",&db);
	if(rc)
	{
		fprintf(stderr,"Can't open database:%s\n",sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}	
	else
		printf("opened a sqlite3 seccessfully.");
	for(int i=0;i<100;i++)
	{
		value = 0.7 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (1.5 - 0.7)));
		addData(db,"vibration",to_string(value));
	}
	char** result = selData(db,"vibration","20","10");
	sqlite3_free_table(result);
	sqlite3_close(db);
	return 0;
}
