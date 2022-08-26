#Name: Nazmul Haque Turja (Aggie ID: 800779609)
#Date: 04/08/2022
#Lab: Compilers and Automata

all: lab9

lab9: yacc.y lex.l ast.h ast.c symtable.c symtable.h emit.h emit.c
	lex lex.l 
	yacc -d yacc.y
	gcc y.tab.c lex.yy.c ast.c symtable.c emit.c -o lab9

run: lab9
	./lab9 
	
clean: 
	rm -f lab9
	rm -f lex.yy.c
	rm -f y.tab.c
	rm -f y.tab.h