/*   Emitter Header File
  
   #Name: Nazmul Haque Turja (Aggie ID: 800779609)
   #Date: 04/28/2022
   #Lab: Compilers and Automata


*/
#ifndef EMIT_H
#define EMIT_H

//prototype info
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

#include "ast.h"
#include "symtable.h"

#define WSIZE 4 // # of bytes in word
#define LOGWSIZE 2 // # of shifts to get to WSIZE

char *currentFunction;

void emit(char *label, char *command, char *comment, FILE *fp);
void emit_ast(ASTnode *p, FILE *fp);
void emit_header(ASTnode *p, FILE *fp);
void emit_expr(ASTnode *p, FILE *fp);
void emit_ident(ASTnode *p, FILE *fp);
void emit_function(ASTnode *p, FILE *fp);
void evaluate_args(ASTnode *p, FILE *fp);
void emit_args_to_params(ASTnode *arg, ASTnode *param, int functionSize, FILE *fp);
void emit_return(ASTnode *p, FILE *fp);


#endif
