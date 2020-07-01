#include "reason.h"

reason::reason()
{
	oriParaNum = 0;
	rList = new RULELIST();
	pList = new PARALIST();
	tList = new TOKENLIST();
	rMap = new RULEMAP();
	pMap = new PARAMAP();
	tMap = new TOKENMAP();
	IndeRList = new RULELIST();
	nestedRList = new NESTEDRULELIST();
	srand((unsigned)time(NULL));
}
reason::~reason()
{
	delete rList;
	rList = NULL;
	delete pList;
	pList = NULL;
	delete tList;
	tList = NULL;
	delete rMap;
	rMap = NULL;
	delete pMap;
	pMap = NULL;
	delete tMap;
	tMap = NULL;
	delete IndeRList;
	IndeRList = NULL;
	delete nestedRList;
	nestedRList = NULL;
}
int reason::InitReasonNetwork()
{
	LoadParaFromFile();
	LoadTokenFromFile();
	LoadRuleFromFile();
	maprListToMap();//add the rule pointer to map so that we can find rule* quickly

	//LoadAllFromxml();

	maptListToMap();
	mappListToMap();
	//testPara();
	//testRule();
	//testIndeRList();
	//testNestedRuleList();
	//testToken();
	return 0;
}
int reason::testPara()
{
	PARALIST::iterator pit = pList->begin();
	RULELIST *rltmp;
	RULELIST::iterator rit;
	TOKENLIST::iterator tit;
	TOKENLIST *ttmp = NULL;
	cout<<"pList:";
	for (;pit!=pList->end();pit++)
	{
		// rltmp = (*pit)->GetQuotedRuleList();
		// rit = rltmp->begin();
		// ttmp = (*pit)->GetQuotedTokenList();
		// tit = ttmp->begin();
		// for (;rit!=rltmp->end();rit++)
		// {
		// 	//cout<<"The QuotedRuleList 's member of "<<(*pit)->GetName()<< " are: "<<(*rit)->GetRuleName()<<endl;
		// }
        //         //cout<<"The QuotedTokneList 's member of "<<(*pit)->GetName()<< " are: ";
		// for(;tit!=ttmp->end();tit++)
		// {
        //                 //cout<<(*tit)->GetTokenName()<<" ";
		// }
        //         //cout<<endl;
		
		cout<<(*pit)->GetName()<<" ";

	}
	cout<<endl;

	return 0;
}
int reason::testRule()
{
	RULELIST::iterator rit = rList->begin();
	cout<<"rList:";
	for(;rit != rList->end();rit++)
	{
		cout<<(*rit)->GetAntecedent()<<" ";
	}
	cout<<endl;
	return 0;
}
int reason::testIndeRList()
{

	RULELIST::iterator rit=IndeRList->begin();
	PARALIST::iterator pit;
	PARALIST *tmp = NULL;
	for (;rit!=IndeRList->end();rit++)
	{
		cout<<"there are independent rules: "<<(*rit)->GetRuleName()<<endl;
		cout<<"The replacedRule is :  "<<(*rit)->GetReplacedRule()<<endl;
		tmp = (*rit)->GetConParaList();
		pit = tmp->begin();
		for(;pit!=tmp->end();pit++)
		{
			
			cout<<"The consequent para list is: "<<(*pit)->GetName()<<endl;
		}
	}
	return 0;
}
int reason::testNestedRuleList()
{
	NESTEDRULELIST::iterator neit=nestedRList->begin();
	PARALIST *tmp = NULL;
	RULELIST::iterator rit;
	PARALIST::iterator pit;
	int i = 0;
	for (;neit!=nestedRList->end();neit++)
	{
		rit = (*neit)->begin();
		for (;rit!=(*neit)->end();rit++)
		{
			
			cout<<"The Nested Rules :   "<< i <<"  are: "<<(*rit)->GetRuleName()<<endl;
			cout<<"The replacedRule is :  "<<(*rit)->GetReplacedRule()<<endl;
			tmp = (*rit)->GetConParaList();
			pit = tmp->begin();
			for(;pit!=tmp->end();pit++)
			{

				cout<<"The consequent para list is: "<<(*pit)->GetName()<<endl;
			}
			
		}
		i++;
	}
	return 0;
}
int reason::testToken()
{
	TOKENLIST::iterator tit=tList->begin();
	PARALIST::iterator pit;
	for (;tit!=tList->end();tit++)
	{
		pit=(*tit)->paraList->begin();
		for(;pit!=(*tit)->paraList->end();pit++)
		{

			cout<<"The paras of the "<<(*tit)->GetTokenName()<<"  are: "<<(*pit)->GetName()<<endl;
		}
	}
	return 0;
}
int reason::LoadParaFromFile()
{
	FILE *fp;
	char buff[4096]={'\0'};
	const string pFilePath = "para2.txt";
	fp = fopen(pFilePath.c_str(),"r+");
   	if(!fp)
   	{
		printf("Can't open input file\n");
		return -1;
	}
	string str;//the line including para and it's value
	int plength = 0;
	while(fgets(buff,sizeof(buff),fp)!=NULL)
	{
		str = string(buff);
		plength = str.length();
		if(str.at(0) == '\n' || str.at(0) == ' ')
			continue;
		if(str.at(plength-1) == '\n')
		{
			str = str.erase(plength-1,1);
		}
		CreateParas(str,"NONE");
		oriParaNum += 1;
		memset(buff,'\0',sizeof(buff));
	}
	fclose(fp);
	return 0;	
}
int reason::LoadRuleFromFile()
{
	FILE *fp;
	char buff[4096]={'\0'};
	const string rFilePath = "rule22.txt";
	fp = fopen(rFilePath.c_str(),"r+");
   	if(!fp)
   	{
		printf("Can't open input file\n");
		return -1;
	}
	string strrule ;
	string rn;
	string ant;
	string con;
	int length = 0;
	
	while(fgets(buff,sizeof(buff),fp)!=NULL)
	{
		length = strlen(buff);
		strrule = string(buff);
		int rlength = strrule.length();
		if(strrule.at(0) == '\n' || strrule.at(0) == ' ')
			continue;
		if(strrule.at(rlength-1) == '\n')
		{
			strrule = strrule.erase(rlength-1,1);
		}
		string sa= ":";
		int po = strrule.find_first_of(sa,0);
		if(po!=strrule.npos)
		{
			rn=strrule.substr(0,po); 
		}
		else
		{
			printf("There exists errors in rules!\n");
			return -2;
		}
		string strThen = " THEN ";
		int pos = strrule.find(strThen,0);
		if(pos!=strrule.npos && po!=strrule.npos)
		{
			
			ant=strrule.substr(po+1,pos-po-1);
			con=strrule.substr(pos+6,rlength-pos-5);
			
		}
		else
		{
			printf("There exists errors in rules!\n");
			return -2;
		}
		CreateRules(rn,ant,con);      //call the CreateRules function
		memset(buff,'\0',sizeof(buff));
	}
	fclose(fp);
	return 0;
}
int reason::LoadTokenFromFile()
{
	FILE *fp;
	char buff[4096]={'\0'};
	const string tFilePath = "token.txt";
	fp = fopen(tFilePath.c_str(),"r+");
   	if(!fp)
   	{
		printf("Can't open input file\n");
		return -1;
	}
	string str;//the line including para and it's value
	int tlength = 0;
	while(fgets(buff,sizeof(buff),fp)!=NULL)
	{
		str = string(buff);
		tlength = str.length();
		if(str.at(0) == '\n' || str.at(0) == ' ')
			continue;
		if(str.at(tlength-1) == '\n')
		{
			str = str.erase(tlength-1,1);
		}
		CreateTokens(str);
		memset(buff,'\0',sizeof(buff));
	}
	fclose(fp);
	return 0;
}
int reason::LoadAllFromxml()
{

	TiXmlDocument *RuleDocument=NULL;

	RuleDocument = new TiXmlDocument("Rules.xml");		
	bool loadOK = RuleDocument->LoadFile();

	if(!loadOK)
	{
		printf("Load Rules.xml failed!\n");
		return -1;
	}
	//got the root node...
	TiXmlElement *RootElement = RuleDocument->RootElement();



	//analysis the para 
	TiXmlElement *ParaNode = RootElement->FirstChildElement();
	if(!ParaNode->NoChildren())
	{
		TiXmlElement *pChilds = ParaNode->FirstChildElement();//the current value is paraName;
		//call the CreatePara fucntion...here;
		/*
			we should analysis the QuotedRule list , meanwhile create the network between para and rules 
			The rules instances should be create when the program started!
		*/
		string pValue;
		string qrstring;
		para *tmpp=NULL;
		int beginp=0,endp=0;
		rule *rtmp = NULL;
		RULEMAP::iterator rmapit;
		while (pChilds!=NULL)
		{
			pValue = pChilds->Value();
			if(pValue == "ParaName")
			{
				
				tmpp = CreateParas(pChilds->FirstChild()->Value(),"Unknown");//create the instance of paras.
				//cout<<"Create Para instance of!"<<pChilds->FirstChild()->Value()<<endl;
			}
			if(pValue == "QuotedRule")
			{
				qrstring = pChilds->FirstChild()->Value();
				//cout<<qrstring<<endl;
				
				while((endp = qrstring.find(";",beginp))!=qrstring.npos)
				{
					string tmp = qrstring.substr(beginp,endp-beginp);
					beginp = endp+1;
					rmapit = rMap->find(tmp);
					if (rmapit!=rMap->end())
					{
						tmpp->AddQuotedRule(rmapit->second);
					}
				}
				endp = 0;
				beginp = 0;
			}
			pChilds = pChilds->NextSiblingElement();
		}
	}

	mappListToMap();//map the paralist to the map
	//analysis the Independent Rules
	TiXmlElement *RuleNode = ParaNode->NextSiblingElement();
	TiXmlElement *rChilds = NULL;
	string rValue;
	string pstring;
	RULEMAP::iterator idenrmapit;
	PARAMAP::iterator pmit;
	rule *rtmp = NULL; 
	int epos=0,bpos=0;
	if (!RuleNode->NoChildren())
	{
		rChilds = RuleNode->FirstChildElement();
					
		while(rChilds!=NULL)
		{

			rValue = rChilds->Value();
			if (rValue=="RuleName")
			{
				idenrmapit = rMap->find(rChilds->FirstChild()->Value());
				if (idenrmapit!=rMap->end())
				{
					IndeRList->push_back(idenrmapit->second);
				}
				//cout<<"The RuleName of Independent rule is :"<<rChilds->FirstChild()->Value()<<endl;
			}
			if (rValue == "ReplacedRule")
			{
				if (idenrmapit!=rMap->end())
				{
					idenrmapit->second->SetReplacedRule(rChilds->FirstChild()->Value());
				}
			}
			if(rValue == "ConsequentParaList")
			{
				pstring = rChilds->FirstChild()->Value();
				while((epos = pstring.find(";",bpos))!=pstring.npos)
				{
					string tmp = pstring.substr(bpos,epos-bpos);
					bpos = epos+1;
					pmit = pMap->find(tmp);
					if (pmit!=pMap->end())
					{
						idenrmapit->second->AddConPara(pmit->second);
					}
				}
				epos = 0;
				bpos = 0;

			}
			rChilds = rChilds->NextSiblingElement();
		}
	}

	//got the nested Rules
	TiXmlElement *NestedRuleNode = RuleNode->NextSiblingElement();
	TiXmlElement *nChilds = NULL;
	TiXmlElement *ndChilds = NULL;
	string nestring;
	RULEMAP::iterator nestedrit;
	PARAMAP::iterator paramapit;
	int endpos,beginpos;
	string pastring;
	nChilds = NestedRuleNode->FirstChildElement();
	if (nChilds==NULL)
	{
		cout<<"There is no nestedRules!"<<endl;	
	}
	else
	{
		while(nChilds!=NULL)
		{
			RULELIST *rlList = NULL;
			rlList = new RULELIST();
			ndChilds = nChilds->FirstChildElement();
			//cout<<"The Nested Rule name is : "<<nChilds->Value()<<endl;
			while(ndChilds!=NULL)
			{
				
				nestring = ndChilds->Value();
				if(nestring == "RuleName")
				{
					nestedrit = rMap->find(ndChilds->FirstChild()->Value());
					if (nestedrit!=rMap->end())
					{
						rlList->push_back(nestedrit->second);
					}
					
				}
				if (nestring == "ReplacedRule")
				{
					if (nestedrit!=rMap->end())
					{
						nestedrit->second->SetReplacedRule(ndChilds->FirstChild()->Value());
					}
				}
				if(nestring == "ConsequentParaList")
				{
					pastring = ndChilds->FirstChild()->Value();
					while((endpos = pastring.find(";",beginpos))!=pastring.npos)
					{
						string tmp = pastring.substr(beginpos,endpos-beginpos);
						beginpos = endpos+1;
						paramapit = pMap->find(tmp);
						if (paramapit!=pMap->end())
						{
							nestedrit->second->AddConPara(paramapit->second);
						}
					}
					endpos = 0;
					beginpos = 0;
					
				}
				ndChilds = ndChilds->NextSiblingElement();

			}
			nChilds = nChilds->NextSiblingElement();
			if (nChilds!=NULL)
			{
				ndChilds = nChilds->FirstChildElement();
			}
			nestedRList->push_back(rlList);
		}
	}


	TiXmlElement *TokenNode = NestedRuleNode->NextSiblingElement();
	TiXmlElement *tChilds = NULL; 
	TiXmlElement *tdChilds = NULL;//the whole content of each token
	TiXmlElement *tpChilds = NULL;//paraList
	string tstring;
	string tname,tcon,tpstring;
	int bp=0,ep=0;
	PARAMAP::iterator pmapit;
	token *ttmptoken = NULL;
	tChilds = TokenNode->FirstChildElement();
	tdChilds = tChilds->FirstChildElement();
	if(TokenNode->NoChildren())
	{
		cout<<"There is no Tokens!"<<endl;	
	}
	else
	{
		while(tChilds!=NULL)
		{
			while(tdChilds!=NULL)
			{
				tstring = tdChilds->Value();
				if (tstring == "tokenName")
				{
					tname = tdChilds->FirstChild()->Value();
					//Create the tokens
					
					//cout<<"The token name is :"<<tdChilds->FirstChild()->Value()<<endl;
				}
				if(tstring == "tokenContent")
				{
					tcon = tdChilds->FirstChild()->Value();
					
					//cout<<"The token content is: "<<tdChilds->FirstChild()->Value()<<endl;
				}
				if (tstring == "paraList")
				{

					ttmptoken = CreateTokens(tname,tcon);
					tpChilds = tdChilds->FirstChildElement();
					//the paraList of each token
					tpstring = tpChilds->FirstChild()->Value();
					while((ep = tpstring.find(";",bp))!=tpstring.npos)
					{
						string tmp = tpstring.substr(bp,ep-bp);
						bp = ep+1;
						pmapit = pMap->find(tmp);
						if (pmapit!=pMap->end())
						{
							ttmptoken->AddPara(pmapit->second);//add para to the token's paralist
							pmapit->second->QuotedTokenList->push_back(ttmptoken);//add token* to the para's tokenlist
						}
						//cout<<tmp<<endl;
					}
					ep = 0;
					bp = 0;

				}
				tdChilds = tdChilds->NextSiblingElement();
			}
			tChilds = tChilds->NextSiblingElement();
			if (tChilds!=NULL)
			{
				tdChilds = tChilds->FirstChildElement();
			}
			
		}
	}

	delete RuleDocument;
	return 0;
}
int reason::maprListToMap()
{

	RULELIST::iterator rit = rList->begin();
	for (;rit!=rList->end();rit++)
	{
		rMap->insert(make_pair((*rit)->GetRuleName(),(*rit)));
	}
	return 0;
}
int reason::maptListToMap()
{
	TOKENLIST::iterator tit = tList->begin();
	for (;tit!=tList->end();tit++)
	{
		tMap->insert(make_pair((*tit)->GetTokenName(),(*tit)));
	}
	return 0;
}
int reason::mappListToMap()
{
	PARALIST::iterator pit = pList->begin();
	for (;pit!=pList->end();pit++)
	{
		pMap->insert(make_pair((*pit)->GetName(),(*pit)));
	}
	return 0;
}
void reason::SetFilePath(const string &fpath)
{
	this->rFilePath = fpath;
}
rule *reason::GetRule(int i)
{
	RULELIST::iterator it = rList->begin();
	int count = 0;
	for(;it!=rList->end();it++)
	{
		if(i==count++)
			return *it;
	}	
	return *it;
}
para *reason::GetPara(int i)
{
	PARALIST::iterator it = pList->begin();
	int count = 0;
	for(;it!=pList->end();it++)
	{
		if(i==count++)
			return *it;
	}	
	return *it;
}
token *reason::GetToken(int i)
{
	TOKENLIST::iterator it =tList->begin();
	int count = 0;
	for(;it!=tList->end();it++)
	{
		if(i==count++)
			return *it;
	}	
	return *it;
}
RULELIST *reason::GetRuleList()
{
	return this->rList;
}
PARALIST *reason::GetParaList()
{
	return this->pList;
}
TOKENLIST *reason::GetTokenList()
{
	return this->tList;
}
rule* reason::CreateRules(const string &rn,const string &ant,const string &con)
{
	rule *r = new rule(rn,ant,con);
	rList->push_back(r);
	return r;
}
para* reason::CreateParas(const string &pname,const string &ptype)
{
	para *p = new para(pname,ptype);
	LISTDOUBLE* lv = new deque<double>();
	p->SetValue(rand()%100);
	lv->push_back(0);
	p->SetListValue(lv);
	pList->push_back(p);
	delete lv;
	return p;
}
token* reason::CreateTokens(const string &tokenstr)
{	
	token *t = new token(tokenstr);
	tList->push_back(t);
	return t;
}
token *reason::CreateTokens(const string &tname,const string &tcon)
{
	token *t = new token(tname,tcon);
	tList->push_back(t);

	return t;
}
RULELIST* reason::GetIndeRules()
{
	return IndeRList;
}
NESTEDRULELIST* reason::GetNestedRules()
{
	return nestedRList;
}
int reason::GetOriParaNum()
{
	return oriParaNum;
}
