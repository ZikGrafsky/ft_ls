//
// Created by grafsky on 11/20/22.
//
#include "../ft_ls.h"

char *get_permissions(struct stat fileStat){
    char *permissions = (char *)malloc(sizeof(char) * 11);
    if (S_ISDIR(fileStat.st_mode))
        permissions[0] = 'd';
    else if (S_ISLNK(fileStat.st_mode))
        permissions[0] = 'l';
    else if (S_ISCHR(fileStat.st_mode))
        permissions[0] = 'c';
    else if (S_ISBLK(fileStat.st_mode))
        permissions[0] = 'b';
    else if (S_ISFIFO(fileStat.st_mode))
        permissions[0] = 'f';
    else if (S_ISSOCK(fileStat.st_mode))
        permissions[0] = 's';
    else
        permissions[0] = '-';
    permissions[1] = (fileStat.st_mode & S_IRUSR) ? 'r' : '-';
    permissions[2] = (fileStat.st_mode & S_IWUSR) ? 'w' : '-';
    permissions[3] = (fileStat.st_mode & S_IXUSR) ? 'x' : '-';
    permissions[4] = (fileStat.st_mode & S_IRGRP) ? 'r' : '-';
    permissions[5] = (fileStat.st_mode & S_IWGRP) ? 'w' : '-';
    permissions[6] = (fileStat.st_mode & S_IXGRP) ? 'x' : '-';
    permissions[7] = (fileStat.st_mode & S_IROTH) ? 'r' : '-';
    permissions[8] = (fileStat.st_mode & S_IWOTH) ? 'w' : '-';
    permissions[9] = (fileStat.st_mode & S_IXOTH) ? 'x' : '-';
    permissions[10] = '\0';
    return permissions;
}