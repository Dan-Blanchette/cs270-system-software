/**
 * @file shell.c
 * @author Dan Blanchette
 * @version 0.1
 * @date started 2020-11-04
 * completed 2020-11-10
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

    pid = fork(); // make new process
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
            printf("You have moved to the subdirectory path: %s\n", arglist[1]);
        }
        else if (strcmp(arglist[1], "..") == 0)
        {
            printf("you have moved to a parent directory path: %s\n", arglist[1]);
        }
    }
    if (strcmp(arglist[1], "~") == 0)
    {
        chdir(getenv("HOME"));
        printf("You are now in the home directory\n");
    }
}



/**
 * @brief this function will create a new hidden directory in 
 *  user's home directory called ".junk".
 * the junk command will take unwanted files and move them into .junk
 * with -l as arglist[1] it will list all files currently inside of the.junk directory
 * with -p as arglist[1] it will remove all files currently inside of the .junk directory
 * 
 * @param arglist 
 */
void junk(char *arglist[])
{
    char cwd[PATH];
    char *path;
    int pid, exitstatus;

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        path = getcwd(cwd, sizeof(cwd));
    }
    chdir(path);

    // if arglist [1] is a regular file, move it to the junk folder
    if (access(arglist[1], F_OK) == 0)
    {
        moveJunk(arglist);
    }
    else if (access(arglist[1], F_OK) != 0)
    {
        // list all the files in .junk
        if (strcmp(arglist[1], "-l") == 0)
        {
            junkList(arglist);
            chdir(path);
        }
        // else if arglist[1]  == "-p"
        else if (strcmp(arglist[1], "-p") == 0)
        {
            deleteJunk(arglist);
            chdir(path);
        }
        else
            fprintf(stderr, "\nIncorrect usage:\nsyntax or non-existing file: %s\n\nCorrect format: junk filename.ext or -l or -p\n\n", arglist[1]);
    }
}

/**
 * @brief will check for a directory named .junk in the 
 * home direcotry. If it exsists then no action needs to be taken
 * else, create the .junk directory in the home directory.
 * 
 * @param 
 */
void createJnk()
{
    char cwd[PATH];
    char *path;
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        path = getcwd(cwd, sizeof(cwd));
    }
    chdir(getenv("HOME"));
    struct stat st = {0};
    if (stat(".junk", &st) == -1)
    {
        mkdir(".junk", 0777);
        printf(".junk folder was created\n");
    }
    chdir(path);
}

/**
 * @brief "ls -l" of the .junk directory
 * 
 * @param arglist 
 */
void junkList(char *arglist[])
{
    int pid, exitstatus;

    pid = fork(); // make new process
    if (pid == -1)
    {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0)
    {
        chdir(getenv("HOME"));
        if (chdir(".junk") != 0)
        {
            printf("Empty junk folder!\n");
        }
        else
        {
            execlp("ls", "ls", "-l", NULL);
            // exec cannot return
            fprintf(stderr, "Cannot execute %s\n", arglist[0]);
        }
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
 * @brief delete all files in .junk
 * 
 * @param arglist 
 */
void deleteJunk(char *arglist[])
{
    // create a pointer to the struct that evaluates directory entries
    struct dirent *dirE;

    // navigate to the .junk folder in the home directory
    char homePath[256];
    strcpy(homePath, getenv("HOME"));
    strcat(homePath, "/.junk");
    chdir(homePath);

    // pointer to read the contents within a directory
    DIR *dirptr = opendir(".");
    if (dirptr == NULL)
    {
        printf("could not open directory\n");
        exit(1);
    }
    // while inside the current directory
    while ((dirE = readdir(dirptr)) != NULL )
    {
        // if the entry being accessed is a regular file
        if (access(dirE->d_name, F_OK) == 0)
        {
            // delete the files
            unlink(dirE->d_name);
        }
    } 
    closedir(dirptr);
    printf("\nDelete operation completed.\nThe .junk folder is empty\n\nFolder contents:\n");
    junkList(arglist);
}

/**
 * @brief moves files specified in arg[1] to the .junk 
 * using rename
 * 
 * @param arglist 
 */
void moveJunk(char *arglist[])
{
    char homePath[256];
    strcpy(homePath, getenv("HOME"));
    strcat(homePath, "/.junk/");
    // append the file name to complete the path requirement for
    // the rename function call.
    strcat(homePath, arglist[1]);

    if (rename(arglist[1], homePath) == 0)
    {
         printf("file %s was moved into the .junk folder\n", arglist[1]);
    }
}