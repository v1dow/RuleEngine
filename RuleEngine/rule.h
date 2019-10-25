#ifndef RULE_H
#define RULE_H


#include <string>
#include <list>
#include <map>
#include <iostream>
#include <deque>
using namespace std;
class rule;
class token;
class para;
typedef list<rule *> RULELIST;
typedef list<token *> TOKENLIST;
typedef list<para *> PARALIST;
typedef map<string, rule *> RULEMAP;
typedef map<string, token *> TOKENMAP;
typedef map<string, para*> PARAMAP;
typedef deque<double> LISTDOUBLE;
class para
{
    private:
        int PID;
        double value;
        LISTDOUBLE* lvalue;
        string Name;
        string Type;        
        static int Pcount;
    public:
	RULELIST *QuotedRuleList;
        TOKENLIST *QuotedTokenList;
    public:
        para();
        para(const string &name,const string &type);
        ~para();
        para(const para &oldPara);
        void AssignParaID();
        RULELIST *GetQuotedRuleList();
	TOKENLIST *GetQuotedTokenList();
        void AddQuotedRule(rule* r);
	void AddQuotedToken(token *t);
        string  GetName();
        string  GetType();
        int  GetParaID();
        void SetName(string &name);
        void SetType(string &type);
        void SetValue(double v);
        double GetValue();
        void SetListValue(LISTDOUBLE* lv);
        LISTDOUBLE* GetListValue();
};
class token
{
private:
  	int tokenID;
  	string tokenName;
  	string tokenContent;
  	static int tokenCount;
public:
	PARALIST *paraList;
public:
	token();
	~token();

	token(const string &Name,const string &Content);
	token(const string &token);
	string GetTokenName();
	int GetTokenID();
	string GetTokenContent();
	bool IsParaExist(string paraName);
	bool IsParaExist(int paraID);
	bool IsParaExist(para *p);
	PARALIST *GetParaList();
	void AddPara(para *p);
};
class rule
{
	private:
                int RID;
                string RuleName;
		string Antecedent;
		string Consequent;
                bool NestedRule;
		PARALIST *AntParaList;
		PARALIST *ConParaList;

                string ReplacedRule;
                static int RCount;
	public:
        //       TList *preQuotedList;
        //        TList *folQuotedList;
		rule();
		~rule();
		rule(const rule& oldRule);
                rule(const string &rname,const string &Ant,const string &Con);
                void Assign();
		PARALIST *GetAntParaList();
		PARALIST *GetConParaList();
                void AddAntPara(para *p);
                void AddConPara(para *p);

                void SetReplacedRule(string as);
                string GetReplacedRule();
                bool isNestedRule();
                void setNestedRuleState(bool flag);
                int  GetRuleID();
                string  GetRuleName();
                void SetRuleName(string rn);
		string  GetAntecedent();
		string  GetConsequent();
		void SetContent(string Ant,string Con);
};
#endif
