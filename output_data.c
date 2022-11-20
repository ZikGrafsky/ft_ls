//
// Created by grafsky on 11/20/22.
//
#include "ft_ls.h"

void output_data(char **data, t_options *out_options){
    for (int i = 0; i < duarrlen(data); ++i) {
        int j = out_options->r_flag ? duarrlen(data) - i - 1 : i;
        write(1, data[j], ft_strlen(data[j]));
        if (out_options->l_flag)
            write(1, "\n\r", 2);
        else
            write(1, "  ", 2);
    }
}