/*   Abstract syntax tree code


   Header file   
   #Name: Nazmul Haque Turja (Aggie ID: 800779609)
   #Date: 03/23/2022
   #Lab: Compilers and Automata

   Changes made in this file: 
   1. Added necessary ASTtype and operators
   2. Made a struct datatype ASTnode for creating nodes

*/
#ifndef AST_H
#define AST_H

#include<stdio.h>
#include<malloc.h>
#include<ctype.h>


extern int mydebug;

/* define the enumerated types for the AST.  THis is used to tell us what 
sort of production rule we came across */

/* enum which allows us to distinguish which node type
*/

/* This is a partial list of Node types for the ASTNode*/
enum ASTtype {
   A_PROGRAM,
   A_VARDEC,
   A_FUNDEC,
   A_PARAM,
   A_INTTYPE,
   A_IDENTIFIER,
   A_BLOCK,
   A_EXPRSTMT,
   A_ASSIGNSTMT,
   A_IFSTMT,
   A_WHILESTMT,
   A_READSTMT,
   A_RETURNSTMT,
   A_WRITESTMT,
   A_EXPR,
   A_CALL,
   A_NUMBER,
   A_ARGLIST
};


enum OPERATORS {
   A_PLUS,
   A_MINUS,
   A_TIMES,
   A_DIV,
   A_MOD,
   A_INTDEC,
   A_VOIDDEC,
   A_BOOLDEC,
   A_LESSTHANEQUAL,
   A_LESSTHAN,
   A_GREATERTHANEQUAL,
   A_GREATERTHAN,
   A_EQUAL,
   A_NOTEQUAL, 
   A_AND,
   A_OR,
   A_NOT
};

/* define a type AST node which will hold pointers to AST structs that will
   allow us to represent the parsed code 
*/
typedef struct ASTnodetype
{
     enum ASTtype type;
     enum OPERATORS operator;
     char * name;
     int value;
     struct ASTnodetype *next; //connector
     struct ASTnodetype *s1,*s2 ; /* used for holding IF and WHILE components -- not very descriptive */
} ASTnode;


/* uses malloc to create an ASTnode and passes back the heap address of the newley created node */
ASTnode *ASTCreateNode(enum ASTtype my_type);


void ASTattachnext(ASTnode *p,ASTnode *q);

ASTnode *program;

/*  Print out the abstract syntax tree */
void ASTprint(int level,ASTnode *p);

#endif // of AST_H
