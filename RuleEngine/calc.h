#ifndef CALC_H
#define CALC_H




#include "symbol.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <errno.h>
#include <sstream>
#include <string>


namespace calc{
class calc_parser;
class calc_lexer
{
public:
	symboltable * m_symboltable;		
	char *m_p;
	virtual int yygetchar();
	bool IsFloat(char str[]);
	int stop;	
	calc_parser * m_parser;

public:
	int create(calc_parser* parser, symboltable* symboltable);
	int SetExpression(char* str);
	void SetStop();
	
	double number(char *yytext) const;
	LISTDOUBLE* listnumber(char *yytext);
	char* stringvalue(char *yytext) const;
	symbol* id(char *yytext) const;
	double* address(char *yytext) const;
};

class calc_parser
{
public:
	symboltable* m_symboltable;		
	calc_lexer m_lexer;				

	double m_result;
	LISTDOUBLE* m_lresult;	
	char* m_strresult;	
public:	
	int m_iWrong;
	int worktype;

public:
	int create(int tag=0);
	virtual void yysyntaxerror();

	double assign(symbol* id, double value);
	void setnull(symbol* id);
	void setstrnull(symbol* id);
	void setlistnull(symbol* id);
	char* assignchar(symbol* id, char* value);
	LISTDOUBLE* assignlist(symbol* id, LISTDOUBLE* ld);
	double GetIDValue(symbol* id);
	char* GetIDCharValue(symbol* id);
	LISTDOUBLE* GetLIDValue(symbol* id);
	char*AddString(char* a1,char* a2);
	char*AddString(symbol* a1,char* a2);
	char*AddString(char* a1,symbol* a2);
	char*AddString(symbol* a1,symbol* a2);
	double divide(double dividend, double divisor);
	double exponent2(double dividend, double divisor);

	double GetMax(LISTDOUBLE* d);
	double GetMaxs(double* address, double value);
	double GetMin(LISTDOUBLE* d);
	double GetMean(LISTDOUBLE* d);

	int GetStrIn(char* a1,char* a2);
	int GetStrIn(symbol* a1,char* a2);
	int GetStrIn(char* a1,symbol* a2);
	int GetStrIn(symbol* a1,symbol* a2);
	int GetAnd(int a1,int a2);
	int GetOr(int a1,int a2);
	int GetNot(int a1);
	int GetEQL(double a1,double a2);
	int GetEQL(char* a1,char* a2);
	int GetEQL(symbol* a1,char* a2);
	int GetEQL(char* a1,symbol* a2);
	int GetEQL(symbol* a1,symbol* a2);
	int GetNOTEQL(double a1,double a2);
	int GetNOTEQL(char* a1,char* a2);
	int GetNOTEQL(symbol* a1,char* a2);
	int GetNOTEQL(char* a1,symbol* a2);
	int GetNOTEQL(symbol* a1,symbol* a2);
	int GetLEQL(double a1,double a2);
	int GetMEQL(double a1,double a2);
	int GetLESS(double a1,double a2);
	int GetMORE(double a1,double a2);
	
	int GetLIAN(symbol* a1,char*a2);
	int GetLIAN(char* a1,symbol* a2);
	int GetBING(symbol* a1,char*a2);
	int GetBING(char* a1,symbol* a2);
	 
	int getstr(char *source);
	char *strAdd(char *source);
	void SetError();

	double GetResult();
	char*GetStrResult();
	LISTDOUBLE* GetListResult();
	void ClearStrResult();
	int GetWrongStat();
	bool GetLogicResult();
	int SetExpression(char*str);
	void	SetStop();
	
	void StopWork();
	int GetVariableCount(int left);
	char*GetVariableName(int i,int left);
};
}



#endif
