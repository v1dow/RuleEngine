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
#include "window.h"

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

deque<double>* combineWindows(window* windows[], int size);

double GetMax(deque<double>* d);

double GetMin(deque<double>* d);

double GetMean(deque<double>* d);

double GetVar(deque<double>* d);

void makebuffer(double buffer[], double maxindex[], double maxbuffer[], double minindex[], double minbuffer[], size_t maxsize, size_t minsize);

void makebuffer1(double buffer[], double minindex[], double minbuffer[], size_t minsize);

void makebuffer3(double buffer[], double maxindex[], double maxbuffer[], double minindex[], double minbuffer[], double meanindex[], double meanbuffer[],size_t maxsize, size_t minsize, size_t meansize);

void makebuffer4(double buffer[], double maxindex[], double maxbuffer[], double minindex[], double minbuffer[], double meanindex[], double meanbuffer[], double varindex[], double varbuffer[], size_t maxsize, size_t minsize, size_t meansize, size_t varsize);

string ConvertToString(double value);

string ConvertListToString(LISTDOUBLE *lb);

double genRandData(double low, double high);

void updateData(double value, oriAllocator* oa);

void updateDataSQL(const string& value, oriAllocator* oa, sqlite3* db, const string& tName);

void updatePara(optimize* opt, oriAllocator *oa, PARALIST *pl, int index);

void updateParaOPT(optimize* opt, oriAllocator *oa, PARALIST *pl, int index);

void updatePara(optimize* opt, reason* re, oriAllocator* oa, PARALIST* pl, int index);


void updatePara1(PARALIST *pl, double dvalue);

void updateParas1(PARALIST* pl, deque<double>* data[]);

void updateParas2(PARALIST* pl, double buffer[]);

void initReasonwork1(reason *re, calc::calc_parser *parser);

void initReasonwork2(reason *re, calc::calc_parser *parser);

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
