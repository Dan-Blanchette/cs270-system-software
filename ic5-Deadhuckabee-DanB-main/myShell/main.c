/**
 * @file   main.c
 * @author WRITE STUDENT NAME
 * @brief  My own version of the shell
 * @date   WRITE DATE TODAY
 * 
 */
#include <stdio.h>
#include <string.h> // strcmp
#include <stdlib.h> // exit
#include "shell.h"

#define MAXARGS 20
#define ARGLEN 256




int main()
{
    char *arglist[MAXARGS+1];   // array of pointers
    char cmd[ARGLEN];           // read stuff here

    while (1)
    {
        printf("Dan_Shell> ");
        fgets(cmd, ARGLEN, stdin);

        // remove newline from cmd
        cmd[strlen(cmd) - 1] = '\0';

        // exit if user types exit
        if (strcmp(cmd, "exit") == 0)
        {
            exit(0);
        }
        else if (*cmd != '\0')
        {
            int numArg = cmdToArray(cmd, arglist);
            if (strcmp(arglist[0], "cd") == 0)
            {
                if (numArg == 2)
                {
                    cd(arglist);
                }
            }
            else
            {
                execute(arglist);
            }
        }
    }

    return 0;
}
