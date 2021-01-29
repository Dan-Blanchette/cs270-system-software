/**
 * @file ls2.c
 * @author Gabe de la Cruz
 * @brief List contents of directory or directories.
 *        If no args, use . else list files in args
 * @version 0.2
 * @date 2020-10-01
 * 
 * Student Name: Dan Blanchette
 * ICP1
 * 10-1-2020
 */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

#define MAXPATH 512

void doLs(const char*);
void showStatInfo(const char *fname, struct stat *buf);
void modeToLetters(int mode, char str[]);
char* uidToName(uid_t id);
char* gidToName(gid_t id);

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        doLs(".");
    }
    else
    {
        while (--argc)
        {
            printf("%s:\n", *++argv);
            doLs(*argv);
        }
    }

    return 0;
}

/**
 * @brief List files in directory called dirname
 * 
 * @param dirname 
 */
void doLs(const char *dirname)
{
    DIR *pDir;               // the directory
    struct dirent *pDirent;  // each entry

    if ((pDir = opendir(dirname)) == NULL)
    {
        fprintf(stderr, "ls2: cannot open %s\n", dirname);
    }
    else
    {
        while ((pDirent = readdir(pDir)) != NULL)
        {
            char filename[MAXPATH];
            struct stat info;
            
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
