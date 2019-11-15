#include "rule.h"
token::token()
{
	tokenCount++;
	tokenID=tokenCount;
	paraList=new PARALIST();
}
int token::tokenCount=0;

token::token(const string &Name,const string &Content)
{
	tokenCount++;
	tokenID=tokenCount;
	tokenName=Name;
	tokenContent=Content;
	paraList=new PARALIST();
}

token::token(const string &t)
{
	string equalSign="=";
	int len=t.length();
	int result=t.find(equalSign);
	if(result!=t.npos)
	{
		string name=t.substr(0,result);
		string content=t.substr(result+2,len-result-3);
		token(name,content);
	}
}
token::~token()
{ 
      	delete paraList;
	paraList = NULL;

}
string token::GetTokenName()
{
	return this->tokenName;
}

int token::GetTokenID()
{
	return this->tokenID;
}

string token::GetTokenContent()
{
	return this->tokenContent;
}

PARALIST *token::GetParaList()
{
	return this->paraList;
}

bool token::IsParaExist(string paraName)
{
	PARALIST::iterator it = paraList->begin();
	for(;it!=paraList->end();it++)
	{
		if((*it)->GetName() ==paraName)
			return true;
	}
	return false;
}

bool token::IsParaExist(int paraID)
{
	PARALIST::iterator it = paraList->begin();
	for(;it!=paraList->end();it++)
	{
		if((*it)->GetParaID()==paraID)
			return true;
	}
	return false;
}

bool token::IsParaExist(para *para)
{
	PARALIST::iterator it = paraList->begin();
	for(;it!=paraList->end();it++)
	{
		if((*it)->GetParaID()==para->GetParaID())
			return true;
	}
	return false;
}

void token::AddPara(para *p)
{
	paraList->push_back(p);
}