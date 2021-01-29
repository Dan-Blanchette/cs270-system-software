 /**
 * @file tail.c
 * @author Dan Blanchette
 * @brief 
 * @version 0.1
 * @date 2020-10-06
 * 
 * @Acknowledgements GEEKS FOR GEEKS : https://www.geeksforgeeks.org/implement-your-own-tail-read-last-n-lines-of-a-huge-file/
 * 
 */
 #include "tail.h"


/**
 * @brief looks for the last 10 lines of a file
 * based on the '\n' characters encountered
 * and returns the count and prints the lines
 * 
 * @param fp 
 * @param lines 
 */
void tail(FILE *fp, int lines) 
{ 
	/**
	 * @brief int count stores the amount of 
	 * newline characters encountered in the file.
	 */
	int count = 0;  

	unsigned long long position; 
	char str[2*SIZE]; 

	if (fseek(fp, 0, SEEK_END)) 
		perror("The fseek() operation has failed"); 
	else
	{ 
		/**
		 * @brief position will store the count of 
		 * the number of characters in the file
		 * 
		 */
		 position = ftell(fp); 

		// look for the newline char 
		while (position) 
		{ 
			// starting from EOF read the file back toward
			// the start. 
			if (!fseek(fp, --position, SEEK_SET)) 
			{ 
				if (fgetc(fp) == '\n') 

					// stop reading when newlines 
					// are found 
					if (count++ == lines) 
						break; 
			} 
			else
				perror("The fseek() operation has failed"); 
		} 

		// after 10 '\n' chars are encountered, 
		// print the last 10 lines  
		while (fgets(str, sizeof(str), fp))
			if (count == 10) 
				printf("%s", str); 
	} 
} 


/**
 * @brief similar implementation as before
 * however this version of tail will allow 
 * the third parameter a 
 * user specified line disignation 
 * to print to console.
 * 
 * @param fp 
 * @param lines 
 * @param num 
 */

void tail2(FILE *fp, int lines, int num) 
{ 
	/**
	 * @brief int count stores the amount of 
	 * newline characters encountered in the file.
	 */
	int count = 0;  


	unsigned long long position; 
	char str[2*SIZE]; 

	if (fseek(fp, 0, SEEK_END)) 
		perror("The fseek() operation has failed"); 
	else
	{ 
		/**
		 * @brief position will store the count of 
		 * the number of characters in the file
		 * 
		 */
		 position = ftell(fp); 

		// look for the newline char 
		while (position) 
		{ 
			// starting from EOF read the file back toward
			// the start. 
			if (!fseek(fp, --position, SEEK_SET)) 
			{ 
				if (fgetc(fp) == '\n') 

					// stop reading when newlines 
					// are found 
					if (count++ == lines) 
						break; 
			} 
			else
				perror("The fseek() operation has failed"); 
		} 

		// after 10 '\n' chars are encountered, 
		// print the last 10 lines  
		while (fgets(str, sizeof(str), fp))
			if (count == num) 
				printf("%s", str);
			 
	} 
} 