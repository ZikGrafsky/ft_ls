//
// Created by grafsky on 11/20/22.
//
#include "../ft_ls.h"

char **duarrbsort(char **arr){//bubble - sort method
    for(int i = 0; i < duarrlen(arr); ++i)
        for (int j = 0; j < duarrlen(arr) - i - 1; ++j)
            if(ft_strcmp_nc(arr[j], arr[j+1]) > 0){
                char *str = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = str;
            }
    return arr;
}