/*
* YACC Program
* Nazmul Haque Turja 
* Aggie ID: 800779609
* Compilers and Automata Lab 
* Date: 23 February, 2022

	Summary of work that I did: 
	1)	Returned all boldface elements as T_(TOKEN -> element name)
	2)	Followed Extended BNF grammar for C-Algol and changed LEX and YACC codes accordingly


*/


%{	/* begin specs */
#include <stdio.h>
#include <ctype.h>
// #include "lex.yy.c"
int base, debugsw;
extern int mydebug;
extern int lineno;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s on Line number: %d\n", s, lineno);
}


%}//end of c definitions 

/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

%start P

%union{
	int value;
	char * string;
}


%token T_INT T_VOID T_IF T_ELSE T_WHILE T_RETURN T_READ T_WRITE T_LE T_LT T_GT T_GE T_EQ T_NE T_BEGIN T_END T_DO T_TRUE T_FALSE T_NOT T_AND T_OR T_THEN T_OF T_BOOLEAN
%token <string> T_ID
%token <value> T_NUM

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS 

%%	/* end specs, begin rules */

P 		: 	DL /*program -Decleration-list*/
		;
DL 		: 	DEC
		|   DEC DL
		;

DEC     : VARDEC 
		| FUNDEC
		;

VARDEC  : typespec var_list ';'
		;

var_list : T_ID
		| T_ID '[' T_NUM ']'
		| T_ID ',' var_list
		| T_ID '[' T_NUM ']' ',' var_list 
		;
typespec	: T_INT
			| T_VOID
			| T_BOOLEAN
			;	

FUNDEC  : typespec T_ID '(' params ')' compoundstmt
		;

params	: T_VOID
		| paramlist
		;

paramlist	: param
			| param ',' paramlist
			;

param   :  T_ID T_OF typespec
		|  T_ID '[' ']' T_OF typespec
		;

compoundstmt : T_BEGIN localdeclarations statementlist T_END
			 ;

localdeclarations : /* empty */ 
				  | VARDEC localdeclarations
				  ;

statementlist : /* empty */
			  | statement statementlist
			  ;

statement :  expressionstmt
		  |	 compoundstmt
		  |  selectionstmt
		  |  iterationstmt
		  |  assignmentstmt
		  |  returnstmt
		  |  readstmt
		  |  writestmt
		  ;

expressionstmt : ';'
			   | expression ';'
			   ;

selectionstmt : T_IF expression T_THEN statement
			  | T_IF expression T_THEN statement T_ELSE statement
			  ;

iterationstmt : T_WHILE expression T_DO statement
			  ;

returnstmt : T_RETURN ';'
		   | T_RETURN expression ';'
		   ;

readstmt : T_READ var ';'
		 ;

writestmt : T_WRITE expression ';'
		  ;

assignmentstmt  : var '=' simpleexpression ';'
			   ;

expression : simpleexpression
		   ;

var : T_ID 
    | T_ID '[' expression ']' 
    ;

simpleexpression : additiveexpression 
				 | simpleexpression relop additiveexpression
				 ;

relop : T_LE | T_LT | T_GT | T_GE | T_EQ | T_NE
      ;

additiveexpression : term
				   | additiveexpression addop term
				   ;

addop : '+' | '-'
	  ;

term : factor
	 | term multop factor
	 ;

multop : '*' 
	   | '/' 
	   | T_AND
	   | T_OR
       ;

factor : '(' expression ')' 
	   | T_NUM 
	   | var 
	   | call
	   | T_TRUE
	   | T_FALSE
	   | T_NOT factor
       ;

call : T_ID '(' args ')'
	 ;

args : /*empty*/ 
	 | arglist
	 ;

arglist : expression
		| expression ',' arglist
		;


%% /* end rules */

main()
{ yyparse();
printf("parsing complete \n");
}

