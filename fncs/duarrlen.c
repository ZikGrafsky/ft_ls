//
// Created by grafsky on 11/20/22.
//
#include "../ft_ls.h"

int	duarrlen(char **array)
{
    int	i = 0;

    while (array && array[i])
        i++;
    return (i);
}