#ifndef FUNC_H
#define FUNC_H

#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <time.h>
#include <unistd.h>
#include <vector>
#include <array>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "reason.h"
#include "calc.h"
#include "optimize.h"
#include "parser.tab.h"
#include "oriAllocator.h"

#define RAND_M 32767

bool ready = false;


using namespace calc;


extern "C"
{
extern int yylex(void);
extern void yyerror(const char *);
extern void scan_string(const char* str);
extern void delete_buffer();
}

string ConvertToString(double value);

string ConvertListToString(LISTDOUBLE *lb);

double genRandData(double low, double high);

void updateData(double value, oriAllocator* oa);

void updateDataSQL(const string& value, oriAllocator* oa, sqlite3* db, const string& tName);

void updatePara(optimize* opt, oriAllocator *oa, PARALIST *pl, int index);

void updateParaOPT(optimize* opt, oriAllocator *oa, PARALIST *pl, int index);

void updatePara(optimize* opt, reason* re, oriAllocator* oa, PARALIST* pl, int index);


void updatePara1(PARALIST *pl, double dvalue);

void initReasonwork(reason *re, calc::calc_parser *parser);

void reshapeRulePara(reason *re, calc::calc_parser *parser, optimize* opt);

void dataProduce(reason *re);

void changeParaValue(reason *re, rule *tmpRule);

void testReason(reason *re, calc::calc_parser *parser);

void reasonRules(reason *re, calc::calc_parser *parser);

void reasonRulesList(optimize* opt, reason *re, calc::calc_parser *parser, oriAllocator *oa, PARALIST *pl);

void reasonOnce(optimize* opt, reason *re, calc::calc_parser *parser, oriAllocator *oa, PARALIST *pl);

void reasonOnceOPT(optimize* opt, reason *re, calc::calc_parser *parser, oriAllocator *oa, PARALIST *pl);

void reasonOnceSQL(optimize* opt, reason *re, calc::calc_parser *parser, oriAllocator *oa, PARALIST *pl, sqlite3* db, const string& tName);

void reasonOnceOPTSQL(optimize* opt, reason* re, calc::calc_parser* parser, oriAllocator* oa, PARALIST* pl, sqlite3* db, const string& tName);

void reasonIndeRules(reason *re, calc::calc_parser *parser);

void reasonNestedRules(reason *re, calc::calc_parser *parser);



#endif
