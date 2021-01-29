/**
 * @file shell.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-10-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // exit
#include <unistd.h> // fork, exec, chdir
#include <sys/wait.h> // wait



void execute(char *arglist[]);
int cmdToArray(char *cmd, char *arglist[]);
void cd(char *arglist[]);

#endif