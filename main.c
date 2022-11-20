//
// Created by grafsky on 11/12/22.
//
#include "ft_ls.h"

int main(int argc, char **argv){
    ft_ls(argc, argv);
    return 0;
}

/*output{
DIR *opened = opendir("./");
struct dirent *tmp = readdir(opened);
struct stat fileStat;

while (tmp != NULL) {
stat(tmp->d_name, &fileStat);
write(1, get_permissions(fileStat), 10);
write(1, "\t", 1);
write(1, ft_itoa((int) fileStat.st_nlink), ft_strlen(ft_itoa((int) fileStat.st_nlink)));
write(1, "\t", 1);
write(1, get_username(fileStat.st_uid), ft_strlen(get_username(fileStat.st_uid)));
write(1, "\t", 1);
write(1, get_groupname(fileStat.st_gid), ft_strlen(get_groupname(fileStat.st_gid)));
write(1, "\t", 1);
write(1, ft_itoa((int) fileStat.st_size), ft_strlen(ft_itoa((int) fileStat.st_size)));
write(1, "\t", 1);
write(1, ctime(&fileStat.st_atime), ft_strlen(ctime(&fileStat.st_atime)) - 1);
write(1, "\t", 1);
write(1, tmp->d_name, ft_strlen(tmp->d_name));
write(1, "\n", 1);
//        free(&fileStat);
tmp = readdir(opened);
}
}*/