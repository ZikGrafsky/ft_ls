//
// Created by grafsky on 11/20/22.
//
#include "../ft_ls.h"

char    *get_username(uid_t uid){
    struct passwd *pws;
    pws = getpwuid(uid);
    return pws->pw_name;
}