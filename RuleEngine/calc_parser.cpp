#include "calc.h"
using namespace calc;
int calc_parser::create(int tag)
{
	worktype=tag;


	if(tag==0)
	{
		if(m_symboltable==NULL)
			m_symboltable = new symboltable;
		else
		{
			delete m_symboltable;
			m_symboltable = new symboltable;
		}
		if (m_lexer.create(this, m_symboltable)!=0) {
			printf("Create failed!\n");
		}
	}
	else if(tag==1)
	{
		if(m_symboltable==NULL)
			m_symboltable = new symboltable(80);
		else
		{
			delete m_symboltable;
			m_symboltable = new symboltable(80);
		}
/*		if (!yycreate(&m_lexer)) {
			return 0;
		}
*/
		if (!m_lexer.create(this, m_symboltable)) {
			return 0;
		}

	}	
	return 1;	
}

int calc_parser::GetVariableCount(int left)
{
	if(m_symboltable==NULL)
		return 0;
	else
		return m_symboltable->GetVariableCount(left);
}
char*calc_parser::GetVariableName(int i,int left)
{
	return m_symboltable->GetVariableName(i,left);
}
double calc_parser::assign(symbol* id, double value)
{
	assert(id != NULL);
	id->m_bHasbeenInit= true;
	id->m_value = value;
	return id->m_value;
}
char* calc_parser::assignchar(symbol* id, char* value)
{
	assert(id != NULL&&value!=NULL);
	id->m_bHasbeenInit= true;
	if(id->m_charvalue!=NULL)
	{
		delete[] id->m_charvalue;
		id->m_charvalue=NULL;
	}
	id->m_charvalue = new char[strlen(value) + 1];
	strcpy(id->m_charvalue, value);

	delete[] value;
	return id->m_charvalue;
}
LISTDOUBLE* calc_parser::assignlist(symbol* id, LISTDOUBLE* ld)
{
	assert(id != NULL && !ld->empty());
	id->m_bHasbeenInit = true;
	if(!id->m_lvalue->empty())
	{
		delete id->m_lvalue;
		id->m_lvalue = NULL;
	}
	id->m_lvalue = new deque<double>(*ld);
	return id->m_lvalue;
}
void calc_parser::setnull(symbol* id)
{
	assert(id != NULL);
	id->m_bHasbeenInit= false;
}

