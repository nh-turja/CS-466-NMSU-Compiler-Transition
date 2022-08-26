Name: Nazmul Haque Turja
Aggie ID: 800779609
Project Name: Making a calculator with Yacc and Symbol Table


I have done all the requirements required for the project. I have done the following: 

1)  Removed the #include "lex.yy.c" from the Yacc file and 
updated my Makefile to compiler in lex.yy.c. 

2) I extended the context free grammar of the calculator.

3) I updated the lex program to match variable names instead of just single lower case characters

4) I created a %UNION type in YACC to allow LEX to return integer or "char *"

5) I defined each token in the CFG to be either one of the types in the union

6) In lex, I used strdup() to copy yytext to yylval.string so that YACC 
can have a copy of the variable name whenever a VARIABLE matches

7) I do not have "label" in my Symbol Table CODE. I commented out all the unnecessary components of symtable.