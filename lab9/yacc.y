/*
* YACC Program
* Nazmul Haque Turja 
* Aggie ID: 800779609
* Compilers and Automata Lab 
* Date: 29 April, 2022

	Summary of work that I did: 
	1)	Returned all boldface elements as T_(TOKEN -> element name)
	2)	Followed Extended BNF grammar for C-Algol and changed LEX and YACC codes accordingly
	3)  Wrote Syntax Directied Semantic Action for Symbol Table


*/


%{	/* begin specs */
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "symtable.h"
#include "ast.h"
#include "emit.h"

#define max(x,y) ((x)>(y)? (x) : (y))
// #include "lex.yy.c"


extern int mydebug;
extern int lineno;
int maxoffset=0;
int level=0;
int offset = 0;
int goffset = 0;
int moffset = 0;

static FILE *out;

int yylex();
int CompareFormals(ASTnode *formals, ASTnode *actual);

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
	ASTnode *node;
	enum OPERATORS operator;
	
}


%token    T_BEGIN T_END T_DO T_AND T_OR T_THEN T_OF T_NOT T_TRUE T_FALSE
%token <string> T_ID T_QUOTED_STRING
%token <value> T_BOOLEAN T_NUM T_INT T_VOID T_IF T_ELSE T_WHILE T_RETURN T_READ T_WRITE T_LE T_LT T_GT T_GE T_EQ T_NE

%type <node> P DL DEC VARDEC FUNDEC var_list params paramlist param compoundstmt localdeclarations statementlist statement expressionstmt selectionstmt iterationstmt assignmentstmt simpleexpression additiveexpression returnstmt readstmt writestmt expression var arglist args call factor term fundec_head fundec_tail 

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
		|   DEC DL { 
			if($1 == NULL) $$ = $2;
			else {
				$$ = $1; 
				$1->next = $2;
			}
		}
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
				p0->symbol->Type = $1;
				p0=p0->s1;
			} 
		}
		;

var_list : T_ID { 
		if((Search($1, level, 0)) == NULL){
			$$ = ASTCreateNode(A_VARDEC); /* Creating Node for Variable Declaration*/
			$$->symbol = Insert($1,0, 0, level, 1, offset);
			$$->name = $1;
			$$->offset=offset;
			offset +=1;
		} else{
			yyerror($1);
				yyerror("symbol is already used");
			exit(1);
		}
	
					}
		| T_ID '[' T_NUM ']' {
		if(!Search($1, level, 0)){
			$$ = ASTCreateNode(A_VARDEC);
			$$->name = $1;
			$$->value = $3;
			$$->symbol = Insert($1, 0, 2,level,$3,offset);
			$$->offset = offset;
			offset += $3;
		}else{
			yyerror($1);
				yyerror("symbol is already used");
			exit(1);
		}
			
			}
		| T_ID ',' var_list {

		if(!Search($1, level, 0)){
			$$ = ASTCreateNode(A_VARDEC); /* Creating Node for Variable Declaration*/
			$$->name = $1;
			$$->symbol = Insert($1,0, 0, level, 1, offset);
			offset +=1;
			$$->s1 = $3;
			} else{
			yyerror($1);
				yyerror("symbol is already used");
			exit(1);
			}
		}
		| T_ID '[' T_NUM ']' ',' var_list {

		if(!Search($1, level, 0)){
			$$ = ASTCreateNode(A_VARDEC);
			$$->name = $1;
			$$->value = $3;
			$$->symbol = Insert($1, 0, 2,level,$3,offset);
			$$->offset = offset;
			offset += $3;
			$$->s1 = $6;
			} else{
			yyerror($1);
				yyerror("symbol is already used");
			exit(1);
		}

		}
		;
typespec	: T_INT { $$ = A_INTDEC; } /* Integer type */
			| T_VOID { $$= A_VOIDDEC; }  /* Void type */
			| T_BOOLEAN { $$ = A_BOOLDEC; }  /* Boolean type */
			;	


 
FUNDEC : fundec_head fundec_tail {
                $$=$1;
				if($2!=NULL) {   /*we know this is a definition, not prototype*/  
					$$->s2=$2;
					$$->symbol=Search($$->name, level, 0);
					$$->symbol->mysize=maxoffset;
					offset=goffset; 
					maxoffset=0;
												
					}
				else {   /*we know this is a  prototype*/ 
					$$->type=A_FUN_PROTOTYPE; 
					offset=goffset;
					struct SymbTab *p; 
					p=Search($$->name, level, 0);
					p->IsAFunc=4;  /*to differ between definition and prototype*/ 
					Delete(1);   /*need to delete params for prototype so it does nto conflict with definition*/
					}
				}                
       						;
  