void calc_parser::setstrnull(symbol* id)
{
	assert(id != NULL);
	id->m_bHasbeenInit= false;
	if(id->m_charvalue!=NULL)
	{
		delete[] id->m_charvalue;
		id->m_charvalue=NULL;
	}
}
void calc_parser::setlistnull(symbol* id)
{
	assert(id != NULL);
	id->m_bHasbeenInit= false;
	if(id->m_lvalue!=NULL)
	{
		delete id->m_lvalue;
		id->m_lvalue=NULL;
	}
}
double calc_parser::GetIDValue(symbol* id)
{
	assert(id != NULL);
	if(!id->m_bHasbeenInit)
		m_iWrong=2;	
	return 	 id->m_value;
}
char* calc_parser::GetIDCharValue(symbol* id)
{
	assert(id != NULL);
	if(!id->m_bHasbeenInit)
		m_iWrong=2;	
	return 	 id->m_charvalue;
}
LISTDOUBLE* calc_parser::GetLIDValue(symbol* id)
{
	assert(id != NULL);
	if(!id->m_bHasbeenInit)
		m_iWrong=2;	
	return id->m_lvalue;
}
char*calc_parser::AddString(char* a1,char* a2)
{
	assert(a1 != NULL&&a2!=NULL);
	if(strlen(a1)<=2&&strlen(a2)<=2)
	{
		delete[]a1;
		delete[]a2;
		char*cff=new char[2];
		cff[0]='\'';
		cff[1]='\'';
		return cff;
	}
	getstr(a1);
	getstr(a2);

	int len=strlen(a1) + strlen(a2)+1;
	char*cff=new char[len];
	memset(cff,'\0',strlen(cff));
	char*k=NULL;
	cff[len-1]='\0';
	strncpy(cff,a1,strlen(a1));
	k=cff+(strlen(a1));
	strncpy(k,a2,strlen(a2));
	delete[]a1;
	delete[]a2;
	cff = strAdd(cff);
	return cff;
}
char*calc_parser::AddString(symbol* a1,char* a2)
{
	assert(a1->m_charvalue!= NULL&&a2!=NULL);
	if(strlen(a1->m_charvalue)<=2||strlen(a2)<=2)
	{
		delete[]a2;
		char*cff=new char[2];
		cff[0]='\'';
		cff[1]='\'';
		return cff;
	}	
	getstr(a1->m_charvalue);
	getstr(a2);

	int len=strlen(a1->m_charvalue) + strlen(a2)+1;
	char*cff=new char[len];
	char*k;
	cff[len-1]='\0';
	strncpy(cff,a1->m_charvalue,strlen(a1->m_charvalue));
	k=cff+(strlen(a1->m_charvalue));
	strncpy(k,a2,strlen(a2));
	delete[]a2;
	cff = strAdd(cff);
	return cff;
}
char*calc_parser::AddString(char* a1,symbol* a2)
{
	assert(a1 != NULL&&a2->m_charvalue!=NULL);
	if(strlen(a1)<=2||strlen(a2->m_charvalue)<=2)
	{
		delete[]a1;
		char*cff=new char[2];
		cff[0]='\'';
		cff[1]='\'';
		return cff;
	}
	getstr(a1);	
	getstr(a2->m_charvalue);
	
	int len=strlen(a1) + strlen(a2->m_charvalue)+1;
	char*cff=new char[len];
	char*k;
	cff[len-1]='\0';
	strncpy(cff,a1,strlen(a1));
	k=cff+(strlen(a1));
	strncpy(k,a2->m_charvalue,strlen(a2->m_charvalue));
	delete[]a1;
	cff = strAdd(cff);
	return cff;
}
char*calc_parser::AddString(symbol* a1,symbol* a2)
{
	
	getstr(a1->m_charvalue);
	getstr(a2->m_charvalue);

	assert(a1->m_charvalue != NULL&&a2->m_charvalue!=NULL);
	if(strlen(a1->m_charvalue)<=2||strlen(a2->m_charvalue)<=2)
	{
		char*cff=new char[2];
		cff[0]='\'';
		cff[1]='\'';
		return cff;
	}
	int len=strlen(a1->m_charvalue) + strlen(a2->m_charvalue)+1;
	char*cff=new char[len];
	char*k;
	cff[len-1]='\0';
	strncpy(cff,a1->m_charvalue,strlen(a1->m_charvalue));
	k=cff+(strlen(a1->m_charvalue));
	strncpy(k,a2->m_charvalue,strlen(a2->m_charvalue));
	cff = strAdd(cff);
	return cff;
}
double calc_parser::divide(double a, double b)
{
	if (b == 0) {
		return 0;
	}
	else {
	    double kk = a/b;
		return kk;
	}
}
double calc_parser::exponent2(double dividend, double divisor)
{
	double kk = pow(dividend,divisor);
 	return kk;
}
double calc_parser::GetMax(LISTDOUBLE*d)
{
	double max=-999999999;
	double t=0;
	for(int i=0;i<d->size();i++)
	{
		t=d->at(i);
		if(t>max)max=t;		
	}
	d->clear();
	delete d;
	return max;
}
double calc_parser::GetMaxs(double* address, double value)
{
	double max=-999999999;
	double t=0;
	for(double d=0;d<value-1;d++)
	{
		t = *reinterpret_cast<double *>(address);
		if(t>max)max=t;
		address += 1;
	}
	return max;
}
double calc_parser::GetMin(LISTDOUBLE*d)
{
	double min=9999999999;
	double t=0;
	for(int i=0;i<d->size();i++)
	{
		t=d->at(i);
		if(t<min)min=t;		
	}
	d->clear();
	delete d;
	return min;
}
double calc_parser::GetMean(LISTDOUBLE*d)
{
	double total=0;
	double t=0;
	int count = d->size();
	if(count<=0)return 0;

	for(int i=0;i<count;i++)
	{
		t=d->at(i);
		total+=t;		
	}
	d->clear();
	delete d;
	return total/count;
}
int calc_parser::GetAnd(int a1,int a2)
{
   	if(a1!=0&&a2!=0)
 		return 1;//a1&a2=true
   	else
 		return 0;  
}
int calc_parser::GetOr(int a1,int a2)
{
   	if(a1!=0||a2!=0)
 		return 1;//a1|a2=true
   	else
 		return 0;  
}
int calc_parser::GetNot(int a1)
{
   	if(a1!=0)
 		return 0;//!a1
   	else
 		return 1;  
}
int calc_parser::GetEQL(double a1,double a2)
{
   	if(fabs(a1-a2)<0.0000000001)
 		return 1;//a1==a2
   	else
 		return 0;  
}


