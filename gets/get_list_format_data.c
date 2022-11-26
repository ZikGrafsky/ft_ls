//
// Created by grafsky on 11/20/22.
//
#include "../ft_ls.h"

char *get_list_format_data(struct stat fileStat, char *filename){
    char *ret_data = get_permissions(fileStat);
    ret_data = strconcat(ret_data, " ");
    ret_data = strconcat(ret_data, ft_itoa((long)fileStat.st_nlink));
    ret_data = strconcat(ret_data, "\t");
    ret_data = strconcat(ret_data, get_username(fileStat.st_uid));
    ret_data = strconcat(ret_data, " ");
    ret_data = strconcat(ret_data, get_groupname(fileStat.st_gid));
    ret_data = strconcat(ret_data, "\t");
    ret_data = strconcat(ret_data, ft_itoa(fileStat.st_size));
    ret_data = strconcat(ret_data, "\t\t");
    ret_data = strconcat(ret_data, ft_substr(ctime(&fileStat.st_mtime), 4, 12));
    ret_data = strconcat(ret_data, " ");
    ret_data = strconcat(ret_data, filename);
    return ret_data;
}