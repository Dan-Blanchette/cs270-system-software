/**
 * @file tail.h
 * @author Dan Blanchette
 * @brief 
 * @version 0.1
 * @date 2020-10-05
 * 
 * @Acknowledgements GEEKS FOR GEEKS : https://www.geeksforgeeks.org/implement-your-own-tail-read-last-n-lines-of-a-huge-file/
 * 
 */

#ifndef TAIL_H
#define TAIL_H

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <errno.h>

#define SIZE 100 


/**
 * @brief a function that will return the last 10 lines of a file
 * 
 * @param fd 
 * @param lines 
 */

void tail(FILE *fp, int lines);
 void tail2(FILE *fp, int lines,  int numLines);



#endif