//
// Created by grafsky on 11/20/22.
//
#include "../ft_ls.h"

char	**stradd(char *str, char **dst)
{
    int		i;
    char	**tmp;

    if (!str)
        return (0);
    tmp = (char **)malloc(sizeof (char *) * (duarrlen(dst) + 2));
    if (!tmp)
        return (dst);
    i = 0;
    while (dst && i < duarrlen(dst))
    {
        tmp[i] = ft_strdup(dst[i]);
        i++;
    }
    tmp[i++] = ft_strdup(str);
    tmp[i] = NULL;
    duarrfree(dst);
    return (tmp);
}