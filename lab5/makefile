#Name: Nazmul Haque Turja (Aggie ID: 800779609)
#Date: 02/16/2022
#Lab: Compilers and Automata

all: lab5

lab5: lab5cminus.y lab5cminus.l
	lex lab5cminus.l 
	yacc -d lab5cminus.y
	gcc y.tab.c lex.yy.c -o lab5
run: lab5
	./lab5 < lab5goodtest.al
	./lab5 < lab5badtest.al
clean: 
	rm -f lab5
	rm -f lex.yy.c
	rm -f y.tab.c
	rm -f y.tab.h