%{

/*
 *			**** CALC ****
 *
 * This routine will function like a desk calculator
 * There are 26 integer registers, named 'a' thru 'z'
 *
 */

/* This calculator depends on a LEX description which outputs either VARIABLE or INTEGER.
   The return type via yylval is integer 

   When we need to make yylval more complicated, we need to define a pointer type for yylval 
   and to instruct YACC to use a new type so that we can pass back better values
 
   The registers are based on 0, so we substract 'a' from each single letter we get.

   based on context, we have YACC do the correct memmory look up or the storage depending
   on position

    Shaun Cooper 
    January 2015

   problems  fix unary minus, fix parenthesis, add multiplication
   problems  make it so that verbose is on and off with an input argument instead of compiled in
*/

/*
  I have extended grammer to accept variable or integer combinations. 
  Also includes symbol table implementation.

Name: Nazmul Haque Turja
Aggie ID: 800779609
Date: 16 February, 2022
*/



	/* begin specs */
#include <stdio.h>
#include <ctype.h>
#include "symtable.h"
#include "symtable.c"
#define MAXSTACK 2

int regs[MAXSTACK];
int STACKP = 0;
int base, debugsw;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s\n", s);
}


%}//end of c definitions 

/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

%start program

%union{
	int value;
	char * string;
}

%token <value> INTEGER
%token <string> VARIABLE 
%token INT
%type <value> expr stat

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS 


%%	/* end specs, begin rules */
program  : decls list
    	 ;

decls  : /* empty */
 		| dec decls
 		;
dec 	: INT VARIABLE{
	        //Search and Insert code here	

	        if(Search($2)){
	           fprintf(stderr, "Error : Symbol %s already defined\n", $2);
	        }
	        else{
	        	if(STACKP >= MAXSTACK)
	        	   fprintf(stderr, "Error : no more register space\n");
	        
	        	else{
	        	Insert($2,STACKP);
	        	STACKP++;
	            }
	        }

	      }
     ';' '\n'


list	:	/* empty */
	|	list stat '\n'
	|	list error '\n'
			{ yyerrok; }
	;

stat	:	expr
			{ fprintf(stderr,"the answer is %d\n", $1); }
	|	VARIABLE{
				if(Search($1)){
				 fprintf(stderr, "Variable %s is defined\n", $1);
				}
				else
					fprintf(stderr, "Variable %s is not defined \n", $1);
				
	} '=' expr
			{ regs[fetch($1)] = $4; }


	;

expr	:	'(' expr ')'
			{ $$ = $2; }
	|	expr '-' expr
			{ $$ = $1 - $3; }
	|	expr '+' expr
			{ $$ = $1 + $3; }
	|	expr '/' expr
			{ $$ = $1 / $3; }
	//added multiplication rules
	|   expr '*' expr
			{ $$ = $1 * $3; }
	|	expr '%' expr
			{ $$ = $1 % $3; }
	|	expr '&' expr
			{ $$ = $1 & $3; }
	|	expr '|' expr
			{ $$ = $1 | $3; }
	|   '-' expr  %prec UMINUS 
			{ $$ = -$2; }
	|	VARIABLE
	          { if(Search($1)){

	                 $$ = regs[fetch($1)];  
                }
               else{
                  fprintf(stderr,"Variable %s does not exist. Defaulting to zero\n", $1);
                  $$ = 0;
               }

	          }
	|	INTEGER {$$=$1; fprintf(stderr,"found an integer\n");}
	;



%%	/* end of rules, start of program */

int main()
{ yyparse();
}
