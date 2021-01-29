#!/usr/bin/env python3

# Dan Blanchette
# CS270
# November 21 2020
# Pyton junk program 

import os
import sys

cwd = os.getcwd()
# get the user's home directory path
homedir = os.getenv("HOME")
# number of arguments passed
numArgs = len(sys.argv)
# path to be concatonated with the homedir path
junkFolder = "/.junk"
error = "ERROR: Improper format: \n\nAcceptable formats for this utility are:\n./junk.py\n./junk.py 'file_name.extention'\n./junk.py -l or -p"

jPath = homedir + junkFolder
# if only argv[0] is passed
if sys.argv[0] == "./junk.py":
    os.chdir(homedir)
    if not os.path.isdir(jPath):
        os.mkdir(".junk")
        # once the operation is completed, return back to the
        # original CWD
        os.chdir(cwd)
# the directory exists, carry on with program
else:
    pass
# if argv[1] is a regular file move it to .junk folder if not check for other arguments
if numArgs == 2:
    regfile = os.path.join(cwd, sys.argv[1])
    if os.path.isfile(regfile) is True:
        mv = os.path.join(jPath, sys.argv[1])
        os.rename(regfile, mv)
        os.chdir(cwd)
    else:
        pass

    # if argv[1] == -l , make a call to the shell subsystem command "ls -l"
    if numArgs == 2:
        fileName = sys.argv[1]
        if sys.argv[1] == "-l":
            os.chdir(jPath)
            os.system('ls -l')
            os.chdir(cwd)
        else:
            pass
# if argv[1] == -p, read and store the directorie's contents then remove each file. 
if numArgs == 2:
    if sys.argv[1] == "-p":
        os.chdir(homedir)
        contents = os.listdir('.junk')
        for file in contents:
            if file.find('.*') > -1:
                pass
            else:
                print('Delete Complete', file)
                # if there is a regular file within the directory,
                # delete it
                os.remove(os.path.join(jPath, file))
# error checking for more than 2 arguments being passed
if numArgs <= 2:
    pass
else:
    print(error)