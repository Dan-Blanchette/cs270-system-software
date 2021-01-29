/*  main.c
    Dan Blanchette
    Date:9 - 4 - 2020
*/
#include"parse.h"

int main(void)
{
    char buff[1024], **argv; // buff[] or *buff , **argv
    int argc;

    // get user input and store it into buff[]
    fgets(buff, sizeof(buff), stdin);

     makearg(buff, &argv);

    
    return 0; 
 }
