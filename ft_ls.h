//
// Created by grafsky on 11/20/22.
//
#ifndef FT_LS_FNCS_H
#define FT_LS_FNCS_H

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdbool.h>
#include <errno.h>

typedef struct s_options{
    bool    a_flag;
    bool    R_flag;
    bool    r_flag;
    bool    l_flag;
    bool    t_flag;
}t_options;

int         ft_ls(int argc, char **argv);
char	    *ft_strchr(const char *s, int c);
int         ft_strlen(char *str);
char        *ft_strcpy(char *dest, char *src);
char        *get_permissions(struct stat fileStat);
int         ft_atoi(const char *str);
char	    *ft_itoa(int nb);
char        *get_username(uid_t uid);
char        *get_groupname(gid_t gid);
t_options   *get_output_options(char **args, int number);
char        **get_output_args(char **args, int number);
char	    **stradd(char *str, char **dst);
int         duarrlen(char **array);
char	    **duarrfree(char **arr);
char    	*ft_strdup(const char *s1);
char        **get_output_data(char **args, t_options *out_options);
int         ft_strcmp_nc(char *s1, char *s2);
char        to_lower(char chr);
char        **duarrbsort(char **arr);
void        output_data(char **data, t_options *out_options);
char        **duarrtsort(char **arr);
char        *get_list_format_data(struct stat fileStat, char *filename);
char        *strconcat(char *str1, char *str2);
char        *ft_strjoin(char const *s1, char const *s2);

#endif //FT_LS_FNCS_H
