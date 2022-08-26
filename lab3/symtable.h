#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

#ifndef SYMBTAB
#define SYMBTAB

struct SymbTab *Insert(char *symbol, int address);
void Display();
void Delete(char *symbol);
struct Symbtab *Search(char *symbol);
void Modify();
struct SymbTab{
    char* symbol;
    int addr;
    struct SymbTab *next;
};
#endif