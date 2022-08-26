#Name: Nazmul Haque Turja (Aggie ID: 800779609)
#Date: 02/16/2022
#Lab: Compilers and Automata


all: lab4

lab4: lab4docalc.y lab4docalc.l
	lex lab4docalc.l 
	yacc -d lab4docalc.y 
	gcc y.tab.c lex.yy.c -o lab4
run: lab4
	./lab4
clean:
	rm -f lab4
	rm -f lex.yy.c
	rm -f y.tab.c
	rm -f y.tab.h