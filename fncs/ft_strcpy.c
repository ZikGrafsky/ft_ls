//
// Created by grafsky on 11/20/22.
//
#include "../ft_ls.h"

char *ft_strcpy(char *dest, char *src)
{
    int i = -1;

    while (src[++i] != '\0')
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}