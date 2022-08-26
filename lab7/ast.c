/*   Abstract syntax tree code

    This code is used to define an AST node, 
    routine for printing out the AST
    defining an enumerated type so we can figure out what we need to
    do with this.  The ENUM is basically going to be every non-terminal
    and terminal in our language.

    #Name: Nazmul Haque Turja (Aggie ID: 800779609)
    #Date: 04/08/2022
    #Lab: Compilers and Automata
    Changes made in the code: 
    1. Wrote all the cases for ASTtype
    2. Used level for creating indentation

*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>
#include "ast.h" 
#include "symtable.h"
extern int mydebug;



/* uses malloc to create an ASTnode and passes back the heap address of the newley created node */
//PRE: AST_Node_Type
//POST: ptr to ASTnode from heap with all links set to NULL
//    MyType is set to my_type
ASTnode *ASTCreateNode(enum ASTtype my_type)
{
    ASTnode *p;
    if (mydebug) fprintf(stderr,"Creating AST Node \n");
    p=(ASTnode *)malloc(sizeof(ASTnode));
    p->type=my_type;
    p->s1=NULL;
    p->s2=NULL;
    p->value=0;
    p->next=NULL;
    return(p);
}

/*  Helper function to print tabbing */

void PT(int howmany)
{
	 // MISSING
}



/*  Print out the abstract syntax tree */
//Pre: Insert a label and ASTnode
//Post: Printing the items of the ASTnode
void ASTprint(int level,ASTnode *p)
{
   int i;
   if (p == NULL ) return;
   else
    { 
      for(i=0;i<level;i++) printf(" "); /*indent */
      switch (p->type) {
        case A_VARDEC :  printf("Variable ");
                      if (p->operator == A_VOIDDEC)
                        printf("VOID ");
                      if (p->operator == A_INTDEC)
                        printf("INT ");
                      if (p->operator == A_BOOLDEC)
                        printf("BOOLEAN ");
                      printf(" %s",p->name);

                     if (p->value > 0)
                        printf("[%d]",p->value);
                     printf("\n");
		                ASTprint(level,p->s1);
                     break;
        case A_FUNDEC :  
                    if (p->operator == A_INTDEC)
                      printf("INT ");
                    if (p->operator == A_VOIDDEC)
                      printf("VOID ");
                    if (p->operator == A_BOOLDEC)
                      printf("BOOLEAN ");
                     printf("FUNCTION \n",p->name);
                     /* print out the parameter list */
                    if (p->s1 == NULL ) {  
		                      printf (" (VOID) "); }
                     else
                       { 
                         printf( "( \n");
                          ASTprint(level+2, p->s1);
                         PT(level+2);
                         printf( ") ");
                       }
                     printf("\n");
                     ASTprint(level+2, p->s2); // print out the block
                     break;
        case A_PARAM :  printf("PARAMETER ");
                      if (p->operator == A_INTDEC)
                         printf (" INT ");
                      if (p->operator == A_VOIDDEC)
                         printf (" VOID ");
                      if (p->operator == A_BOOLDEC)
                         printf (" BOOLEAN ");

                      printf (" %s \n",p->name);
                      if (p->value == -1 ) 
                         printf("[]");
                      ASTprint(level+1, p->s1);                
                     break;

        case A_BLOCK :  printf("BLOCK STATEMENT  \n");
                     ASTprint(level+1, p->s1);
                     ASTprint(level+1, p->s2);
                     break;
        
        case A_ASSIGNSTMT: printf("ASSIGNMENT STATEMENT \n");

                    ASTprint(level+1, p->s1);
                    ASTprint(level+1, p->s2);
                    break;

        case A_IFSTMT: printf("IF STATEMENT \n");

                  ASTprint(level+1, p->s1);
                  ASTprint(level+2, p->s2);
                  if(p->next != NULL){
                    for(i=0;i<level;i++) printf(" ");
                    printf("ELSE STATEMENT \n");
                    ASTprint(level+2, p->next);
                  }
                  break;
        
        case A_WHILESTMT :  printf("WHILE STATEMENT \n");

                     ASTprint(level+1, p->s1);
                     ASTprint(level+2, p->s2);
                     break;

        case A_ARGLIST: printf("ARGLIST \n");

                    ASTprint(level+1, p->s1);
                    break;

        case A_WRITESTMT :  printf("WRITE STATEMENT\n");

                     ASTprint(level+1, p->s1);
                     break;

        case A_READSTMT :  printf("READ STATEMENT\n");

                     ASTprint(level+1, p->s1);
                     break;

        case A_RETURNSTMT : 
                      if(p->s1 == NULL){
                        printf("RETURN STATEMENT \n");

                      }
                      else {
                        printf("RETURN STATEMENT with expression: \n");
                        ASTprint(level+1, p->s1);
                      }
                      break;
        
        case A_CALL : printf("CALL: %s \n", p->name);

                    ASTprint(level+1, p->s1);
                    break;
        
        case A_EXPRSTMT: printf("EXPRESSION STATEMENT \n");

                    ASTprint(level+1, p->s1);
                    break;

        case A_EXPR :  printf("EXPR ");
                     switch(p->operator) {
   			                case A_PLUS : printf(" + ");
                                      break;
   			                case A_MINUS: printf(" - ");
                                      break;
                        case A_TIMES: printf(" * ");
                                      break;
                        case A_DIV : printf(" / ");
                                      break;
                        case A_AND: printf(" & ");
                                      break;
                        case A_OR : printf(" | ");
                                      break;
                        case A_MOD : printf(" % ");
                                      break;
                        case A_LESSTHANEQUAL : printf(" <= ");
                                      break;
                        case A_LESSTHAN : printf (" < ");
                                      break;
                        case A_GREATERTHANEQUAL : printf(" >= ");
                                      break;
                        case A_GREATERTHAN : printf(" > ");
                                      break;
                        case A_EQUAL : printf(" = ");
                                      break;
                        case A_NOTEQUAL : printf(" != ");
                                      break;
                        
                       }
                     printf("\n");

                      ASTprint(level+1, p->s1);
		                  if (p->operator != A_NOT) 
                         ASTprint(level+1, p->s2);
                     break;
        
        
        case A_NUMBER :  printf("NUMBER with value %d\n",p->value);

                     ASTprint(level+1, p->s1);
                     break;
        
        case A_IDENTIFIER: 
                      if(p->s1 == NULL){
                        printf("IDENTIFIER %s \n", p->name);
                        ASTprint(level+1, p->s1);
                      }
                      else {
                        printf("IDENTIFIER %s \n", p->name);
                        for(i=0;i<level;i++) printf(" ");
                        printf("array reference [ \n");
                        ASTprint(level+1, p->s1);
                        for(i=0;i<level;i++)
                          printf(" ");
                        printf("] end array \n");
                      }
                      break;
                      
        default: fprintf(stderr, "WARNING: UNKNOWN type in ASTprint\n");


       }
       ASTprint(level, p->next);
     }

}



/* dummy main program so I can compile for syntax error independently   
main()
{
}
/* */
