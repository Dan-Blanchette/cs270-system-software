#include <stdio.h>
#include <string.h> // strcmp
#include <stdlib.h> // exit
#include <unistd.h> // fork, exec
#include <sys/wait.h> // wait

#define MAXARGS 20
#define ARGLEN 256

void cmdToArray(char *cmd, char *arglist[]);
void execute(char *arglist[]);


int main(void)
{
    int pid;
    char *arglist[MAXARGS + 1];   // array of pointers
    char cmd[ARGLEN];           // read stuff here
    

    while (1)
    {
        printf("cmd> ");
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
            // TODO: break cmd into individual strings as elements of arglist
            cmdToArray(cmd, arglist);
            execute(arglist);
        }
    }

    return 0;
}

void cmdToArray(char *cmd, char *arglist[])
{
    int argc = 0;
    int newStr = 0;
    int len = strlen(cmd);
    for (int i = 1; i < len; i++)
    {
        if ( cmd[i] != ' ' && newStr == 0)
        {
            arglist[argc] = &cmd[i];
            argc++;
        }
        else if( cmd[i] == ' ')
        {
            cmd[i] = '\0';
            newStr++;
        }
        arglist[argc][newStr];
    }
}

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
            printf("The child we were waiting for died\n");

            if (WIFEXITED(exitstatus))
            {
                printf("child process %d exited with value %d\n", pid, WEXITSTATUS(exitstatus));
            }
        }
        else if (got_pid == -1)
        {
            perror("wait failed");
        }
    }
}
