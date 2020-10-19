/**
 * @file main.c
 * @author Dan B
 * @brief Fork Practice from week 08 lecture
 * @version 0.1
 * @date 2020-10-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "fork1.h"

int main()
{
    int A[] = {1, 2, 3, 4 , 5, 6};
    int sum = 0, product = 1, pid;

    if ((pid = fork()) == 0)
    {
        for (int i = 0; i < 6; i++)
        {
            sum += A[i];
        }
        sleep(3);
        printf("The child process computed sum is %d \n", sum);
        exit(0);
    }
    if (pid < 0)
        fprintf(stderr, "problem creating a process \n");
    if ( pid > 0)
    {
        for ( int i = 0; i < 6; i++)
        {
            product *= A[i];
        }
        printf("This is the parent process the product is %d \n", product);
        sleep(4);
    }

    return 0;
}