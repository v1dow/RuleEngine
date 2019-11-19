#include "sqliteFunc.h"

bool addData(sqlite3* db, const string& tName, const string& data)
{
	string sqlStr = "";
	sqlStr += "insert into ";
	sqlStr += tName;
	sqlStr += "(data) values(";
	sqlStr += data;
	sqlStr += ");";

	char* cErrMsg;
	int nRes = sqlite3_exec(db, sqlStr.c_str(), 0, 0, &cErrMsg);
	if(nRes != SQLITE_OK)
	{
		cout<<"add "<<tName<<" data fail: "<<cErrMsg<<endl;
		return false;
	}
	return true;
}

char** selData(sqlite3* db, const string& tName, const string& limit, const string& offset)
{
	char** result;
	int row, column;
	string sqlStr = "";
	sqlStr += "select * from ";
	sqlStr += tName;
	sqlStr += " limit ";
	sqlStr += offset;
	sqlStr += ", ";
	sqlStr += limit;
	sqlStr += ";";
	char* cErrMsg;

	int nRes = sqlite3_get_table(db, sqlStr.c_str(), &result, &row, &column, &cErrMsg);
	if(nRes != SQLITE_OK)
	{
		cout<<"data fetch fail."<<endl;
	}
	/* test result*/
	/*
	else{
		printf("row = %d, column = %d\n", row, column);
		printf(result[0]);
		for (int i = 0; i <= row; i++){
			printf("----------- %d -------------\n", i);
			for (int j = 0; j < column; j++) {
				printf("%s  ",  result[i*column + j]);
			}
		}
	}
	*/
	return result;
}

bool clrData(sqlite3* db, const string& tName)
{
	string sqlStr = "";
	sqlStr += "delete from ";
	sqlStr += tName;
	sqlStr += ";";

	char* cErrMsg;
	int nRes = sqlite3_exec(db,sqlStr.c_str(),0,0,&cErrMsg);
	if(nRes != SQLITE_OK)
	{
		cout<<"clear "<<tName<<" fail: "<<cErrMsg<<endl;
		return false;
	}
	return true;
}
