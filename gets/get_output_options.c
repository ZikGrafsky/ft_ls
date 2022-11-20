//
// Created by grafsky on 11/20/22.
//
#include "../ft_ls.h"

t_options *get_output_options(char **args, int number){
    t_options *out_options = (t_options *)malloc(sizeof (t_options));
    int string_pos, sym_pos;
    string_pos = 1;

    out_options->a_flag = false;
    out_options->R_flag = false;
    out_options->r_flag = false;
    out_options->l_flag = false;
    out_options->t_flag = false;
    while (string_pos < number){
        if (args[string_pos][0] == '-') {
            sym_pos = 0;
            while (++sym_pos < ft_strlen(args[string_pos])){
                if (args[string_pos][sym_pos] == 'a')
                    out_options->a_flag = true;
                else if (args[string_pos][sym_pos] == 'R')
                    out_options->R_flag = true;
                else if (args[string_pos][sym_pos] == 'r')
                    out_options->r_flag = true;
                else if (args[string_pos][sym_pos] == 'l')
                    out_options->l_flag = true;
                else if (args[string_pos][sym_pos] == 't')
                    out_options->t_flag = true;
                else
                {
                    write(2, "ft_ls: invalid option -- \'", ft_strlen("ft_ls: invalid option -- \'"));
                    write(2, &args[string_pos][sym_pos], 1);
                    write(2, "\'", 1);
                    exit(EINVAL);
                }
            }
        }
        string_pos++;
    }
    return out_options;
}