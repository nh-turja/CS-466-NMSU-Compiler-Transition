#Name: Nazmul Haque Turja (Aggie ID: 800779609)
#Date: 01/23/2022
#Lab: Compilers and Automata


all: lab22

lab22: lab2docalc.y lab2docalc.l
	yacc -d lab2docalc.y 
	lex lab2docalc.l 
	gcc y.tab.c symtable.c lex.yy.c -o lab22
run: lab22
	./lab22
clean:
	rm -f lab22
	rm -f lex.yy.c
	rm -f y.tab.c
	rm -f y.tab.h