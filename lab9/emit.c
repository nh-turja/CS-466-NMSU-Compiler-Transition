/*
  Lab9, "Emiter" file for MIPS generation 
  Nazmul Haque Turja
  April 28, 2022
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "emit.h"
#include "ast.h"


//function prototypes
void emit_function_head(ASTnode *p, FILE *fp);
void emit_function_tail(ASTnode *p, FILE *fp);

void emit_global_strings(ASTnode *p, FILE *fp);
void emit_global_variables(ASTnode *p, FILE *fp);


//helper function
//PRE: strings to print formatted
//POST: formatted output to MIPS
void emit(char *label, char *command, char *comment, FILE *fp){

	if(strcmp (label, "") == 0){
		if (strcmp (comment, "") == 0) 
			//label and comment are empty
			fprintf(fp, "\t%s\n",command);
		else
			//label empty, comment full
			fprintf(fp, "\t%s\t#%s\n",command,comment);	
	}
	else{
			//label has some contents
		if(strcmp(comment, "")==0)
			//label full, comment empty
			fprintf(fp, "%s:\t%s\n", label, command);
		else
			//label and comment full
			fprintf(fp, "%s:\t%s\t#%s\n", label, command, comment);
	}


}



void emit_ast(ASTnode *p, FILE *fp){
	
	if (p == NULL) 
		return;
	
	char *L1, *L2;

	switch (p->type) {

		case A_VARDEC :  
			emit_ast(p->next, fp);
			break;

		case A_FUNDEC :
			emit_function_head(p,fp);
			emit_ast(p->s2, fp);
			emit_function_tail(p,fp);
			emit_ast(p->next, fp);
			break;

		case A_BLOCK:
			emit_ast(p->s1, fp);
			emit_ast(p->s2,fp);
			break;
		
		case A_PARAM:
			break;
		
		case A_EXPRSTMT: 
			if(p->s1 != NULL){
				char s[100];
				switch(p->s1->type){
					case A_NUMBER:
						fprintf(fp,"\tli $a0 %d\t\t#get Identifier offset\n",p->s1->value);
						break;
					case A_IDENTIFIER: 
						emit_ident(p->s1,fp);
						fprintf(fp,"\tlw $a0 ($a0)\t\t#expression identifier\n");
						break;
					case A_EXPR:
						emit_expr(p->s1,fp);
						fprintf(fp, "\tlw $a0 %d(sp)\t\t#Expressionstmt expr\n",p->s1->symbol->offset*WSIZE);
						break;
					case A_CALL:
						emit_function_head(p->s1,fp);
						emit_function_tail(p->s1,fp);
						break;
					default:
						fprintf(fp, "\tBAD EXPRSTMT\n");
						break;
				}

				fprintf(fp, "sw $a0, %d($sp)\t\t#store RHS value in memory\n",p->symbol->offset*WSIZE);
						
			}
			break;
		
		case A_ASSIGNSTMT: 
			emit_ast(p->s2,fp);
			emit_ident(p->s1,fp);
			fprintf(fp,"\tlw $a0  %d($sp)\t\t#fetch LHS of expression from memory\n",p->s2->symbol->offset*WSIZE);
			break;

		case A_IFSTMT:

			L1 = CreateLabel();
			L2 = CreateLabel();
			switch(p->s1->type){
				case A_NUMBER:
					fprintf(fp,"\tli $a0 %d\t\t#If value loaded\n",p->s1->value);
					break;
				case A_IDENTIFIER: 
					emit_ident(p->s1,fp);
					fprintf(fp,"\tlw $a0 ($a0)\t\t#If expression identifier\n");
					break;
				case A_EXPR:
					emit_expr(p->s1,fp);
					fprintf(fp, "\tlw $a0 %d(sp)\t\t#Expressionstmt expr\n",p->s1->symbol->offset*WSIZE);
					break;
				case A_CALL:
					emit_function_head(p->s1,fp);
					emit_function_tail(p->s1,fp);
					break;
				default:
					fprintf(fp, "\tBAD IFSTMT\n");
					break;

			}

			fprintf(fp,"\tbeq $a0 $0 %s\t\t#If compare and branch to else",L1);
			
			emit_ast(p->s2->s1,fp);

			fprintf(fp,"\tj\t%s\t\t#If s2->s1 end\n",L2);
			fprintf(fp, "\n %s:\t\t#Else Target\n",L1);

			emit_ast(p->s2->s2,fp);
			fprintf(fp, "\n%s:\t\t#IF bottom target\n",L2);

			break;
		
		case A_WHILESTMT: 
			L1 = CreateLabel();
			L2 = CreateLabel();

			fprintf(fp, "\n%s: \t\t#WHILE Top target",L1);

			switch(p->s1->type){
				case A_NUMBER:
					fprintf(fp,"\tli $a0 %d\t\t#while value loaded\n",p->s1->value);
					break;
				case A_IDENTIFIER: 
					emit_ident(p->s1,fp);
					fprintf(fp,"\tlw $a0 ($a0)\t\t#while expression identifier\n");
					break;
				case A_EXPR:
					emit_expr(p->s1,fp);
					fprintf(fp, "\tlw $a0 %d(sp)\t\t#while expression expr\n",p->s1->symbol->offset*WSIZE);
					break;
				case A_CALL:
					emit_function_head(p->s1,fp);
					emit_function_tail(p->s1,fp);
					break;
				default:
					fprintf(fp, "\tBAD WHILE\n");
					break;

			}
					

			fprintf(fp,"\tbeq $a0 $0 %s\t\t#WHILE branch out",L2);
			
			emit_ast(p->s2,fp);

			fprintf(fp,"\tj\t%s\t\t#WHILE jump back\n",L1);
			fprintf(fp, "\n%s:\t\t#WHILE end target\n",L2);
			break;

		case A_RETURNSTMT:
			emit_return(p,fp);
			break;
		
		case A_READSTMT: 
			emit_ident(p->s1,fp);
			fprintf(fp,"\tsw $v0 ($a0)\t\t# end of read stmt\n");
			break;

		case A_WRITESTMT:
			if(p->s1 != NULL){
				switch(p->s1->type){
					case A_NUMBER:
					fprintf(fp,"\tli $a0 %d\t\t#load immediate value\n",p->s1->value);
					break;
					case A_IDENTIFIER: 
						emit_ident(p->s1,fp);
						fprintf(fp,"\tlw $a0 ($a0)\t\t#load immediate value\n");
						break;
					case A_EXPR:
						emit_expr(p->s1,fp);
						fprintf(fp, "\tlw $a0 %d(sp)\t\t#load expr value from expr mem\n",p->s1->symbol->offset*WSIZE);
						break;
					case A_CALL:
						emit_function_head(p->s1,fp);
						emit_function_tail(p->s1,fp);
						fprintf(fp,"\tsw $a1 ($a0)\t\t# store function return");
						break;
					default:
						fprintf(fp, "\tBAD WRITESTMT\n");
						break;
				}

				fprintf(fp,"\tli $v0 1\t\t#set up write call for integers\n");
				fprintf(fp,"\tsyscall\n");

				fprintf(fp,"\tli $v0, 4\t\t#print NEWLINE\n");
				fprintf(fp,"\tla $a0, _NL\t\t#print NEWLINE string location\n");
				fprintf(fp,"\tsyscall\n");		
			}
			if(p->name != NULL){
				fprintf(fp,"\tli $v0 4\t\t#set up write call for strings\n");
				fprintf(fp,"\tla $a0, %s\t\t#print NEWLINE string location\n",p->label);
				fprintf(fp,"\tsyscall\n");

				fprintf(fp,"\tli $v0, 4\t\t#print NEWLINE\n");
				fprintf(fp,"\tla $a0, _NL\t\t#print NEWLINE string location\n");
				fprintf(fp,"\tsyscall\n");	
			}	
			
			break;

		case A_EXPR: 
			fprintf(fp,"\t#EXPR\n");
			break;
		
		case A_IDENTIFIER:
			fprintf(fp,"\t#IDENT\n");
			break;
		
		case A_NUMBER:
			fprintf(fp,"\t#NUMBER\n");
			break;
		
		case A_CALL:
			emit_function_head(p->s1,fp);
			emit_function_tail(p->s1,fp);
			break;
		
		case A_ARGLIST:
			fprintf(fp,"\t#ARG\n");
			break;

		default: fprintf(fp, "\t;unknown type in emit_ast\n");

		}//end switch

		emit_ast(p->next, fp);

	
}//end emit_ast()


//PRE: PTR to A_FUNDEC
//POST: MIPS Code in fp to handle the activation record carve out
void emit_function_head (ASTnode *p, FILE *fp){
	char s[100];
	//all functions have to have a LABEL
	emit(p->name, "","Start of function", fp);
	//we need four lines of code after

	//we also need to adjust the stack pointer
	sprintf(s, "subu $t0 $sp %d ", p->symbol->mysize * WSIZE);
	emit("", s, "Set up $t0 to be the new spot for Stack Pointer", fp);
	emit("", "sw $ra ($t0)", "Store the return address", fp);
	emit("", "sw $sp 4($t0)", "Store the old stack pointer", fp);
	emit("", "move $sp $t0", "Set the stack pointer to the new value", fp);
	emit("","","",fp);
}// end emit_function_head

//PRE: PTR to A_FUNDEC
//POST: MIPS code in fp to handle the activation record carve out
void emit_function_tail(ASTnode *p, FILE *fp){
	emit("", "li $v0 0", "return NULL zero(0)", fp);
	emit("", "lw $ra ($sp)", "reset return address", fp);
	emit("", "lw $sp 4($sp)", "reset stack pointer", fp);
	emit("","","",fp);
	if(strcmp(p->name,"main")==0){
		emit("", "li $v0, 10", "Main function ends", fp);
		emit("", "syscall", "MAIN FUNCTION EXITS", fp);	
	}
}

//PRE: PTR to emit_header
//POST: MIPS code for emitting header infos
void emit_header (ASTnode *p, FILE *fp){
	fprintf(fp, ".data # Start of the DATA section, strings first\n\n");
	emit_global_strings(program, fp);
	fprintf(fp, "_NL: .asciiz \"\\n \"# New line\n");
	fprintf(fp, ".align 2 # start all of global variable aligned\n\n");
	emit_global_variables(p, fp);

	fprintf(fp, "\n.text\n");
	fprintf(fp, "\n.globl main\n\n\n ");
	fprintf(fp, "\t.text\n\n");
} //end emit_header


//Pre: PTR to global strings
//Post: .data and start of .text segment for AST in file fp
void emit_global_strings(ASTnode *p, FILE *fp){
	if(p==NULL)
		return;
	if((p->type == A_WRITESTMT) && (p->name != NULL)){
		fprintf(fp, "%s:\t.asciiz\t%s\t\t#global string\n",p->label,p->name);
	}
	emit_global_strings(p->s1, fp);
	emit_global_strings(p->s2, fp);
	emit_global_strings(p->next, fp);
}//end emit_global_strings




//Pre: PTR to ASTnode
//Post: .data and start of .text segment for AST in file fp
void emit_global_variables(ASTnode *p, FILE *fp){
	if (p==NULL)
		return;
	if((p->type == A_VARDEC) && (p->symbol->level == 0)){
		fprintf(fp, "%s:\t.space %d\t\t# define a global variable\n", p->name, (p->symbol->mysize * WSIZE));
	}
	emit_global_variables(p->s1, fp);
	emit_global_variables(p->next, fp);
}//end emit_global_variables

//PRE: PTR to emit_expr
//POST: MIPS code for emitting expression
void emit_expr(ASTnode *p, FILE *fp){

	switch(p->s1->type){

		case A_NUMBER:
			fprintf(fp,"\tli $a0 %d\t\t#Get Identifier Offset\n",p->s1->value);
			break;

		case A_IDENTIFIER: 
			emit_ident(p->s1,fp);
			fprintf(fp,"\tlw $a0 ($a0)\t\t#LHS expression is identifier\n");
			break;
		case A_EXPR:
			emit_expr(p->s1,fp);
			fprintf(fp, "\tlw $a0 %d(sp)\t\t#fetch LHS of expression from memory\n",p->s1->symbol->offset * WSIZE);
			break;

		case A_CALL:
			emit_function_head(p->s1,fp);
			emit_function_tail(p->s1,fp);
			fprintf(fp,"\tsw $a1 ($a0)\t\t# store function return\n");
			break;

		default:
			fprintf(fp, "\tBAD Left Side\n");
			break;
	}//end left switch

//store
fprintf(fp, "\tsw $a0 %d(sp)\t\t#store LHS of expression into memory\n",p->symbol->offset * WSIZE);

//right side
switch(p->s2->type){

		case A_NUMBER:
			fprintf(fp,"\tli $a0 %d\t\t#Get Identifier Offset\n",p->s2->value);
			break;

		case A_IDENTIFIER: 
			emit_ident(p->s2,fp);
			fprintf(fp,"\tlw $a0 ($a0)\t\t#LHS expression is identifier\n");
			break;

		case A_EXPR:
			emit_expr(p->s2,fp);
			fprintf(fp, "\tlw $a0 %d(sp)\t\t#fetch LHS of expression from memory\n",p->s2->symbol->offset * WSIZE);
			break;

		case A_CALL:
			emit_function_head(p->s2,fp);
			emit_function_tail(p->s2,fp);
			fprintf(fp,"\tsw $a1 ($a0)\t\t# store function return\n");
			break;

		default:
			fprintf(fp, "\tBAD Right Side\n");
			break;
	}//end left switch

//store
fprintf(fp, "\tsw $a0 %d(sp)\t\t#store RHS of expression into memory\n",p->symbol->offset * WSIZE);

//operators
switch(p->operator){
	case A_PLUS: 
		fprintf(fp,"\tadd $a0, $a0, $a1\t\t#EXPR ADD\n");
		break;

	case A_MINUS: 
		fprintf(fp,"\tsub $a0, $a0, $a1\t\t#EXPR SUB\n");
		break;
	
	case A_TIMES: 
		fprintf(fp,"\tmult $a0 $a1\t\t#EXPR MULT\n");
		fprintf(fp,"\tmflo $a0\t\t#EXPR MULT\n");				
		break;
	
	case A_DIV: 
		fprintf(fp,"\tdiv $a0 $a1\t\t#EXPR DIV\n");
		fprintf(fp,"\tmflo $a0\t\t#EXPR DIV\n");				
		break;
	
	// EQUAL and Not-equals etc....

	case A_LESSTHANEQUAL:
		emit("","sle $a0,$a0,$a1","branch instr less than equal",fp);
		break;

	case A_LESSTHAN:
		emit("","slt $a0,$a0,$a1","branch instr less than",fp);
		break;
	
	case A_GREATERTHAN:
		emit("","sgt $a0,$a0,$a1","branch instr greater than",fp);
		break;
	
	A_GREATERTHANEQUAL:
		emit("","sge $a0,$a0,$a1","branch instr greater than equal",fp);
		break;
	
	case A_EQUAL:
			emit("","seq $a0,$a0,$a1","branch instr equal",fp);
			break;

	case A_NOTEQUAL:
			emit("","sne $a0,$a0,$a1","branch instr not equal",fp);
			break;

	default:
		fprintf(fp,"\tBad Operator\n");
		break; 

}

//store
fprintf(fp, "\tsw $a0 %d(sp)\t\t#store $a0\n",p->symbol->offset * WSIZE);


}

//PRE: PTR to emit_ident
//POST: MIPS code for emitting identifiers
void emit_ident(ASTnode *p, FILE *fp){
	if(p->s1 != NULL){
		switch(p->s1->type){
			case A_NUMBER:
				fprintf(fp,"\tli $a1 %d\t\t#Assign value to a1\n",p->s1->value);
				break;

			case A_IDENTIFIER: 
				emit_ident(p->s1,fp);
				fprintf(fp,"\tli $a0 8\t\t#get Identifier offset\n");
				fprintf(fp,"\tadd $a0,$a0,$sp\t\t# we have direct reference to memory \n");
				fprintf(fp,"\tadd $a0, $a0, $t3\t\t# move add on $t3 as this is an array reference \n");		
				break;

			case A_EXPR:
				emit_expr(p->s1,fp);
				fprintf(fp, "\tlw $a0 %d(sp)\t\t#fetch Array value from SP to $a0\n",p->s1->symbol->offset * WSIZE);
				fprintf(fp,"\tadd $a0, $a0, $t3\t\t# move add on $t3 as this is an array reference \n");
				break;

			case A_CALL:
				emit_function_head(p->s1,fp);
				emit_function_tail(p->s1,fp);
				fprintf(fp,"\tsw $a1 ($a0)\t\t# store function return\n");
				fprintf(fp,"\tadd $a1, $a1, $t3\t\t# move add on $t3 as this is an array reference \n");
				break;

			default:
				fprintf(fp, "\tBAD Left Side\n");
				break;
		}//end_switch

	}//end_if

	if(p->symbol->level == 0){
		fprintf(fp,"\tlw $a0 %s \t\t#Put address into $a0\n", p->name);
	}
	else{
		fprintf(fp,"\tli $a0 %d \t\t# get Identifier offset\n", p->symbol->offset * WSIZE);
		fprintf(fp,"\tadd $a0,$a0,$sp\t\t# we have direct reference to memory\n");
	}

	if(p->s1 != NULL)
		fprintf(fp,"\tadd $a0,$a0,$sp\t\t# Add offset and stack pointer\n");
}//end emit_ident


//PRE: PTR to emit_function
//POST: MIPS code for emitting functions
void emit_function(ASTnode *p, FILE *fp){
	//gets value from arg
	evaluate_args(p->s1,fp);
	//move args of function call to params of function
	emit_args_to_params(p->s1, p->symbol->fparms, p->symbol->mysize,fp);
	emit("","","about to call a function, set up each parameter in the new activation record",fp);
	fprintf(fp,"\tjal %s\t\t#jump and link to function",p->name);
}

//PRE: PTR to evaluate_args
//POST: MIPS code for evaluating args
void evaluate_args(ASTnode *p, FILE *fp){
	if(p==NULL){
		return;
	}
	switch(p->s1->type){
		case A_NUMBER:
			fprintf(fp,"\tli $a0 %d\t\t#Arg Number\n",p->s1->value);
			break;

		case A_IDENTIFIER: 
			emit_ident(p->s1,fp);
			fprintf(fp,"\tlw $a0 ($a0)\t\t#Arg identifier value\n");
			break;

		case A_EXPR:
			emit_expr(p->s1,fp);
			fprintf(fp, "\tlw $a0 %d(sp)\t\t#Arg Expression\n",p->s1->symbol->offset * WSIZE);
			break;

		case A_CALL:
			emit_function_head(p->s1,fp);
			emit_function_tail(p->s1,fp);
			break;

		default:
			fprintf(fp, "\tBAD Arg Type\n");
			break;
	}//end switch

	fprintf(fp,"\t sw $a0 %d(sp)\t\t#Store arg into arglist offset\n",p->symbol->offset * WSIZE);
	evaluate_args(p->next, fp);
}//end evaluate_args

//moves all args of function call to params of function

//PRE: PTR to emit_args_to_params
//POST: MIPS code for args and params
void emit_args_to_params(ASTnode *arg, ASTnode *param, int functionSize, FILE *fp){
	fprintf(fp, "\tsubu $t0 $sp %d\t\t#set up $t0 to be the new spot for SP\n",(functionSize+1)*WSIZE);

	while(param != NULL){
		//copy arg
		fprintf(fp, "\tsw $a0 %d($sp)\t\t#temporarily store arg contents\n",arg->symbol->offset * WSIZE);
		//mov arg to param
		fprintf(fp, "\tsw %d($t0) $a0\t\t#copy contents of rax into param\n",param->symbol->offset * WSIZE);	
		arg = arg->next;
		param = param->next;
	}//end while still params
	
}//end emit_args_to_params

//PRE: PTR to return
//POST: MIPS code for return statements
void emit_return(ASTnode *p, FILE *fp){
	if((p != NULL) && (p->s1 != NULL)){

		switch(p->s1->type){

			case A_NUMBER:
				fprintf(fp,"\tli $a0 %d\t\t#Return Number\n",p->s1->value);
				break;

			case A_IDENTIFIER: 
				emit_ident(p->s1,fp);
				fprintf(fp,"\tlw $a0 ($a0)\t\t#Return Identifier Value\n");
				break;

			case A_EXPR:
				emit_expr(p->s1,fp);
				fprintf(fp, "\tlw $a0 %d(sp)\t\t#Return value of expression\n",p->s1->symbol->offset*WSIZE);
				break;
			case A_CALL:
				emit_function_head(p->s1,fp);
				emit_function_tail(p->s1,fp);
				break;
			default:
				fprintf(fp, "\tBAD Return\n");
				break;
		}//end return switch
	}//end if has something to return
	else{
		fprintf(fp,"\tli $v0 0\t\t#return NULL zero (0)\n");
	}
	fprintf(fp,"\tlw $ra ($sp)\t\t# reset return address\n");
	fprintf(fp,"\tlw $sp 4($sp)\t\t# reset stack pointer\n");	
	if(strcmp(p->name,"main")==0){
		fprintf(fp,"\tli $v0, 10\t\t#Main function ends\n");
		fprintf(fp,"\tsyscall\t\t#MAIN FUNCTION EXITS\n");
	}
	 	
}