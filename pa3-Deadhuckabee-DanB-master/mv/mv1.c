/**
 * @file main.c
 * @author Dan Blanchette
 * @brief this program will compare argv[1] and argv[2]
 * If both arguments are file names, it will replace argv[1]'s file name
 * with argv[2]'s entered filename.
 * 
 * If argv[1] is a filename and argv[2] is a directory,
 * it will move the named file into the target directory passed
 * in argv[2]
 * 
 * 
 * @version 0.1
 * @date 2020-10-10
 * 
 * Acknowledgements: Basic Linux mv command implemented in C https://www.youtube.com/watch?v=v6AORKjrRCA
 * 
 */
#include "mv.h"

int main(int argc, char **argv)
{
    char *fName = argv[1];
    char *dirorfname = argv[2];
    char destdir[100];

    if (argc != 3)
        perror("exceeds that valid amount of required passed arguments");
    else
        move(fName, dirorfname, destdir);
    
    return 0;
}