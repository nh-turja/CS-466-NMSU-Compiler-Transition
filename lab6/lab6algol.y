/*
* YACC Program
* Nazmul Haque Turja 
* Aggie ID: 800779609
* Compilers and Automata Lab 
* Date: 23 March, 2022

	Summary of work that I did: 
	1)	Returned all boldface elements as T_(TOKEN -> element name)
	2)	Followed Extended BNF grammar for C-Algol and changed LEX and YACC codes accordingly
	3)  Wrote Syntax Directied Semantic Action 


*/


%{	/* begin specs */
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include "ast.h"
// #include "lex.yy.c"


extern int level;
extern int mydebug;
extern int lineno;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s on Line number: %d\n", s, lineno);
}

int yylex();
%}//end of c definitions 

/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

%start P

%union{
	int value;
	char * string;
	ASTnode *node;
	enum OPERATORS operator;
	
}


%token    T_BEGIN T_END T_DO T_AND T_OR T_THEN T_OF
%token <string> T_ID
%token <value> T_BOOLEAN T_NOT T_TRUE T_FALSE T_NUM T_INT T_VOID T_IF T_ELSE T_WHILE T_RETURN T_READ T_WRITE T_LE T_LT T_GT T_GE T_EQ T_NE

%type <node> P DL DEC VARDEC FUNDEC var_list params paramlist param compoundstmt localdeclarations statementlist statement expressionstmt selectionstmt iterationstmt assignmentstmt simpleexpression additiveexpression returnstmt readstmt writestmt expression var arglist args call factor term

%type <operator> relop addop multop typespec

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS 

%%	/* end specs, begin rules */

P 		: 	DL {program= $1;} /*program -Decleration-list*/
		;
DL 		: 	DEC {$$ = $1; }
		|   DEC DL { $$ = $1; 
					$1->next = $2;}
		;

DEC     : VARDEC {$$ = $1;}
		| FUNDEC {$$ = $1;}
		;

VARDEC  : typespec var_list ';' {
			$$ = $2;
			ASTnode *p0;
			p0 = $$;
			while (p0!=NULL)
			{
				p0->operator = $1;
				p0=p0->s1;
			} 
		}
		;

var_list : T_ID { $$ = ASTCreateNode(A_VARDEC); /* Creating Node for Variable Declaration*/
					$$->name = $1;
					}
		| T_ID '[' T_NUM ']' {
			$$ = ASTCreateNode(A_VARDEC);
			$$->name = $1;
			$$->value = $3;
			}
		| T_ID ',' var_list {
						$$ = ASTCreateNode(A_VARDEC);
						$$->name = $1;
						$$->s1 = $3; 
					}
		| T_ID '[' T_NUM ']' ',' var_list {
			$$ = ASTCreateNode(A_VARDEC);
			$$->name = $1;
			$$->value = $3;
			$$->s1 = $6;
			}
		;
typespec	: T_INT { $$ = A_INTDEC; } /* Integer type */
			| T_VOID { $$= A_VOIDDEC; }  /* Void type */
			| T_BOOLEAN { $$ = A_BOOLDEC; }  /* Boolean type */
			;	

FUNDEC  : typespec T_ID '(' params ')' compoundstmt {
			$$ = ASTCreateNode(A_FUNDEC);
			$$->operator = $1;
			$$->name = $2;
			$$->s1= $4;
			$$->s2= $6;
		}
		;

params	: T_VOID {$$ = NULL;}
		| paramlist {$$ = $1;}
		;

paramlist	: param { $$ = $1;}
			| param ',' paramlist {
				$1->next=$3;
				$$ = $1;  
			}
			;

param   :  typespec T_ID {
				$$ = ASTCreateNode(A_PARAM); /* Creating Node for Parameters */
				$$->operator = $1;
				$$->name = $2;
			}
		|  typespec T_ID '[' T_NUM ']' {
				$$ = ASTCreateNode(A_PARAM);
				$$->operator = $1;
				$$->name = $2;	
				$$->value = $4;
		}
		;

compoundstmt : T_BEGIN localdeclarations statementlist T_END {
				$$ = ASTCreateNode(A_BLOCK); /* Creating Node for Block statement inside function */
				if ($2 == NULL)
					$$->s1 = $3;
				else {
					$$->s1 = $2;
					$$->s2 = $3;
				}
			}
			 ;

localdeclarations : /* empty */ {$$ = NULL;}
				  | VARDEC localdeclarations {
					  $1->next=$2;
					  $$=$1;
				  }
				  ;

statementlist : /* empty */ { $$ = NULL; }
			  | statement statementlist {
				  if($1 != NULL){
					  $1->next = $2;
					  $$ = $1;
				  }
				  else{
					  $$ = $2;
				  }
			  }
			  ;

statement :  expressionstmt { $$ = $1; }
		  |	 compoundstmt { $$ = $1; }
		  |  selectionstmt { $$ = $1; }
		  |  iterationstmt { $$ = $1; }
		  |  assignmentstmt { $$ = $1; }
		  |  returnstmt { $$ = $1; }
		  |  readstmt { $$ = $1; }
		  |  writestmt { $$ = $1; }
		  ;

expressionstmt : ';' {
				$$ = NULL;
				$$ = ASTCreateNode(A_EXPRSTMT);
				$$->s1 = NULL; 
			}
			   | expression ';' {
				   $$ = ASTCreateNode(A_EXPRSTMT);
				   $$->s1 = $1;
			   }
			   ;
