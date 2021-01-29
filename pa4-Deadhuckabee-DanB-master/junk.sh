# Dan Blanchette
# CS270
# Nov 6 2020

#!/bin/bash

# create the junk directory as a hidden directory
# in the home directory.

#  check for errors and exit if an error is detected
# set -e


dir_check()
{
    [ ! -d $1 ] || return 0
    mkdir -p $1
}
if [ $# -eq 0 ];
    # create .junk directory
    then dir_check "${HOME}/.junk"
    # check to see if .junk exists or has been modified
    touch "${HOME}/.junk"
elif [ "$1" = "-l" ];
    then echo "$(ls -l ~/.junk)"
elif [ "$1" = "-p" ];
    then $(rm -f ~/.junk/*)
elif [ -f $1 ];
   then for file in "$1";
            do mv "$file" "${HOME}/.junk"
        done
else
    echo "ERROR: invalid argument(s). Valid arguments are: exisiting files (*.txt, .c, etc), -l, or -p"
fi