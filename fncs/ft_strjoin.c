//
// Created by grafsky on 11/20/22.
//
#include "../ft_ls.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
    char			*dest;
    unsigned int	i;

    i = 0;
    if (s1 == NULL || s2 == NULL)
        return (NULL);
    dest = (char*)malloc(sizeof(*dest) * (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
    if (dest == NULL)
        return (NULL);
    while (*s1 != '\0')
        dest[i++] = *s1++;
    while (*s2 != '\0')
        dest[i++] = *s2++;
    dest[i] = '\0';
    return (dest);
}