#ifndef REASON_H
#define REASON_H



#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "rule.h"
#include "tinyxml.h"  
#include "tinystr.h" 
typedef list<RULELIST *> NESTEDRULELIST;
class reason
{
public:
	RULELIST *rList;
	PARALIST *pList;
	TOKENLIST *tList;
	RULEMAP *rMap;
	TOKENMAP *tMap;
	PARAMAP *pMap;
	RULELIST *IndeRList;
	NESTEDRULELIST *nestedRList;
	string rFilePath;	
public:
	reason();
	~reason();
	int InitReasonNetwork();
	void SetFilePath(const string &fpath);
	rule* GetRule(int i);
	para* GetPara(int i);
	token* GetToken(int i);
	RULELIST* GetRuleList();
	PARALIST* GetParaList();
	TOKENLIST* GetTokenList();

	RULELIST* GetIndeRules();
	NESTEDRULELIST* GetNestedRules();
	int LoadAllFromxml();
	int testPara();
	int testIndeRList();
	int testNestedRuleList();
	int testToken();
private:
	int LoadParaFromFile();
	int LoadRuleFromFile();
	int LoadTokenFromFile();

	rule* CreateRules(const string &rn,const string &ant,const string &con);
	para* CreateParas(const string &pname,const string &ptype);
	token* CreateTokens(const string &t);
	token* CreateTokens(const string &tname,const string &tcon);
	int maprListToMap();
	int maptListToMap();
	int mappListToMap();
};

#endif
