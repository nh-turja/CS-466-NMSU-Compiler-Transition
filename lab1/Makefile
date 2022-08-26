#Name: Nazmul Haque Turja (Aggie ID: 800779609)
#Date: 01/19/2022
#Lab: Compilers and Automata
#Purpose: To automate the running lex files


all: lab1

lab1: wordlengthlab1.l
	lex wordlengthlab1.l
	gcc -o lab1 lex.yy.c
run: lab1
	./lab1 < /etc/passwd
clean:
	rm lab1
	rm lex.yy.c