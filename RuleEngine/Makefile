LEX=flex
YACC=bison
CC=g++
all:libRuleEngine.so
libRuleEngine.so: window.o sqliteFunc.o func.o oriAllocator.o intermediate.o statOp.o optimize.o calc.o calc_parser.o lex.yy.o parser.tab.o reason.o rule.o para.o token.o tinystr.o tinyxmlparser.o tinyxml.o tinyxmlerror.o
	g++ -fPIC -shared -o libRuleEngine.so window.o sqliteFunc.o func.o oriAllocator.o intermediate.o statOp.o optimize.o calc.o calc_parser.o lex.yy.o parser.tab.o symbol.o reason.o rule.o para.o token.o tinystr.o tinyxmlparser.o tinyxml.o tinyxmlerror.o -lpthread -lsqlite3

sqliteFunc.o: sqliteFunc.cpp
	g++ -fPIC -c sqliteFunc.cpp

window.o: window.cpp
	g++ -fPIC -c window.cpp

func.o: func.cpp
	g++ -fPIC -c func.cpp

oriAllocator.o: oriAllocator.cpp
	g++ -fPIC -c oriAllocator.cpp

intermediate.o: intermediate.cpp
	g++ -fPIC -c intermediate.cpp

statOp.o: statOp.cpp
	g++ -fPIC -c statOp.cpp

optimize.o: optimize.cpp
	g++ -fPIC -c optimize.cpp

calc.o: calc.cpp  symbol.cpp
	g++ -fPIC -c calc.cpp  symbol.cpp

calc_parser.o: calc_parser.cpp symbol.cpp
	g++ -fPIC -c calc_parser.cpp symbol.cpp

lex.yy.c:lexer.l
	flex lexer.l

parser.tab.c parser.tab.h:parser.y
	bison -d parser.y

lex.yy.o: lex.yy.c parser.tab.c
	g++ -fPIC -c lex.yy.c parser.tab.c

parser.tab.o: parser.tab.c
	g++ -fPIC -c parser.tab.c

symbol.o:symbol.cpp
	g++ -fPIC -c symbol.cpp

reason.o:reason.cpp
	g++ -fPIC -c reason.cpp

rule.o:rule.cpp
	g++ -fPIC -c rule.cpp

para.o:para.cpp
	g++ -fPIC -c para.cpp

token.o:token.cpp
	g++ -fPIC -c token.cpp

tinystr.o:tinystr.cpp
	g++ -fPIC -c tinystr.cpp

tinyxmlparser.o:tinyxmlparser.cpp
	g++ -fPIC -c tinyxmlparser.cpp

tinyxml.o:tinyxml.cpp
	g++ -fPIC -c tinyxml.cpp

tinyxmlerror.o:tinyxmlerror.cpp
	g++ -fPIC -c tinyxmlerror.cpp
clean:
	rm -rf *o test 
	
