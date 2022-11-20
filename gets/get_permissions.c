//
// Created by grafsky on 11/20/22.
//
#include "../ft_ls.h"

char *get_permissions(struct stat fileStat){
    char *permissions = malloc(sizeof(char) * 10);
    permissions[0] = (S_ISDIR(fileStat.st_mode)) ? 'd' : '-';
    permissions[0] = (S_ISLNK(fileStat.st_mode)) ? 'l' : '-';
    permissions[0] = (S_ISREG(fileStat.st_mode)) ? 'r' : '-';
    permissions[0] = (S_ISCHR(fileStat.st_mode)) ? 'c' : '-';
    permissions[0] = (S_ISBLK(fileStat.st_mode)) ? 'b' : '-';
    permissions[0] = (S_ISFIFO(fileStat.st_mode)) ? 'f' : '-';
    permissions[0] = (S_ISSOCK(fileStat.st_mode)) ? 's' : '-';
    permissions[1] = (fileStat.st_mode & S_IRUSR) ? 'r' : '-';
    permissions[2] = (fileStat.st_mode & S_IWUSR) ? 'w' : '-';
    permissions[3] = (fileStat.st_mode & S_IXUSR) ? 'x' : '-';
    permissions[4] = (fileStat.st_mode & S_IRGRP) ? 'r' : '-';
    permissions[5] = (fileStat.st_mode & S_IWGRP) ? 'w' : '-';
    permissions[6] = (fileStat.st_mode & S_IXGRP) ? 'x' : '-';
    permissions[7] = (fileStat.st_mode & S_IROTH) ? 'r' : '-';
    permissions[8] = (fileStat.st_mode & S_IWOTH) ? 'w' : '-';
    permissions[9] = (fileStat.st_mode & S_IXOTH) ? 'x' : '-';
    return permissions;
}