assignmentstmt : var '=' expression ';' {
				$$ = ASTCreateNode(A_ASSIGNSTMT);
				$$->s1 = $1;
				$$->s2 = $3;
			}
			;
selectionstmt : T_IF expression T_THEN statement { 
				$$ = ASTCreateNode(A_IFSTMT); /* Creating Node for If-then statement*/
				$$->s1 = $2;
				$$->s2 = $4;
				$$->next = NULL;
			}
			  | T_IF expression T_THEN statement T_ELSE statement {
				  $$ = ASTCreateNode(A_IFSTMT); /* Creating Node for If-then-else Statement*/
				  $$->s1 = $2;
				  $$->s2 = $4;
				  $$->next = $6;
			  }
			  ;

iterationstmt : T_WHILE expression T_DO statement {
				$$ = ASTCreateNode(A_WHILESTMT); /* Creating Node for While-do Statemen*/
				$$->s1 = $2;
				$$->s2 = $4;
			}
			  ;

returnstmt : T_RETURN ';' {
			$$ = ASTCreateNode(A_RETURNSTMT);
			$$->s1 = NULL;
		}
		   | T_RETURN expression ';' {
			$$ = ASTCreateNode(A_RETURNSTMT); /* Creating Node for Return Statement*/
			$$->s1 = $2; 
		   }
		   ;

readstmt : T_READ var ';' {
			$$ = ASTCreateNode(A_READSTMT); /* Creating Node for Read Statement*/
			$$->s1 = $2;
		}
		 ;

writestmt : T_WRITE expression ';' {
			$$ = ASTCreateNode(A_WRITESTMT); /* Creating Node for Write Statement*/
			$$->s1 = $2;
		}
		  ;

expression : simpleexpression { $$ = $1; }
		   ;

var : T_ID {
			$$ = ASTCreateNode(A_IDENTIFIER);
			$$->name = $1;
			$$->s1 = NULL;
		}
    | T_ID '[' expression ']' {
		$$ = ASTCreateNode(A_IDENTIFIER);
		$$->name = $1;
		$$->s1 = $3;
	}
    ;

simpleexpression : additiveexpression { $$ = $1; }
				 | simpleexpression relop additiveexpression {
					 $$ = ASTCreateNode(A_EXPR);
					 $$->s1 = $1;
					 $$->operator = $2;
					 $$->s2 = $3;
				 }
				 ;

relop : T_LE { $$ = A_LESSTHANEQUAL; }
		| T_LT { $$ = A_LESSTHAN; }
		| T_GT { $$ = A_GREATERTHAN; }
		| T_GE { $$ = A_GREATERTHANEQUAL; }
		| T_EQ { $$ = A_EQUAL; }
		| T_NE { $$ = A_NOTEQUAL; }
      ;

additiveexpression : term { $$ = $1; }
				   | additiveexpression addop term {
					   $$ = ASTCreateNode(A_EXPR); 
					   $$->s1 = $1; 
					   $$->operator = $2; 
					   $$->s2 = $3;
				   }
				   ;

addop : '+' {$$ = A_PLUS;} 
		| '-' {$$ = A_MINUS;}
	  ;

term : factor {$$ = $1; }
	 | term multop factor {
		 $$ = ASTCreateNode(A_EXPR); /* Creating Node for Expression */
		 $$->s1 = $1;
		 $$->operator = $2;
		 $$->s2 = $3;
	 }
	 ;

multop : '*' {$$ = A_TIMES;}
	   | '/' {$$ = A_DIV;}
	   | T_AND {$$ = A_AND;}
	   | T_OR {$$ = A_OR;}
       ;

factor : '(' expression ')' { $$ = $2;}
	   | T_NUM { 
		   $$ = ASTCreateNode(A_NUMBER); /* Creating Node for Number */
		   $$->value = $1; 
		   }
	   | var { $$ = $1; }
	   | call { $$ = $1; }
	   | T_TRUE { 
		   $$ = ASTCreateNode(A_BOOLDEC); /* Creating Node for Boolean Declaration*/
		   $$->value = $1; }
	   | T_FALSE {  
		   $$ = ASTCreateNode(A_BOOLDEC);
		   $$->value = $1; }
	   | T_NOT factor {
		   $$ = ASTCreateNode(A_BOOLDEC);
		   $$->value = $1;
		   $$->s1 = $2;
	   }
       ;

call : T_ID '(' args ')' {
		$$ = ASTCreateNode(A_CALL); /* Creating Node for Call Function*/
		$$->s1 = $3;
		$$->name = $1; 
	}
	 ;

args : /*empty*/ { $$ = NULL;}
	 | arglist {$$ = $1; }
	 ;

arglist : expression {
			$$ = ASTCreateNode(A_ARGLIST); /* Creating Node for Arguments List*/
			$$->s1 = $1; 
			$$->next = NULL;
		}
		| expression ',' arglist {
			$$ = ASTCreateNode(A_ARGLIST);
			$$->next = $3;
			$$->s1 = $1; 
		}
		;


%% /* end rules */

int main(int argv, char * argc[])
{
	if (argv > 2) mydebug=1; 
	yyparse();
	fprintf(stderr, "The input has been syntactically checked \n");
	ASTprint(0, program); /* Printing the Syntax of the Code */
}

