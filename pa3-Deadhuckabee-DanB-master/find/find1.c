/**
 * @file main.c
 * @author Dan Blanchette
 * @brief this program will operate similar to 
 * the find command in the linux command shell
 * 
 * @version 0.1
 * @date 2020-10-08
 * 
 * Acknowledgements: modified program of
 * In class lecture code from week06 ls1.c
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

void find(const char*);

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        find("./");
    }
    else
    {
        while (--argc)
        {
            printf("%s:\n", *++argv);
            find(*argv);
        }
    }

    return 0;
}


/**
 * @brief operates similar to the ls command with
 * added logic to search for specific directory
 * symbology. If '.' is found it is printed as it
 * appears.
 * 
 * If ".." is found the entry will still be printed
 * by ls but is ignored by find
 * 
 * otherwise all files that exist in the CWD are prefixed with
 * "./" to indicate to the user that the files exist in 
 * the same directory.
 * 
 * @param dirname 
 */
void find(const char *dirname)
{
    DIR *DirPtr;               // the directory
    struct dirent *pDirent;  // each entry

    if ((DirPtr = opendir(dirname)) == NULL)
    {
        fprintf(stderr, "ls1: cannot open %s\n", dirname);
    }
    else
    {
        while ((pDirent = readdir(DirPtr)) != NULL)
        {
            if (pDirent->d_name[0] == '.' && pDirent->d_name[1] != '.')
            {
                printf("%s\n", pDirent->d_name);
            }
            else if (pDirent->d_name[0] == '.' && pDirent->d_name[1] == '.')
            {
                continue;
            }
            else
                printf("./%s\n", pDirent->d_name);
        }
        closedir(DirPtr);
    }
    
}
