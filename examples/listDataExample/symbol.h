#ifndef SYMBOL_H
#define SYMBOL_H

/****************************************************************************
symbol.h
Implements a symbol table for a simple calculator.
****************************************************************************/


#include <deque>
#include <iostream>
using namespace std ;
typedef deque<double> LISTDOUBLE;
class symbol{
public:
	symbol();
	virtual ~symbol();

public:
	symbol* m_next;			
	char* m_name;			
	double m_value;			
	char* m_charvalue;
	LISTDOUBLE* m_lvalue;
	bool m_bHasbeenInit;

public:
	int create(const char* name);
};

const int BUCKET_SIZE =5000;				

class symboltable {
public:
	symboltable(int c=BUCKET_SIZE);
	virtual ~symboltable();
	

protected:

	symbol* m_bucket[BUCKET_SIZE];		

protected:
	int hash(const char* name) const;
public:
	symbol* install(const char* name);
	symbol* search(const char* name);
	int GetVariableCount(int left);
	char*GetVariableName(int i,int left);
};

#endif
