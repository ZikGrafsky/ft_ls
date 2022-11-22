//
// Created by grafsky on 11/20/22.
//
#include "../ft_ls.h"

char *strconcat(char *str1, char *str2){
    char *tmp = ft_strjoin(str1, str2);
    if (str1)
        free(str1);
    return tmp;
}