fundec_head: typespec T_ID '('  {  
					struct SymbTab *p; 
					p=Search($2, level, 0);

					/* not defined nor declared as prototype */ 
 			        if(p==NULL) { 
						Insert($2,$1,1,level,0,0);
						goffset=offset; offset=0; 
				        }
				
					/* not defined but declared as prototype */ 
                    else if(p!=NULL && p->IsAFunc==4)  
                        {  p->IsAFunc=1; goffset=offset; offset=0;  }
							else {yyerror($2);  printf("func already defined\n"); exit(1);}
				    	}


			params {
             struct SymbTab *p; p=Search($2, level, 0);
             	if (p->fparms==NULL) /* add params, check to match params of definition and prototype  */
             		{(p->fparms)=$5;}
            	else 
					{ 
						if (CompareFormals(p->fparms, $5)!=1) 
							{yyerror($5);  
							printf("param type,name or length mismtach in definition \n"); 
						exit(1);
							}
                 	}
	  		}

			')'
				{
					$$=ASTCreateNode(A_FUNDEC);
					$$->name=$2; $$->operator=$1;$$->istype=$1;
                    $$->s1=$5;
                }

fundec_tail : ';' {$$=NULL;  }    	

           | compoundstmt   {$$=$1; } 

         ;


params: T_VOID     {$$=NULL;}
      | paramlist {$$=$1;}
      ;
paramlist : param   {$$=$1;}
           | param ',' paramlist 
                {$$=$1; $$->next=$3;}
           ;

param : T_ID T_OF typespec
			{
		if(Search($1, level+1, 0)==NULL)
				{ 
			$$=ASTCreateNode(A_PARAM);	
			$$->name=$1;
			$$->operator=$3;
			$$->value=1; 
			$$->symbol=Insert($1,$3,0,level+1,1,offset);
            $$->istype=$3; $$->value=0;
			offset+=1;					
			}
		else {yyerror($1);  printf("param name already in sym table \n"); exit(1);}
            }
			 
      | T_ID '[' ']' T_OF typespec 	{
			
			if(Search($1, level+1, 0)==NULL)
			{
				$$=ASTCreateNode(A_PARAM);	
				$$->name=$1;
				$$->operator=$5;
				$$->value=1; 
				$$->symbol=Insert($1,$5,2,level+1,1,offset);
				$$->istype=$5; $$->value=1;
				offset+=1;
			}
			else {yyerror($1);  printf("param name already in sym table \n"); exit(1);}
	 					}
      ;


compoundstmt : 	T_BEGIN {level++; } 
					localdeclarations statementlist 
				T_END {
				
				$$ = ASTCreateNode(A_BLOCK); /* Creating Node for Block statement inside function */
				$$->s1 = $3;
				$$->s2 = $4;
				Display();
				$$->offset = offset;
				offset -= Delete(level);
				level--;
			}
			 ;

localdeclarations : /* empty */ {
				$$ = NULL;
				}
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
				   $$->istype = $1->istype;
				   $$->s1 = $1;
			   }
			   ;
assignmentstmt : var '=' expression ';' {
				$$ = ASTCreateNode(A_ASSIGNSTMT);
				if (($1->istype == A_VOIDDEC) || ($1->istype != $3->istype)){
					yyerror("type error in assignment statement ");
					exit(1);
				}
				$$->s1 = $1;
				$$->s2 = $3;

				;
			}
			;
