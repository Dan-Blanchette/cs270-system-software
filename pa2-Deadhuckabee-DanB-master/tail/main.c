/**
 * @file main.c
 * @author Dan Blanchette
 * @brief 
 * @version 0.1
 * @date 2020-10-05
 * 
 * @Acknowledgements GEEKS FOR GEEKS : https://www.geeksforgeeks.org/implement-your-own-tail-read-last-n-lines-of-a-huge-file/
 * 
 */

#include "tail.h"

// void tail2(FILE *fp, int lines, int num);

/**
 * @brief main function reads file, flushes the buffer and calls tail(fp, index)
 * to print output. 
 * @param argc arguments that have been passed
 * @param argv holds the argument strings entered from the command line 
 * @return int 
 */
int main(int argc, char **argv) 
{ 
	FILE* fp;
	char *p;
	int num;

	fp = fopen( argv[1], "r"); 
	if (fp == NULL) 
	{ 
		printf("Error while opening file"); 
		exit(1); 
	} 
	 
	fflush(fp);

	if (argc == 2)
	{	
		for (int index = 0; index < 10; index++) 
		{  
			tail(fp, index);
		}
	}
	else if (argc == 3)
	{
		long conv = strtol(argv[2], &p, 10);
		num = conv;
		for (int index = 0; index < num; index++) 
		{  
			tail2(fp, index, num);
		}	
	}
	printf("\n");

	fclose(fp); 

	return 0; 
} 