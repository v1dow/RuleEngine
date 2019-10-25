#include "reason.h"
#include "calc.h"
#include "parser.tab.h"

#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <string>
#include <time.h>
#include <unistd.h>



#define RAND_M 32767


using namespace calc;


extern "C"
{
extern int yylex(void);
extern void yyerror(const char *);
extern void scan_string(const char* str);
extern void delete_buffer();
}

void UpdatePara(double t, ifstream& fin, PARALIST* pl);

string ConvertToString(double value);

string ConverListToString(LISTDOUBLE* lb);

void initReasonwork(reason *re,calc::calc_parser *parser);

void dataProduce(reason *re);

void changeParaValue(reason *re,rule *tmpRule);

void reasonIndeRules(reason *re,calc::calc_parser *parser);

void reasonNestedRules(reason *re,calc::calc_parser *parser);

void initReason();
