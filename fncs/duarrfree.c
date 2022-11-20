//
// Created by grafsky on 11/20/22.
//
#include "../ft_ls.h"

char	**duarrfree(char **arr)
{
    int	i;

    if (!arr || !*arr)
        return (NULL);
    i = 0;
    while (arr[i])
    {
        if (arr[i])
            free(arr[i]);
        arr[i] = NULL;
        i++;
    }
    free(arr);
    arr = NULL;
    return (NULL);
}