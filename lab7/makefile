#Name: Nazmul Haque Turja (Aggie ID: 800779609)
#Date: 04/08/2022
#Lab: Compilers and Automata

all: lab7

lab7: lab6algol.y lab6algol.l ast.h ast.c symtable.c symtable.h
	lex lab6algol.l 
	yacc -d lab6algol.y
	gcc y.tab.c lex.yy.c ast.c symtable.c -o lab7 
run: lab7
	./lab7 < lab7example.al
	./lab7 < lab7test.al
	
clean: 
	rm -f lab7
	rm -f lex.yy.c
	rm -f y.tab.c
	rm -f y.tab.h