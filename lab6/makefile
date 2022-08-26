#Name: Nazmul Haque Turja (Aggie ID: 800779609)
#Date: 03/23/2022
#Lab: Compilers and Automata

all: lab6

lab6: lab6algol.y lab6algol.l ast.h ast.c
	lex lab6algol.l 
	yacc -d lab6algol.y
	gcc y.tab.c lex.yy.c ast.c -o lab6 
run: lab6
	./lab6 < lab6test.al
	./lab6 < lab6mytest.al
	
clean: 
	rm -f lab6
	rm -f lex.yy.c
	rm -f y.tab.c
	rm -f y.tab.h