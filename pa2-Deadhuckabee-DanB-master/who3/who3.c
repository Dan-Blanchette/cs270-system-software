/**
 * @file who3.c
 * @author Dan Blanchette
 * @brief Third version of the who program open,
 *        read UTMP file, and show results
 *        - suppress empty records
 *        - format time nicely
 *        - apply buffering for efficiency
 * @version 0.3
 * @date 10/2/2020
 * 
 */
#include <stdio.h>
#include <utmp.h>
#include <time.h>
#include <stdlib.h> // exit()
#include "utmplib.h"

#define SHOWHOST  // include remote machine an output

void showTime(long timeval);
void showInfo(struct utmp *utbufp);

int main()
{
    struct utmp *currentRecord;  // read info into here

    if (utmpOpen(UTMP_FILE) == -1)
    {
        perror(UTMP_FILE);   // UTMP_FILE is in utmp.h
        exit(1);
    }

    while ((currentRecord = utmpNext()) != NULL)
    {
        showInfo(currentRecord);
    }

    utmpClose();
    return 0;
}

/**
 * @brief Displays contents of the utmp struct in human readable form
 *        *note* these sizes should not be hardwired
 * 
 * @param utbufp pointer to struct utmp data
 */
void showInfo(struct utmp *utbufp)
{
    if (utbufp->ut_type != USER_PROCESS)
         return;

    // the logname
    printf("%-8.8s ", utbufp->ut_name);

    // the tty (terminal)
    printf("%-8.8s ", utbufp->ut_line);

    // login time
    showTime(utbufp->ut_time);

#ifdef SHOWHOST
    printf("(%s)", utbufp->ut_host);
#endif

    printf("\n");
}

/**
 * @brief Displays time in a format fit for human consumption
 *        uses ctime to build a string then picks parts out of it
 *        Note: %12.12s prints a string 12 chars wide and LIMITS
 *        it to 12chars only.
 * 
 * @param timeval 
 */
void showTime(long timeval)
{
    time_t t = time(NULL);
    struct tm tmptr = *localtime(&t);
    char *cp;  // holds address of time

    // Convert time to string
    //cp = ctime(&timeval);

    // pick 12 chars from pos 4
    printf("%8d-%02d-%02d %02d:%02d ", tmptr.tm_year + 1900, tmptr.tm_mon + 1, 
        tmptr.tm_mday, tmptr.tm_hour, tmptr.tm_min);
}