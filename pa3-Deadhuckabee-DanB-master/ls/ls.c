/**
 * @file ls.c
 * @author Dan Blanchette
 * @brief function definitions file
 * @version 0.1
 * @date 2020-10-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "ls.h"

/**
 * @brief the regular output of ls
 * 
 * @param dirname 
 */
void doLs(const char *dirname)
{
    DIR *pDir;               // the directory
    struct dirent *pDirent;  // each entry

    if ((pDir = opendir(dirname)) == NULL)
    {
        fprintf(stderr, "ls1: cannot open %s\n", dirname);
    }
    else
    {
        while ((pDirent = readdir(pDir)) != NULL)
        {
            if (strcmp(pDirent->d_name, ".") == 0 || strcmp(pDirent->d_name, "..") == 0)
                continue;
            else
                printf("%s  ", pDirent->d_name);
        }
        printf("\n");
        closedir(pDir);
    } 
}

/**
 * @brief will output my version of ls -ialR
 * 
 * @param dirname 
 */
void lsialR(const char *dirname)
{
    DIR *pDir;               // the directory
    struct dirent *pDirent;  // each entry

    if ((pDir = opendir(dirname)) == NULL)
    {
        fprintf(stderr, "ls2: cannot open %s\n", dirname);
    }
    else
    {   
        printf(".:\n");
        while ((pDirent = readdir(pDir)) != NULL)
        {
            char filename[MAXPATH];
            struct stat info, *buff;
            
            strcpy(filename, dirname);
            if (dirname[strlen(dirname)-1] != '/')
            {
                strcat(filename, "/");
            }
            strcat(filename, pDirent->d_name);        

            if (stat(filename, &info) != -1)
            {   
                showStatInfo(pDirent->d_name, &info);
            }
            else
            {
                perror(pDirent->d_name); 
            }
        }
        closedir(pDir);
    }   
}

/**
 * @brief Displays some info from stat in name=value format
 * 
 * @param fname  filename
 * @param buf    stat information for the filename
 */
void showStatInfo(const char *fname, struct stat *buf)
{
    // EXCLUDE HIDDEN FILES
    char strMode[11];
    printf("total %2ld", buf->st_blocks);
    printf("%6ld",buf->st_ino);
    printf("  ");
    modeToLetters(buf->st_mode, strMode);
    printf("%10s ", strMode);
    printf("%3ld ", buf->st_nlink);
    printf("%-8s ", uidToName(buf->st_uid));
    printf("%-8s ", gidToName(buf->st_gid));
    printf("%6ld ", buf->st_size);
    printf("%.12s ", 4+ctime(&buf->st_mtime));
    printf("%s\n", fname); 
}

char* uidToName(uid_t id)
{
    // CODE HERE
    return getpwuid(id)->pw_name;
}

char* gidToName(gid_t id)
{
    // CODE HERE
    return getgrgid(id)->gr_name;
}

void modeToLetters(int mode, char str[])
{
    strcpy(str, "----------");
    int len =  strlen(str), i;
    
    if ((mode & S_IFMT) == 0040000)
	    str[0] = 'd';
    
    if ((mode & S_IFMT) == 0020000)
	    str[0] = 'c';
    
    // user
    if ((mode & S_IRUSR))
        str[1] ='r';
    
    if ((mode & S_IWUSR))
        str[2] ='w';

    if ((mode & S_IXUSR))
        str[3] ='x';
    
    // group
    if ((mode & S_IRGRP))
        str[4] ='r';

    if ((mode & S_IWGRP))
        str[5] ='w';

    if ((mode & S_IXGRP))
        str[6] ='x';

    // others
    if ((mode & S_IROTH))
        str[7] ='r';

    if ((mode & S_IWOTH))
        str[8] ='w';

    if ((mode & S_IXOTH))
        str[9] ='x';
}
