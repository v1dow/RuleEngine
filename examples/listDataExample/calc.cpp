#include "calc.h"
using namespace calc;
int calc_lexer::create(calc_parser* parser, symboltable* symboltable)
{
	assert(parser != NULL);
	assert(symboltable != NULL);

	stop=-1;
	m_symboltable = symboltable;
	m_parser = parser;
	return 0;
}

double calc_lexer::number(char *yytext) const
{
	errno = 0;		
	char* endp;
	double d = strtod(yytext, &endp);
	if ((d == +HUGE_VAL || d == -HUGE_VAL) && errno == ERANGE) {
		printf("number too big\n");
	}
	return d;
}

double* calc_lexer::address(char *yytext) const
{
	string s = string(yytext);
	stringstream ss;
	ss<<s;
	uintptr_t d;
	ss>>hex>>d;
	double* d_ptr = reinterpret_cast<double *>(d);
	return d_ptr;
}

char* calc_lexer::stringvalue(char *yytext) const
{
	char* endp;
	endp=new char[strlen(yytext)+1];
	strcpy(endp,yytext);
	endp[strlen(yytext)]='\0';
	return endp;
}
bool calc_lexer::IsFloat(char str[])
{
	for(int i=0;i<strlen(str);i++)
	{
		char ch = str[i];
		if((ch<'0'&&ch!='.')||ch>'9'&&ch!='.')
			return false;
	}
	return true;
}
LISTDOUBLE* calc_lexer::listnumber(char *yytext)
{
	errno = 0;		
	char* endp;
	char *beginp;
    	beginp =yytext;
	beginp++;
	int begin=0;
	int end=0;
	LISTDOUBLE*list=new LISTDOUBLE;
	while((endp=strchr(beginp,','))!=NULL)
	{
		char strData[80];
		end = endp - beginp + 1;
		strncpy(strData,beginp,end-1);
		strData[end-1]='\0';
		beginp=endp+1;
		double d;
		if(!IsFloat(strData))
		{
			symbol*p=m_symboltable->search(strData);
			if(p==NULL)
			{
				m_parser->m_iWrong = 2;
				return list;
			}
			else
			{
				d=p->m_value;
			}
		}
		else
		{
			char* e;
			d = strtod(strData, &e);
			if ((d == +HUGE_VAL || d == -HUGE_VAL) && errno == ERANGE) {
				printf("number too big\n");
			}
		}
		list->insert(list->end(),d);
	}
	endp=strchr(beginp,']');
    	end = endp - beginp + 1;
	char strData[80];
	double d;
	strncpy(strData,beginp,end-1);
	strData[end-1]='\0';
	if(!IsFloat(strData))
	{
		symbol*p=m_symboltable->search(strData);
		if(p==NULL)
		{
			m_parser->m_iWrong = 2;
			return list;
		}
		else
		{
			d=p->m_value;
		}
	}
	else
	{
		char* e;
		d = strtod(strData, &e);
		if ((d == +HUGE_VAL || d == -HUGE_VAL) && errno == ERANGE) {
			printf("number too big\n");
		}
	}
	list->insert(list->end(),d);
	return list;
}

symbol* calc_lexer::id(char *yytext) const
{
	symbol* p = m_symboltable->install(yytext);
	if(p==NULL)
		printf("The symbol is null!\n");
	return p;
}

int calc_lexer::SetExpression(char* str)
{
	m_p = str;
	long len= strlen( m_p );
	stop=0;
	return 1;
}
void calc_lexer::SetStop()
{
	long len= strlen( m_p );
	m_p[len]='\n';
}
int calc_lexer::yygetchar()
{
	unsigned char d=*m_p;
	if(stop==1||d=='\0')
	{
		return -1;
	}
	if(d=='\n')
		stop=1;
	m_p=m_p+1;
    return d;
}
