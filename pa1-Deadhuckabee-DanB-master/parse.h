/*  parse.h
    Dan Blanchette
    Date:9 - 4 - 2020
*/

#ifndef PARSE_H
#define PARSE_H

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int makearg(char *s, char ***args);
int wCount(char *s);
void displayS(char *s, char ***args);


#endif