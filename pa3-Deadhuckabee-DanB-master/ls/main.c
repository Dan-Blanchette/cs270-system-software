/**
 * @file ls1.c
 * @author Dan Blanchette
 * @brief this program will output the same results as ls -ialR
 * @version 0.1
 * @date 2020-10-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "ls.h"

int main (int argc, char *argv[])
{

    if (argc == 1) // change back to 1
    {
        doLs(".");
    }
    else if(argc == 2)
    {
        // identifies the '-' as a flag in argv[1]
        char *flag = strrchr(argv[1], '-');
        char *a = strrchr(argv[1], 'a');
        char *i = strrchr(argv[1], 'i');
        char *l = strrchr(argv[1], 'l');
        char *R = strrchr(argv[1], 'R');
        char *str = argv[1];

        if (flag)
        {
            if (a && i && l && R)
            {
                lsialR(".");
            }
            else
                fprintf(stderr,"incorrect format for flag: -ialR\n");
        }
    }
    else
    {
        while (--argc)
        {
            printf("%s:\n", *++argv);
            doLs(*argv);
        }
    }
    return 0;
}