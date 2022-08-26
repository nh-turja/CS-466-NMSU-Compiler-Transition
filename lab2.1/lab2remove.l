         /* simple lex program which removes comments from a source program
            The main key is that a variable "comment" is set when the start of a comment
            is seen and then unset when the ending set is seen.  It is possible to have
            two starts closed by on end.

            Shaun Cooper
            January 2015

          Name: Nazmul Haque Turja (Aggie ID: 800779609)
          Lab Title: Compilers and Automata Lab
          Date: 1/26/2022
         */
        int comment = 0;
        int debug=1;  /* prints out debug statements if desired */
        int linenum = 1; /* variable declared to count the line numbers  */ 
%%
"/*"	{
	if (comment && debug) fprintf(stderr,
		" >>>>>>>> line %d: Possible Nested comment <<<<<<<<<<\n",linenum);
	comment = 1;
	}

\n {linenum++; printf("\n");} /* \n is used to find the increment of the linenum */ 

"*/"	{
          if (!comment) printf("%s",yytext); /*print out if it is not in a comment */
  	  comment = 0;
	}
.       { if (!comment) printf("%s",yytext);}

%%

int yywrap(void)
{ return 1;
}

main()
{
  yylex();
  
}

