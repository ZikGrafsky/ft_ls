//
// Created by grafsky on 11/20/22.
//
#include "../ft_ls.h"

char **get_output_data(char **args, t_options *out_options){
    DIR             *opened = NULL;
    struct dirent   *tmp = NULL;
    struct stat     fileStat;
    char            **output_strings = NULL;

    for (int i = 0; i < duarrlen(args); ++i){
        stat(args[i], &fileStat);
        if (S_ISDIR(fileStat.st_mode)) {
            opened = opendir(args[i]);
            if (duarrlen(args) > 1)
                output_strings = stradd(ft_strjoin(args[i], ":"), output_strings);
            while ((tmp = readdir(opened)) != NULL)
                if (tmp->d_name[0] != '.' || out_options->a_flag) {
                    if (out_options->l_flag) {
                        char *filename = ft_strjoin(args[i], tmp->d_name);
                        stat(filename, &fileStat);
                        output_strings = stradd(get_list_format_data(fileStat, tmp->d_name), output_strings);//NEED REUSE
                        free(filename);
                    } else
                        output_strings = stradd(tmp->d_name, output_strings);
                }
            closedir(opened);
//                free(opened);
        } else{
            if (out_options->l_flag) {
                output_strings = stradd(get_list_format_data(fileStat, args[i]), output_strings);//NEED REUSE
            } else
                output_strings = stradd(args[i], output_strings);
        }
    }
//    output_strings = out_options->t_flag ? duarrtsort(output_strings) : duarrbsort(output_strings);
    return output_strings;
}