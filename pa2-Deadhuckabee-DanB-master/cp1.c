/**
 * @file cp1.c
 * @author Dan Blanchette
 * @brief Uses read and write with tunable buffer size
 *        usage: cp1 src dest
 * @version 2.0
 * @date 10/7/2020
 * 
 * Acknowledgements for code structures/methods used: stackoverflow.com
 */ 
 // https://stackoverflow.com/questions/230062/whats-the-best-way-to-check-if-a-file-exists-in-c
 // https://stackoverflow.com/questions/37049845/using-stat2-to-compare-to-files-if-the-same-dont-copy 
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUFFERSIZE   4096
#define COPYMODE     0644

void oops(char *, char *);
int isSame(char *fName1, char *fName2);
bool isExFile(char *fName2);


int main(int argc, char *argv[])
{
    int infd, outfd, nChars;
    char buf[BUFFERSIZE];
    char *fn1 = argv[1], *fn2 = argv[2];
    int arr1 = sizeof(argv[1]), arr2 = sizeof(argv[2]);

    // check args
    if (argc != 3)
    {
        fprintf(stderr, "usage: %s source destination\n", *argv);
        exit(1);
    }

    if (isSame(fn1,fn2) == 1)
    {
        exit(1);
    }


    if (isExFile(fn2) == true)
    {
        char choice;
        printf("cp: overwrite '%s'?\nenter 'y' for yes or 'n' for no: ", fn2);
        scanf("%c", &choice);
        switch(choice)
        {
            case 'y':
                printf("The file has been overwritten\n");
                break;

            case 'Y':
                printf("The file has been overwritten\n");
                break;

            case 'n':
                printf("The file has been preserved\nThe program will now exit\n");
                exit (1);
            case 'N':
                printf("The file has been preserved\nThe program will now exit\n");
                exit (1);
            default:
                exit (1);
        }
    }
    
    


    // open files
    if ((infd = open(argv[1], O_RDONLY)) == -1)
    {
        oops("Cannot open ", argv[1]);
    }

    if ((outfd = creat(argv[2], COPYMODE)) == -1)
    {
        oops("Cannot open ", argv[2]);
    }

    // copy files
    while ((nChars = read(infd, buf, BUFFERSIZE)) > 0)
    {
        if (write(outfd, buf, nChars) != nChars)
        {
            oops("Write error to ", argv[2]);
        }
    }
    if (nChars == -1)
    {
        oops("Read error from ", argv[1]);
    }

    if (close(infd) == -1 || close(outfd) == -1)
    {
        oops("Error closing files", "");
    }

    return 0;
}


/**
 * @brief creates two pointers that will examine 
 * each of the two buffer's file contents and
 * returns true value if the contents were the same
 * false if not
 * 
 * @param p pointer that points to the start of first buffer array
 * @param q pointer that points to the start of second buffer array
 * @param n the resulting size passed isSame(char *fName1, char *fName2)
 * @return int value for comparison
 */
static int fileCmp(const void *a1Ptr, const void *a2Ptr, size_t size)
{
    const char *bufptr1 = a1Ptr;
    const char *bufptr2 = a2Ptr;

    while(size-- > 0)
    {
        if( *bufptr1++ != *bufptr2++)
        {
            return 0;
        }
    }

    return 1;
}

/**
 * @brief Displays error to the standard error and
 *        prints error by the system call using perror().
 *        Program terminates when this function is called.
 * 
 * @param s1 type of error
 * @param s2 file that cause the error
 */
void oops(char *s1, char *s2)
{
    fprintf(stderr, "Error: %s ", s1);
    perror(s2);
    exit(1);
}


/**
 * @brief code structure from Stackoverflow
 * looks at inode values to determine if the files
 * are the same or not.
 * 
 * @param fName1 
 * @param fName2 
 * @return int 
 */
int isSame(char *fName1, char *fName2)
{
    struct stat src, dst;
    int err;
    err = stat(fName1, &src);
    if (err < 0)
    {
        perror("stat");
        exit(1);
    }
    err = stat(fName2, &dst);
    if (err < 0)
    {
        perror("stat");
        exit(1);
    }
    if((src.st_dev == dst.st_dev) && (src.st_ino == dst.st_ino))
    {
        printf("cp: '%s' and '%s' are the same file\n", fName1, fName2);
        return 1;
    }
    return 0;
}


/**
 * @brief checks for existing files and prompts
 * user before overwriting their contents
 * 
 * @param fName2 
 * @return true 
 * @return false 
 */
bool isExFile(char *fName2)
{
    if (access( fName2, F_OK) != -1)
    {
        // the file exists
        return true;
    }
    else 
        // the file doesn't exist
        return false;
}