#Name: Nazmul Haque Turja (Aggie ID: 800779609)
#Date: 01/26/2022
#Lab: Compilers and Automata
#Purpose: Simple example of counting lines and reporting errors with lex only


all: lab21

lab21: lab2remove.l
	lex lab2remove.l
	gcc -o lab21 lex.yy.c
run: lab21
	./lab21 < comment.tst
clean:
	rm -f lab21
	rm -f lex.yy.c