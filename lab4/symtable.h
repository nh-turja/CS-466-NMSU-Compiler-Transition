/*
Name: Nazmul Haque Turja
Aggie ID: 800779609
Date: 16 February, 2022
*/

#ifndef SYMTABLE
#define SYMTABLE

void Insert(char *, int);
//void Display();
//void Delete();
int Search(char *);
//void Modify();
int fetch(char *);
struct SymbTab{
	char * symbol;
	int addr;
	struct SymbTab *next;
};
struct SymbTab *first,*last;

#endif