/*
*  Lex Program
* Nazmul Haque Turja
* 
* Aggie ID: 800779609
* Compilers and Automata Lab 
* Date: 23 February, 2022
 	Summary of work that I did: 
	1)	Returned all boldface elements as T_(TOKEN -> element name)
	2)	Followed Extended BNF grammar for C-Algol and changed LEX and YACC codes accordingly
*/
%{

int mydebug=0;
int lineno=1;
#include "y.tab.h"

%}

letter 		[a-zA-Z][a-zA-Z]*
num 		[0-9][0-9]*
id 			{letter}({letter}|{num})*

/*Begin Rules*/
%%

int 		{if (mydebug) fprintf(stderr,"int found\n"); 
            							    return(T_INT);}
void		{if (mydebug) fprintf(stderr,"void found\n"); 
            							    return(T_VOID);}
if 			{if (mydebug) fprintf(stderr,"if found\n"); 
            							    return(T_IF);}
else 		{if (mydebug) fprintf(stderr,"else found\n"); 
            							    return(T_ELSE);}	
while	 	{if (mydebug) fprintf(stderr,"while found\n"); 
            							    return(T_WHILE);}
return		{if (mydebug) fprintf(stderr,"return found\n"); 
            							    return(T_RETURN);}
read		{if (mydebug) fprintf(stderr,"read found\n"); 
            							    return(T_READ);}
write		{if (mydebug) fprintf(stderr,"write found\n"); 
            							    return(T_WRITE);}
begin		{if (mydebug) fprintf(stderr,"begin found\n"); 
            							    return(T_BEGIN);}
end			{if (mydebug) fprintf(stderr,"end found\n"); 
            							    return(T_END);}
do			{if (mydebug) fprintf(stderr,"do found\n"); 
            							    return(T_DO);}
true			{if (mydebug) fprintf(stderr,"true found\n"); 
            							    return(T_TRUE);}
false			{if (mydebug) fprintf(stderr,"do found\n"); 
            							    return(T_FALSE);}
not			{if (mydebug) fprintf(stderr,"do found\n"); 
            							    return(T_NOT);}
and			{if (mydebug) fprintf(stderr,"and found\n"); 
            							    return(T_AND);}
or			{if (mydebug) fprintf(stderr,"or found\n"); 
            							    return(T_OR);}
then		{if (mydebug) fprintf(stderr,"then found\n"); 
            							    return(T_THEN);}
of			{if (mydebug) fprintf(stderr,"of found\n"); 
            							    return(T_OF);}
boolean		{if (mydebug) fprintf(stderr,"boolean found\n"); 
            							    return(T_BOOLEAN);}
[<][\=]			{if (mydebug) fprintf(stderr,"LE found\n"); 
            							    return(T_LE);}

[>][\=]			{if (mydebug) fprintf(stderr,"GE found\n"); 
            							    return(T_GE);}

[\=][\=]			{if (mydebug) fprintf(stderr,"EQ found\n"); 
            							    return(T_EQ);}

[\!][\=]			{if (mydebug) fprintf(stderr,"LE found\n"); 
            							    return(T_NE);}

[<]			{if (mydebug) fprintf(stderr,"LT found\n"); 
            							    return(T_LT);}

[>]			{if (mydebug) fprintf(stderr,"GT found\n"); 
            							    return(T_GT);}

                                            
{id}		{if (mydebug) fprintf(stderr,"id found\n"); 
              yylval.string=strdup(yytext);return(T_ID);}

{num}		{if (mydebug) fprintf(stderr,"num found\n"); 
              yylval.value=atoi((const char *)yytext); return(T_NUM);}	


[ \t]		{}
[;]		        { return (*yytext);}
[<>=()\-+*/%&\[\]|;{},] 	{ return (*yytext);}
\n 			{lineno++;} 
                       

%%
/*End Rules*/

int yywrap(void)
{ return 1;}