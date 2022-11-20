//
// Created by grafsky on 11/20/22.
//
#include "../ft_ls.h"

char	*ft_strchr(const char *s, int c)
{
    char	*str = (char *)s;

    while (*str != c || *str != '\0')
        str++;
    return (*str == '\0' ? NULL : str);
}