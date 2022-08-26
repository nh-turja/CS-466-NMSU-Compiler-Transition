/*
    Name: Nazmul Haque Turja (Aggie ID: 800779609)
    Lab Title: Compilers and Automata Lab
    Date: 2/2/2022

    Pulled the code from the site: http://forgetcode.com/C/101-Symbol-table
    The changes that I made: 
    1. Removed all the occurences of "label" from the code and properly indented the code
    2. Changed "symbol[10] to char *symbol"
    3. Changed the prototype of the Insert(), Search() and Delete() Function: 
        i. struct SymbTab *Insert(char *symbol, int address);
        ii. void Delete(char *symbol);
        iii. struct Symbtab *Search(char *symbol);
    4. Used strdup() to copy the string to pointer
    5. Created symbtable.h header file and properly defined it according to instructions
    
*/
#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include "symtable.h"

int size=0;

struct SymbTab *first,*last; 

void main()
{
    int op,addr; //Initializing for the address of the inserted symbols
    struct SymbTab *y;
    char sym[100]; //Initializing for the symbols of the symbol table
do
{
    printf("\n\tSYMBOL TABLE IMPLEMENTATION\n");
    printf("\n\t1.INSERT\n\t2.DISPLAY\n\t3.DELETE\n\t4.SEARCH\n\t5.MODIFY\n\t6.END\n");
    printf("\n\tEnter your option : ");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            printf("\n\tEnter the symbol to be inserted : ");
            scanf("%s",sym);
            printf("\n\tEnter the address : ");
            scanf("%d",&addr);
            y=Search(sym);
            if(y!=NULL)
                printf("\n\tError: The symbol is present in the symbol table\n");
            else
                Insert(sym,addr);
                break;
            break;
        case 2:
            Display();
            break;
        case 3:
            printf("\n\tEnter the symbol to be deleted : ");
            scanf("%s",sym);
            y=Search(sym);
            if(y==NULL)
                printf("\n\tError: The symbol is not present in the symbol table\n");
            else
                Delete(sym);
                break;
            break;
        case 4:
            printf("\n\tEnter the symbol to be searched : ");
            scanf("%s",sym);
            y=Search(sym);
            printf("\n\tSearch Result:");
            if(y!=NULL)
                printf("\n\tThe symbol is present in the symbol table\n");
            else
                printf("\n\tThe symbol is not present in the symbol table\n");
                break;
            case 5:
                Modify();
                break;
            case 6:
                exit(0);
    }
}
while(op<6);

}  /* and of main */
/*
Pre-condition: PTR to character string
Post-condition: PTR to structure new symbol
*/
struct SymbTab * Insert(char *symbol, int address)
{
    struct SymbTab *p;
    p=malloc(sizeof(struct SymbTab));
    p->symbol = strdup(symbol);
    p->addr = address;
    p->next=NULL;
    if(size==0)
    {
        first=p;
        last=p;
    }
    else
    {
        last->next=p;
        last=p;
    }
    size++;
    
    printf("\n\tSymbol inserted\n");
    return p;
}


/*
    Displays the symbol table
*/
void Display()
{
    int i;
    struct SymbTab *p;
    p=first;
    printf("\n\tSYMBOL\t\tADDRESS\n");
    for(i=0;i<size;i++)
    {
        printf("\t%s\t\t%d\n",p->symbol,p->addr);
        p=p->next;
    }
}


/*
Pre-condition: PTR to character string
Post-condition: PTR to matching structure or NULL
*/

struct Symbtab *Search(char *symbol)
{
    int i;
    struct SymbTab *p;
    p=first;

    for(i=0;i<size;i++)
    {
        if(strcmp(p->symbol,symbol)==0)
            return p;
        p=p->next;
    }
return NULL;
}

void Modify()
{
    char l[10],nl[10];
    int add,choice,i,s;
    struct SymbTab *p;
    p=first;
    printf("\n\tWhat do you want to modify?\n");
    printf("\n\t1.Only the symbol\n\t2.Only the address\n\t3.Both the symbol and address\n");
    printf("\tEnter your choice : ");
    scanf("%d",&choice);

switch(choice)
{
    case 1:
        printf("\n\tEnter the old symbol : ");
        scanf("%s",l);
        s=Search(l);
        if(s==0)
            printf("\n\tSymbol not found\n");
        else
        {
            printf("\n\tEnter the new symbol : ");
            scanf("%s",nl);
            for(i=0;i<size;i++)
            {
                if(strcmp(p->symbol,l)==0)
                strcpy(p->symbol,nl);
                p=p->next;
            }
            printf("\n\tAfter Modification:\n");
            Display();
        }
        break;
    case 2:
        printf("\n\tEnter the symbol where the address is to be modified : ");
        scanf("%s",l);
        s=Search(l);
        if(s==0)
            printf("\n\tSymbol not found\n");
        else
        {
            printf("\n\tEnter the new address : ");
            scanf("%d",&add);
            for(i=0;i<size;i++)
            {
                if(strcmp(p->symbol,l)==0)
                p->addr=add;
                p=p->next;
            }
            printf("\n\tAfter Modification:\n");
            Display();
            }
        break;
    case 3:
        printf("\n\tEnter the old symbol : ");
        scanf("%s",l);
        s=Search(l);
        if(s==0)
            printf("\n\tSymbol not found\n");
        else
        {
            printf("\n\tEnter the new symbol : ");
            scanf("%s",nl);
            printf("\n\tEnter the new address : ");
            scanf("%d",&add);
            for(i=0;i<size;i++)
            {
                if(strcmp(p->symbol,l)==0)
                {
                    strcpy(p->symbol,nl);
                    p->addr=add;
                }
                p=p->next;
            }
            printf("\n\tAfter Modification:\n");
            Display();
        }
        break;
    }
}

/*
Pre-condition: Function had no input parameters
Post-condition: Function takes the input as a symbol
*/
void Delete(char *symbol)
{
    struct SymbTab *p,*q;
    p=malloc(sizeof(struct SymbTab)); //allocating memory
    q=malloc(sizeof(struct SymbTab)); //allocating memory
    
    p=first;
    
    if(strcmp(first->symbol,symbol)==0)
        first=first->next;
    else if(strcmp(last->symbol,symbol)==0)
    {
        q=p->next;
        while(strcmp(q->symbol,symbol)!=0)
        {
            p=p->next;
            q=q->next;
        }
        p->next=NULL;
        last=p;
    }
    else
    {
        q=p->next;
        while(strcmp(q->symbol,symbol)!=0)
        {
            p=p->next;
            q=q->next;
        }
        p->next=q->next;
        }
    size--;
    printf("\n\tAfter Deletion:\n");
    Display();
    free(p); //free the allocated memory
    free(q); //free the allocated memory
}