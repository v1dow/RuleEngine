LEX=flex
YACC=bison
CC=g++
all:test
test: oriAllocator.o intermediate.o statOp.o optimize.o calc.o calc_parser.o lex.yy.o parser.tab.o reason.o rule.o para.o token.o tinystr.o tinyxmlparser.o tinyxml.o tinyxmlerror.o
	g++ -o test oriAllocator.o intermediate.o statOp.o optimize.o calc.o calc_parser.o lex.yy.o parser.tab.o symbol.o reason.o rule.o para.o token.o tinystr.o tinyxmlparser.o tinyxml.o tinyxmlerror.o

oriAllocator.o: oriAllocator.cpp
	g++ -c oriAllocator.cpp

intermediate.o: intermediate.cpp
	g++ -c intermediate.cpp

statOp.o: statOp.cpp
	g++ -c statOp.cpp

optimize.o: optimize.cpp
	g++ -c optimize.cpp

calc.o: calc.cpp  symbol.cpp
	g++ -c calc.cpp  symbol.cpp

calc_parser.o: calc_parser.cpp symbol.cpp
	g++ -c calc_parser.cpp symbol.cpp

lex.yy.c:lexer.l
	flex lexer.l

parser.tab.c parser.tab.h:parser.y
	bison -d parser.y

lex.o: lex.yy.c parser.tab.c
	g++ -c lex.yy.c parser.tab.c

parser.o: parser.tab.c
	g++ -c parser.tab.c

symbol.o:symbol.cpp
	g++ -c symbol.cpp

reason.o:reason.cpp
	g++ -c reason.cpp

rule.o:rule.cpp
	g++ -c rule.cpp

para.o:para.cpp
	g++ -c para.cpp

token.o:token.cpp
	g++ -c token.cpp

tinystr.o:tinystr.cpp
	g++ -c tinystr.cpp

tinyxmlparser.o:tinyxmlparser.cpp
	g++ -c tinyxmlparser.cpp

tinyxml.o:tinyxml.cpp
	g++ -c tinyxml.cpp

tinyxmlerror.o:tinyxmlerror.cpp
	g++ -c tinyxmlerror.cpp
clean:
	rm -rf *o test 
	
