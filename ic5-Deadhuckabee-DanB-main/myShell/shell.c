/**
 * @file shell.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-10-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "shell.h"

/**
 * @brief Split string cmd into arguments where
 *        each pointer element of arglist is pointing
 *        to a string in cmd. 
 * 
 * @param cmd      string command
 * @param arglist  string arguments as an array of pointers
 *                 to C-strings
 * @return int     number of arguments in cmd
 */
int cmdToArray(char *cmd, char *arglist[])
{
    int argc = 0;
    int newString = 0;
    int length = strlen(cmd);
    for (int i = 0; i < length; ++i)
    {
        if (cmd[i] != ' ' && newString == 0)
        {
            newString = 1;
            arglist[argc] = &cmd[i];
            ++argc;
        }
        else if (cmd[i] == ' ')
        {
            newString = 0;
            cmd[i] = '\0';
        }
    }
    arglist[argc] = NULL;
    return (argc); // counts the number of arguments
}

/**
 * @brief Creates a child process and executes the command
 *        in the first element of arglist
 * 
 * @param arglist  command and arguments as an array of pointers
 *                 to C-strings
 */
void execute(char *arglist[])
{
    int pid, exitstatus;

    pid = fork();  // make new process
    if (pid == -1)
    {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0)
    {
        execvp(arglist[0], arglist);
        // exec cannot return
        fprintf(stderr, "Cannot execute %s\n", arglist[0]);
        exit(1); // exec failed
    }
    else 
    {
        int got_pid = wait(&exitstatus);
        if (got_pid == pid)
        {
            if (WIFEXITED(exitstatus))
            {
                printf("***pid=%d exited with status %d***\n\n", pid, WEXITSTATUS(exitstatus));
            }
        }
        else if (got_pid == -1)
        {
            perror("wait failed");
        }
    }
}

/**
 * @brief this function will add directory change fucntionality 
 *  to the shell
 * 
 * @param arglist 
 */

void cd(char *arglist[])
{   
    int dircheck = 0;

    dircheck = chdir(arglist[1]);
    
    if (dircheck == 0)
    {
        if (strcmp(arglist[1], "..") != 0)
        {
            printf("You have moved one level deeper into %s\n",arglist[1]);
        }
        else if (strcmp(arglist[1], "..") == 0)
        {
            printf("you have moved up one level to a previous directory\n");
        }
        
    }
    
}