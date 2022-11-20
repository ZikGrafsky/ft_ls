//
// Created by grafsky on 11/20/22.
//
#include "ft_ls.h"

int ft_ls(int argc, char **argv){
    t_options   *out_options = get_output_options(argv, argc);//Gather Options
    char        **out_list = NULL;
    char        **out_data;

    if (argc > 1)
        out_list = get_output_args(argv, argc);//Gather the names
    if (argc == 1 || out_list == NULL)
        out_list = stradd("./", out_list);
    out_data = get_output_data(out_list, out_options);
    output_data(out_data, out_options);
    return (0);
}