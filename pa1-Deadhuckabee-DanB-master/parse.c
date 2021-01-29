 /* parse.c
    Dan Blanchette
    Date:9 - 4 - 2020
*/

/* Sources: GeeksforGeeks.org for their outline of a dynamic
 * jagged array: 
 * https://www.geeksforgeeks.org/jagged-array-or-array-of-arrays-in-c-with-examples/
   #:~:text=Jagged%20array%20is%20array%20of, also%20known%20as%20Jagged%20arrays. */

#include "parse.h" 

 /* this function takes a user's input
  * ignores all whitespace chars and counts
  * the number of arguments in the char array
  * then outputs the number of arguments found
  * followed by the arguments one line at a time
  */

 int makearg(char *s, char ***args)
 {
    int i, j, k = 0;
    int size = wCount(s);

    // check for an empty string 
    if(strlen(s) == 0)
    {
        return -1;
    }

   
    *args = (char **)malloc(sizeof(char *) * size);

    for ( i = 0; i < size ; i++)
    {
        (*args)[i] = malloc(sizeof(char) * size);
    }

    displayS(s, args);

 } 

/* this function is meant to accumulates the word 
 * count for each single space encountered indicating the end of
 * a word.
 * it then accounts for the '\0' by adding + 1 to the stored value*/

int wCount(char *s)
{
    int len;
    int i, arrChar = 0, wCount = 0; 
    for(i = 0; s[i] != '\0'; i++)
    {   
        
        if ( isspace(s[i]) == 0  && isspace(s[i+1]) !=  1 )
        {
            arrChar++;
        }

        if ( isspace(s[i]) == 0  && isalnum(s[i+1]) == 0 )
        {
            wCount++;
        }
    }
    
    /* test code 
     printf("\nThere are %d words\n", wCount);
     printf("I found %d chars\n", arrChar);
     */
    
    return wCount;
}

// responsible for printingt out the resulting string data
void displayS(char *s, char ***args)
{
    // int i, j, k;

    // for (int i = 0; i < 2; i++) 
    // { 
  
    //     char *iPtr = args[i]; 
    //     for (int j = 0; j < s[k]; j++) 
    //     { 
  
    //         printf("%d ", *iPtr); 
    //         // move the pointer to the next element 
    //         iPtr++; 
    //     } 

    //     printf("\n"); 
    //     k++; 

    //     // move the pointer to the next row 
    //     args[i]++; 
    // } 
}