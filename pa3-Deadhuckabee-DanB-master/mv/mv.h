/**
 * @file mv.h
 * @author Dan Blanchette
 * @brief MV_H header file
 * @version 1.0
 * @date 2020-10-11
 * 
 * 
 * 
 */

#ifndef MV_V
#define MV_V

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

/**
 * @brief 
 * 
 * @param file 
 * @param loc 
 * @param dest 
 */
void move(char *fName, char *renameOrMvDir, char *dest);

#endif