int calc_parser::GetStrIn(char* a1,char* a2)
{
	char *tmp_a1=new char[strlen(a1)+1];
	//memset(tmp_a1,'\0',sizeof(tmp_a1));
	strcpy(tmp_a1,a1);
	getstr(tmp_a1);

	char *tmp_a2=new char[strlen(a2)+1];
	//memset(tmp_a2,'\0',sizeof(tmp_a2));
	strcpy(tmp_a2,a2);
	getstr(tmp_a2);
  	if(strstr(tmp_a2,tmp_a1)!=NULL)
  	{

		delete[]a1;
		delete[]a2;
		delete[] tmp_a1;
		delete[] tmp_a2;			
 		return 1;
   	}
   	else
   	{
		delete[]a1;
		delete[]a2;	
		delete[] tmp_a1;
		delete[] tmp_a2;	
 		return 0;  
   	} 
}

int calc_parser::GetEQL(char* a1,char* a2)
{
	char *tmp_a1=new char[strlen(a1)+1];
//	memset(tmp_a1,'\0',sizeof(tmp_a1));
	strcpy(tmp_a1,a1);
	getstr(tmp_a1);

	char *tmp_a2=new char[strlen(a2)+1];
//	memset(tmp_a2,'\0',sizeof(tmp_a2));
	strcpy(tmp_a2,a2);
	getstr(tmp_a2);
  	 if(strcmp(a1,a2)==0)
   	{
		delete[]a1;
		delete[]a2;
		delete[] tmp_a1;
		delete[] tmp_a2;	
 		return 1;//a1==a2
   	}
  	 else
  	 {
		delete[]a1;
		delete[]a2;
		delete[] tmp_a1;
		delete[] tmp_a2;	
 		return 0;  
  			 } 
}
int calc_parser::GetLIAN(symbol* a1,char* a2)
{
 	int a=a1->m_value;
 	char *b = a2;
	int len = strlen(b)-1;
	if ( len < 0 ) {
		return 0;
	}
	unsigned long res = 0;
	int v = 0;
	while ( *b && len >=0) {
		v = (*b)-'0';
		if ( v > 1 || v < 0 ) {
			v=1;
		}
		res |= ( v << len);
		len -= 1;
		b++;
	}
	return (a & res) == a ? 1 : 0;
}
int calc_parser::GetLIAN(char* a1,symbol* a2)
{
 	int a=a2->m_value;
 	char *b = a1;
	int len = strlen(b)-1;
	if ( len < 0 ) {
		return 0;
	}
	unsigned long res = 0;
	int v = 0;
	while ( *b && len >=0) {
		v = (*b)-'0';
		if ( v > 1 || v < 0 ) {
			v=1;
		}
		res |= ( v << len);
		len -= 1;
		b++;
	}
	return (a & res) == a ? 1 : 0;
}
int calc_parser::GetBING(symbol* a1,char* a2)
{

	return 0;
}
int calc_parser::GetBING(char* a1,symbol* a2)
{

	return 0;
}


