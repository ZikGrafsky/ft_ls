//
// Created by grafsky on 11/20/22.
//
#include "../ft_ls.h"

int ft_strlen(char *str){
    int i = 0;
    while (str[++i]!='\0');
    return i;
}