# ic5

## Exercise 1 (3 points)
* Display the names and values of all the shell variables on your Linux machine. Redirect the output of this command to a file called **shellvariables.txt**

#### What command did you use? Replace the line below with the command you use
```
$ printenv > shellvariables.txt
```

* Commit your changes to git and push your repo

## Exercise 2 (7 points)
Create a shell script file called **exercise2**
* Begin the script with `#!/bin/bash`
* Include a comment with your name in it
* Should contain statements comprising the `date` and `pwd` commands, one on each line.
* Make the file executable and run the shell script to test it.
* Commit your changes to git and push your repo

## Exercise 3 (20 points)
Add more functionality to our version of the shell. Currently, you cannot change directory in your version of the shell. If you try `cd` in your shell, it will not work. `cd` command is not a separate program but a built-in proram integrated with the shell. Thus, you will also have to integrate this feature into your version of the shell.
* Add another condition to check in `main()` to check when the user enters `cd` command. For now, `cd` MUST have one additional argument, the name of the directory to go to.
* Create a function that will be called if the user enters the `cd` command. 
* Test your `cd` command by going in and out of existing folders
    * `cd ..`
    * `cd <folder you have>`
    * `cd ../<folder in the parent directory>`
* Create a makefile