int calc_parser::GetStrIn(symbol* a1,char* a2)
{

	char *tmp_a1 = new char[strlen(a1->m_charvalue)+1];
	//memset(tmp_a1,'\0',sizeof(tmp_a1));
	strcpy(tmp_a1,a1->m_charvalue);
	getstr(tmp_a1);

	char *tmp_a2 = new char[strlen(a2)+1];
	//memset(tmp_a2,'\0',sizeof(tmp_a2));
	strcpy(tmp_a2,a2);
	getstr(tmp_a2);

	if(a1->m_charvalue==NULL || a2 == NULL)
	{
		return 1;
	}
	
   	if(strstr(tmp_a2,tmp_a1)!=NULL)
	{
		delete[] a2;
		delete[] tmp_a1;
		delete[] tmp_a2;
 		return 1;
  	}
   	else
   	{
		delete[] a2;
		delete[] tmp_a1;
		delete[] tmp_a2;
 		return 0;  
   	} 
   
}
int calc_parser::GetStrIn(char* a1,symbol* a2)
{
	char *tmp_a1 = new char[strlen(a1)+1];
	//memset(tmp_a1,'\0',sizeof(tmp_a1));
	strcpy(tmp_a1,a1);
	getstr(tmp_a1);

	char *tmp_a2 = new char[strlen(a2->m_charvalue)+1];
	//memset(tmp_a2,'\0',sizeof(tmp_a2));
	strcpy(tmp_a2,a2->m_charvalue);
	getstr(tmp_a2);

	if(a1 == NULL || a2->m_charvalue == NULL)
	{
		return 1;
	}
   	if(strstr(tmp_a2,tmp_a1)!=NULL)
   	{
		delete[]a1;
		delete[] tmp_a1;
		delete[] tmp_a2;
 		return 1;
   	}
   	else
   	{
		delete[]a1;
		delete[] tmp_a1;
		delete[] tmp_a2;
 		return 0;  
   	} 
}
int calc_parser::GetStrIn(symbol* a1,symbol* a2)
{
	char *tmp_a1 = new char[strlen(a1->m_charvalue)+1];
	//memset(tmp_a1,'\0',sizeof(tmp_a1));
	strcpy(tmp_a1,a1->m_charvalue);
	getstr(tmp_a1);

	char *tmp_a2 = new char[strlen(a2->m_charvalue)+1];
	//memset(tmp_a2,'\0',sizeof(tmp_a2));
	strcpy(tmp_a2,a2->m_charvalue);
	getstr(tmp_a2);

	if(a1->m_charvalue == NULL || a2->m_charvalue == NULL)
	{
		return 1;
	}
   	if(strstr(tmp_a2,tmp_a1)!=NULL)
   	{
		delete[] tmp_a1;
		delete[] tmp_a2;
 		return 1;
  	 }
   	else
   	{	
		delete[] tmp_a1;
		delete[] tmp_a2;
 		return 0;  
   	}
  
}
int calc_parser::getstr(char *source)
{
	if(strchr(source,'\'')==NULL)
		return 1;
	else
	{
		char * first = NULL;
		char * last = NULL;
		char * tmp = new char[strlen(source)+1];
		//memset(tmp,'\0',sizeof(tmp));
		first = strchr(source,'\'');

		strncpy(tmp,source,first-source);

		first++;
		last = strrchr(source,'\'');
	
		strncat(tmp,first,last-first);
		//memset(source,'\0',sizeof(source));
		strcpy(source,tmp);
		delete[] tmp;
	}
	return 0;
}


char *calc_parser::strAdd(char *source)
{
	int length=strlen(source);
	char *tmp = new char[length+3];
	char *p = tmp;
	memset(tmp,'\0',length);
	
	tmp[0]='\'';
	
	strncpy(++p,source,strlen(source));
	tmp[length+1]='\'';
	tmp[length+2]='\0';
	
	delete[] source;
	p=NULL;

	return tmp;  

}

int calc_parser::GetEQL(symbol* a1,char* a2)
{
	char *tmp_a1 = new char[strlen(a1->m_charvalue)+1];
	//memset(tmp_a1,'\0',sizeof(tmp_a1));
	strcpy(tmp_a1,a1->m_charvalue);
	getstr(tmp_a1);

	char *tmp_a2 = new char[strlen(a2)+1];
	//memset(tmp_a2,'\0',sizeof(tmp_a2));
	strcpy(tmp_a2,a2);
	getstr(tmp_a2);
	if(a1->m_charvalue==NULL)
	{
		return 1;
	}
   	if(strcmp(tmp_a1,tmp_a2)==0)
   	{
		delete[]a2;
		delete[] tmp_a1;
		delete[] tmp_a2;
 		return 1;//a1==a2
   	}
  	 else
   	{
		delete[]a2;
		delete[] tmp_a1;
		delete[] tmp_a2;
 		return 0;  
   	} 
}
int calc_parser::GetEQL(char* a1,symbol* a2)
{
	char *tmp_a1 = new char[strlen(a1)+1];
	//memset(tmp_a1,'\0',sizeof(tmp_a1));
	strcpy(tmp_a1,a1);
	getstr(tmp_a1);

	char *tmp_a2 = new char[strlen(a2->m_charvalue)+1];
	//memset(tmp_a2,'\0',sizeof(tmp_a2));
	strcpy(tmp_a2,a2->m_charvalue);
	getstr(tmp_a2);

	if(a1 == NULL || a2->m_charvalue == NULL)
	{
		return 1;
	}
   	if(strcmp(tmp_a1,tmp_a2)==0)
   	{
		delete[]a1;
		delete[] tmp_a1;
		delete[] tmp_a2;
 		return 1;//a1==a2
   	}
   	else
   	{
		delete[]a1;
		delete[] tmp_a1;
		delete[] tmp_a2;
 		return 0;  
   	} 
}
int calc_parser::GetEQL(symbol* a1,symbol* a2)
{
	char *tmp_a1 = new char[strlen(a1->m_charvalue)+1];
	//memset(tmp_a1,'\0',sizeof(tmp_a1));
	strcpy(tmp_a1,a1->m_charvalue);
	getstr(tmp_a1);

	char *tmp_a2 = new char[strlen(a2->m_charvalue)+1];
	//memset(tmp_a2,'\0',sizeof(tmp_a2));
	strcpy(tmp_a2,a2->m_charvalue);
	getstr(tmp_a2);

	if(a1->m_charvalue == NULL || a2->m_charvalue == NULL)
	{
		return 1;
	}
  	 if(strcmp(tmp_a1,tmp_a2)==0)
   	{
		delete[] tmp_a1;
		delete[] tmp_a2;		
 		return 1;//a1==a2
   	}
   	else
   	{
		delete[] tmp_a1;
		delete[] tmp_a2;
 		return 0;  
   	} 
}

