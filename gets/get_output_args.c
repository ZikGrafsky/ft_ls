//
// Created by grafsky on 11/20/22.
//
#include "../ft_ls.h"

char **get_output_args(char **args, int number){
    int string_pos = 0;
    char **out_list = NULL;

    while (++string_pos < number)
        if (args[string_pos][0] != '-')
            out_list = stradd(args[string_pos], out_list);
    return out_list;
}