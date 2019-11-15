/****************************************************************************
symbol.cpp
Implements a symbol table for a simple calculator.
****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "symbol.h"

/////////////////////////////////////////////////////////////////////////////
// symbol construction/destruction

symbol::symbol()
{
	m_next = NULL;
	m_name = NULL;
	m_value = 0;
	m_bHasbeenInit=false;
	m_charvalue=NULL;
	m_lvalue = new deque<double>();
}

symbol::~symbol()
{
	delete[] m_name;
	if(m_charvalue!=NULL)
		delete[] m_charvalue;
	delete m_lvalue;
}

/////////////////////////////////////////////////////////////////////////////
// symbol commands

int symbol::create(const char* name)
{
	assert(name != NULL);
	int length = strlen(name);
	m_name = new char[length + 1];
	strcpy(m_name, name);
	return 1;
}

/////////////////////////////////////////////////////////////////////////////
// symboltable construction/destruction

symboltable::symboltable(int c)
{
//	m_bucket=new CObList(BUCKET_SIZE);
	for (int i = 0; i < BUCKET_SIZE; i++) {
		m_bucket[i] = NULL;
	}

}

symboltable::~symboltable()
{
/*	POSITION pos;
	pos = m_bucket->GetHeadPosition();
	for(int i=0;i<BUCKET_SIZE;i++)
	{
		pos=m_bucket->FindIndex(i);
		symbol* p=m_bucket->GetAt(pos);
		delete p;
	}
*/

	for (int i = 0; i < BUCKET_SIZE; i++) {
		symbol* p = m_bucket[i];
		while (p != NULL ) {
			symbol*tmp = p->m_next;
			delete p;
			p = tmp;
		}
	}

}

/////////////////////////////////////////////////////////////////////////////
// symbol commands

int symboltable::hash(const char* name) const
{
	assert(name != NULL);
	int index = 0;
	while (*name != '\0') {
		index = index << 1 ^ *name++;
	}
	index %= BUCKET_SIZE;
	if (index < 0) {
		index = -index;
	}
	return index;
}

symbol* symboltable::install(const char* name)
{
	assert(name != NULL);
	int index = hash(name);
	symbol* p;
	for (p = m_bucket[index]; p != NULL; p = p->m_next) {
		if (strcmp(p->m_name, name) == 0) {
			return p;
		}
	}
	p = new symbol();
	p->create(name);
	p->m_next = m_bucket[index];
	m_bucket[index] = p;

/*
	symbol* p;
	POSITION pos;
	pos = m_bucket->GetHeadPosition();
	for(int i=0;i<BUCKET_SIZE;i++)
	{
		pos=(symbol*) m_bucket->FindIndex( i );
		symbol* p=m_bucket->GetAt(pos);
		if (strcmp(p->m_name, name) == 0) {
			return p;
		}
	}
	p = new symbol();
	p->create(name);
*/
//////////////////////////
	return p;
}
symbol* symboltable::search(const char* name)
{
	assert(name != NULL);
	int index = hash(name);
	symbol* p=NULL;
	for (p = m_bucket[index]; p != NULL; p = p->m_next) {
		if (strcmp(p->m_name, name) == 0) {
			return p;
		}
	}
	return p;
}
int symboltable::GetVariableCount(int left)
{
/*	int index=0;
	for (int i = 0; i < BUCKET_SIZE; i++) {
		symbol* p = m_bucket[i];
		if(left==0&&p != NULL&&p->m_bHasbeenInit)
			index++;
		else if(left!=0&&p != NULL)
			index++;
	}
	return index;
*/
	int index=0;
	for (int i = 0; i < BUCKET_SIZE; i++) {
		symbol* p = m_bucket[i];
		while (p != NULL) {
			if(left==0&&p != NULL&&p->m_bHasbeenInit)
				index++;
			else if(left!=0&&p != NULL)
				index++;
			symbol* next = p->m_next;
			p = next;
		}
	}
	return index;
}
char*symboltable::GetVariableName(int i,int left)
{
	int index=0;
	assert(i < BUCKET_SIZE&&i>=0);
	for (int j = 0; j < BUCKET_SIZE; j++) {
		symbol* p = m_bucket[j];
		while (p != NULL) {
			if(left==0&&p != NULL&&p->m_bHasbeenInit)
			{
				if(index==i)
				{
					return p->m_name;
				}
				else
					index++;
			}
			else if(left!=0&&p != NULL)
			{
				if(index==i)
				{
					return p->m_name;
				}
				else
					index++;
			}
			symbol* next = p->m_next;
			p = next;
		}
	}
	return NULL;
}