int calc_parser::GetNOTEQL(double a1,double a2)
{
   	if(abs(a1-a2)<0.0000000001)
 		return 0;//a1==a2
   	else
 		return 1;  
}
int calc_parser::GetNOTEQL(char* a1,char* a2)
{
	if(a1 == NULL || a2 == NULL)
	{
		return 1;
	}
   	if(strcmp(a1,a2)==0)
   	{
		delete[]a1;
		delete[]a2;
 		return 0;//a1==a2
   	}
   	else
   	{
		delete[]a1;
		delete[]a2;
 		return 1;  
   	} 
}

int calc_parser::GetNOTEQL(symbol* a1,char* a2)
{
	if(a1->m_charvalue == NULL || a2 == NULL)
	{
		return 1;
	}
   	if(strcmp(a1->m_charvalue,a2)==0)
   	{
		delete[]a2;
 		return 1;//a1==a2
   	}
   	else
   	{
		delete[]a2;
 		return 0;  
   	} 
}
int calc_parser::GetNOTEQL(char* a1,symbol* a2)
{
	if(a1 == NULL || a2->m_charvalue == NULL)
	{
		return 1;
	}
   	if(strcmp(a1,a2->m_charvalue)==0)
   	{
		delete[]a1;
 		return 0;//a1==a2
   	}
  	else
   	{
		delete[]a1;
 		return 1;  
  	 } 
}
int calc_parser::GetNOTEQL(symbol* a1,symbol* a2)
{
	if(a1->m_charvalue == NULL || a2->m_charvalue == NULL)
	{
		return 1;
	}
   	if(strcmp(a1->m_charvalue,a2->m_charvalue)==0)
   	{
 		return 0;//a1==a2
   	}
   	else
   	{
 		return 1;  
   	} 
}
int calc_parser::GetLEQL(double a1,double a2)
{
   	if(a1<=a2)
 		return 1;//a1<=a2
   	else
 		return 0;  
}
int calc_parser::GetMEQL(double a1,double a2)
{
   	if(a1>=a2)
 		return 1;//a1>=a2
   	else
 		return 0;  
}
int calc_parser::GetLESS(double a1,double a2)
{
   	if(a1<a2)
 		return 1;//a1<=a2
   	else
 		return 0;  
}
int calc_parser::GetMORE(double a1,double a2)
{
   	if(a1>a2)
 		return 1;//a1>=a2
   	else
 		return 0;  
}

double calc_parser::GetResult()
{
	return m_result;
}   
char*calc_parser::GetStrResult()
{
	return m_strresult;
}
LISTDOUBLE* calc_parser::GetListResult()
{
	return m_lresult;
}
void calc_parser::ClearStrResult()
{
	delete[] m_strresult;
}
void calc_parser::StopWork()
{
	if(m_symboltable!=NULL)
	{
		delete m_symboltable;
		m_symboltable=NULL;
	}

	//yydestroy();
	//m_lexer.yydestroy();
}
void	calc_parser::SetStop()
{
	m_lexer.SetStop();
}
bool calc_parser::GetLogicResult()
{
	//yydestroy();
	//m_lexer.yydestroy();
	return false;
} 

int calc_parser::SetExpression(char*str)
{
	m_lexer.SetExpression(str);
	m_iWrong=0;
	return 1;
}
int calc_parser::GetWrongStat()
{
	return m_iWrong;
}
void calc_parser::SetError()
{
	m_iWrong=1;
}   
void calc_parser::yysyntaxerror()
{
	m_iWrong=1;
}