selectionstmt : T_IF expression T_THEN statement { 
				$$ = ASTCreateNode(A_IFSTMT); /* Creating Node for If-then statement*/
				$$->s1 = $2;
				$$->s2 = ASTCreateNode(A_IFSTMT);
				$$->s2->s1 = $4;
				$$->s2->s2 = NULL;
			}
			  | T_IF expression T_THEN statement T_ELSE statement {
				$$ = ASTCreateNode(A_IFSTMT); /* Creating Node for If-then statement*/
				$$->s1 = $2;
				$$->s2 = ASTCreateNode(A_IFSTMT);
				$$->s2->s1 = $4;
				$$->s2->s2 = $6;
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
		  | T_WRITE T_QUOTED_STRING ';' {
			  $$ = ASTCreateNode(A_WRITESTMT);
			  $$->name = $2;
			  $$->label = CreateLabel();
		  }
		  ;

expression : simpleexpression { $$ = $1; }
		   ;

var : T_ID {
		struct SymbTab *p;

		if((p=Search($1, level, 1)) != NULL){
			$$ = ASTCreateNode(A_IDENTIFIER); /* Creating Node for Variable Declaration*/
			$$->name = $1;
			$$->symbol = p;
			$$->istype = p->Type;
			printf("Type for VAR is %d \n", p->Type);
			if(p->IsAFunc == 2)
			{
				yyerror(1);
				yyerror("variable is an array, syntax error ");
				exit(1);
			}
			
		} else{
			yyerror($1);
				yyerror("Undeclared variable");
			exit(1);
		}

		}
    | T_ID '[' expression ']' {

		struct SymbTab *p;

		if((p=Search($1, level, 1)) != NULL){
			$$ = ASTCreateNode(A_IDENTIFIER); /* Creating Node for Variable Declaration*/
			$$->name = $1;
			$$->s1 = $3;
			$$->istype = p->Type;

			if(p->IsAFunc == 2) $$->symbol = p;

				else{
					yyerror($1);
					yyerror("not an array, type mismatch");
					exit(1);
				}
			
		} else{
			yyerror($1);
				yyerror("Undeclared variable");
			exit(1);
		}

	}
    ;

simpleexpression : additiveexpression { $$ = $1; }
				 | simpleexpression relop additiveexpression {
					 if($1->istype != $3->istype){
						yyerror("additive type mismatch ");
						exit(1);
					 }
					 $$ = ASTCreateNode(A_EXPR);
					 $$->s1 = $1;
					 $$->operator = $2;
					 $$->s2 = $3;
					 $$->istype = $3->istype;
					 $$->name = CreateTemp();
					 $$->symbol= Insert($$->name, A_INTDEC, 0, level, 1, offset);
					 offset++;
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

					   if($1->istype != $3->istype){
						   yyerror("additive expression type mismatch ");
						   exit(1);
					   }
					   $$ = ASTCreateNode(A_EXPR); 
					   $$->s1 = $1; 
					   $$->operator = $2; 
					   $$->s2 = $3;
					   $$->istype = A_INTDEC;
					   $$->name = CreateTemp();
					   $$->symbol = Insert($$->name, A_INTDEC, 0, level, 1, offset);
					   offset++;
				   }
				   ;

addop : '+' {$$ = A_PLUS;} 
		| '-' {$$ = A_MINUS;}
	  ;

term : factor {$$ = $1; }
	 | term multop factor {
		 if($1->istype != $3->istype){
			 yyerror("term type mismatch ");
			 exit(1);
		 }
		 $$ = ASTCreateNode(A_EXPR); /* Creating Node for Expression */
		 $$->s1 = $1;
		 $$->operator = $2;
		 $$->s2 = $3;
		 $$->istype = A_INTDEC;
		 $$->name = CreateTemp();
		 $$->symbol = Insert($$->name, A_INTDEC, 0, level, 1, offset);
		 offset++;
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
		   $$->istype = A_INTDEC;
		   $$->value = $1; 
		   }
	   | var { $$ = $1; }
	   | call { $$ = $1; }
	   | T_TRUE { 
		   $$ = ASTCreateNode(A_NUMBER);
		   $$->istype = A_INTDEC;
		   $$->value = 1; }
	   | T_FALSE {  
		   $$ = ASTCreateNode(A_NUMBER);
		   $$->istype = A_INTDEC;
		   $$->value = 0; }
	   | T_NOT factor {
		   $$ = ASTCreateNode(A_EXPR);
		   $$->operator=A_NOT;
		   $$->istype = $2->istype;
		   $$->s1 = $2;
	   }
       ;

call : T_ID '(' args ')' {
		
		struct SymbTab *p;

		if((p=Search($1,0,0)) != NULL){
			if(p->IsAFunc != 1){
				yyerror($1);
				printf("Function name not defined");
				exit(1);	
			}
		$$ = ASTCreateNode(A_CALL); /* Creating Node for Call Function*/
		$$->s1 = $3;
		$$->istype = p->Type;
		$$->name = $1; 
		$$->symbol = p;
		}
		else{
			yyerror($1);
			printf("Function name not defined");
			exit(1);
		}
	}
	 ;

args : /*empty*/ { $$ = NULL;}
	 | arglist {$$ = $1; }
	 ;

arglist : expression {
			$$ = ASTCreateNode(A_ARGLIST); /* Creating Node for Arguments List*/
			$$->s1 = $1; 
			$$->istype = $1->istype;
			$$->next = NULL;
		}
		| expression ',' arglist {
			$$ = ASTCreateNode(A_ARGLIST);
			$$->next = $3;
			$$->s1 = $1; 
		}
		;


%% /* end rules */

int main(int argc, char * argv[])
{
	int i = 1;
	FILE *fp = NULL;
	char s[100];
	mydebug = 0;
	while(i < argc){
		if(strcmp(argv[i], "-d") == 0) 
			mydebug = 1;

		if(strcmp(argv[i], "-o") == 0){
			
			mydebug && printf("file name is %s\n",argv[i+1]);
			strcpy(s,argv[i+1]);

			strcat(s,".asm");
			
			
			mydebug && printf("opening %s\n",s);
			fp = fopen(s,"w");
			if(fp == NULL){
				printf("Can not open %s\n",s);
				exit(1);
			}
		}
		i++;
	}
	yyparse();
	if(fp == NULL){
		printf("Must provide a -o file name \n");
		exit(1);
	}
	else{
		emit_header(program, fp);
		emit_ast(program, fp);
}
	
	if(mydebug) Display();
	printf("\n Parsing Complete \n");
	
	if (mydebug) ASTprint(0, program);  /* Printing the Syntax of the Code */
}

