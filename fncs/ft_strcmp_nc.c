//
// Created by grafsky on 11/20/22.
//
#include "../ft_ls.h"

int	ft_strcmp_nc(char *s1, char *s2)//nc - no case
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && to_lower(s1[i]) == to_lower(s2[i]))
        i++;
    return (to_lower(s1[i]) - to_lower(s2[i]));
}