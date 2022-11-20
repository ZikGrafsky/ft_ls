//
// Created by grafsky on 11/20/22.
//
#include "ft_ls.h"

char **duarrtsort(char **arr){//time - sort by time
    for(int i = 0; i < duarrlen(arr); ++i)
        for (int j = 0; j < duarrlen(arr) - i - 1; ++j){
            struct stat firstStat, secondStat;
            stat(arr[j], &firstStat);
            stat(arr[j + 1], &secondStat);
            if(firstStat.st_atime < secondStat.st_atime){
                char *str = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = str;
            }
        }
    return arr;
}