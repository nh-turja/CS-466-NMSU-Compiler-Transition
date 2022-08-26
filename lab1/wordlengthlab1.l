     /*  This lex routine uses a counting array to match alphabeticstrings 
         and make a frequency count.
  
         The real item to notice is that yywrap() is called at EOF and then is run
         to do what we need to do.   yywrap() returns true when we have a successful 
         end to the program.  We may want to return false (0) if we want to lexing process 
         to fail 

        Shaun Cooper
        January 2015

        Name: Nazmul Haque Turja (Aggie ID: 800779609)
        Lab Title: Compilers and Automata Lab
        Date: 1/19/2022

        I added [0-9]+ to find out the patterns for number count and initialize a variable num to count the numbers. 
        I also printed all the number count at the end part of the main() function  

        Modified LEX Routine: [0-9]+ {num++;}
        
         

   */
	int lgths[100];
     int num=0;
%%
[a-zA-Z]+	{lgths[yyleng]++;}
[0-9]+ {num++;}
.	|
\n	;

%%
yywrap()
{
	int i;
	printf("Length  No. words\n");
	for (i=1; i<100; i++) {
		if (lgths[i] > 0) {
			printf("%5d%10d\n",i,lgths[i]);
		}
	}
     printf("Count of Numbers: \n");
     printf("%5d \n", num);
	return(1);
}

main()
{  yylex();

}
