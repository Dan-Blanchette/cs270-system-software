/**
 * @file mv.c
 * @author Dan Blanchette
 * @brief defintions page for the move() function
 * @version 1.0
 * @date 2020-10-11
 * 
 * 
 * 
 */

#include "mv.h"


/**
 * @brief  Using DIR *ptr this function will handle distinguishing between 
 * file renames commands and moving files to directory targets.
 * it will also utilize strcat to append the correct file directory 
 * path to the new directory.
 * 
 * @param fName // argv[1] or the given file name to be renamed or moved 
 * 
 * @param renameOrMvDir // parameter that will be evaluated as a new file name 
 *  or directory target location.
 * 
 * @param dest // a string buffer that will have strcat append the path of the
 * target directory to rename the file to.
 */
void move(char *fName, char *renameOrMvDir, char dest[100])
{
    if(renameOrMvDir[0] == '/')
    {
        strcat(renameOrMvDir, "/");
        strcat(renameOrMvDir, fName);

        /* ERROR CHECKING */
        if (rename(fName, renameOrMvDir) == 0)
            printf("Directory was found\n");
        else
            perror("Directory was not found\nthe program will now exit\n");
            exit(1);
    }   
    else
    {
        DIR *dirPtr; /* pointer to the struct __dirstream to see 
            if the argument being passed exists in the CWD */

        dirPtr = opendir(renameOrMvDir);

        /* Error checking  */
        if (dirPtr == NULL)
        {
            if (rename(fName, renameOrMvDir) != 0)
            {
                perror("No new filename was entered\nthe program will now exit\n");
                exit(1);
            }
            else
                printf("Operation complete.\nrenamed file %s to %s\n",
                    fName,renameOrMvDir);
            
        }
        else
        {
            char *pathPtr;
            pathPtr = getcwd(dest, 100);
            strcat(dest, "/");
            strcat(dest, renameOrMvDir);
            strcat(dest, "/");
            strcat(dest, fName);

            /* ERROR CHECKING */
            if (rename(fName, pathPtr) != 1)
                printf("%s has been moved to %s\n", fName, pathPtr);
            else
            {
                perror("Error: target directory doesn't exist within current the working directory\n");
                exit(1);
            }
            closedir(dirPtr);
        }
    }
}