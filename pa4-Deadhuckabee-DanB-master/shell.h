/**
 * @file shell.h
 * @author Dan Blanchette
 * @brief custom shell environment with junk command added
 * @version 0.1
 * @date 2020-11-04
 *  completed 2020-11-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h> // exit
#include <unistd.h> // fork, exec, chdir
#include <sys/wait.h> // wait
#include <sys/stat.h>

#define PATH 1024
#define UNAME 1024

void execute(char *arglist[]);
int cmdToArray(char *cmd, char *arglist[]);
void cd(char *arglist[]);
void junk(char *arglist[]);

/* supporting functions for void junk(char* arglist[]) */
void createJnk();
void junkList(char *arglist[]);
void deleteJunk(char *arglist[]);
void moveJunk(char *arglist[]);

#endif