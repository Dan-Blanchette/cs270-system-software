/**
 * @file ls.h
 * @author Dan Blanchette
 * @brief header file
 * @version 0.1
 * @date 2020-10-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef LS_H
#define LS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define MAXPATH 512

void doLs(const char *dirname);
void lsialR(const char *dirname);
void showStatInfo(const char *fname, struct stat *buf);
void modeToLetters(int mode, char str[]);
char* uidToName(uid_t id);
char* gidToName(gid_t id);

#endif