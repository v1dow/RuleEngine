#include "statOp.h"

statOp::statOp()
{
	opName = "DefaultName";
	mList = new MIDLIST();
	length = mList->size();
}

statOp::statOp(const string opName)
{
	this->opName = opName;
	this->mList = new MIDLIST();
	this->length = mList->size();
}

statOp::~statOp()
{
	delete mList;
	mList = NULL;
}

void statOp::SetName(string name)
{
	this->opName = name;
}

string statOp::GetName()
{
	return this->opName;
}

void statOp::SetMidList(MIDLIST* list)
{
	this->mList = list;
}

MIDLIST* statOp::GetMidList()
{
	return this->mList;
}

int statOp::GetLength()
{
	return this->length;
}
intermediate* statOp::CreateMid(const string name)
{
	intermediate* med = new intermediate(name);
	mList->push_back(med);
	return med;
}
