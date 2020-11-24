#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int pid;
    
    if ((pid = fork()) == 0)
    {
        printf("Child %d is playing...\n", getpid());
        sleep(5);
        execlp("ls", "ls", "-l", NULL);
        printf("The Child %d is now done playing!\n", getpid());
    }
    else
    {
        printf("Parent needs to go home and do something\n");
        printf("But the Child is playing..\n");
        int childStatus;
        int pidWait = wait(&childStatus);
        printf("child %d has terminated with status %d\n", pidWait, childStatus);
        printf("The parent is now going home\n");   
    }
    return EXIT_SUCCESS;
}