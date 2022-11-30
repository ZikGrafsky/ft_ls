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
            if (duarrlen(args) > 1) {
                char *tmp = ft_strjoin(args[i], ":");
                output_strings = stradd(tmp, output_strings);
                free(tmp);
            }
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
        } else{
            if (out_options->l_flag) {
                output_strings = stradd(get_list_format_data(fileStat, args[i]), output_strings);//NEED REUSE
            } else
                output_strings = stradd(args[i], output_strings);
            output_strings = stradd("\n\n", output_strings);
        }
    }
    return output_strings;
}

//char **sort_by_dir(char **list){
//    char  **tmp = NULL;
//
//    for (int i = 0; i < duarrlen(list); ++i) {
//        if ()
//    }
//    return tmp;
//}

char **duarrfpte(char **arr, int pos){//fpte - from position to end
    char *tmp = NULL;

    if(arr && arr[pos]){
        tmp = arr[pos];
        arr[pos] = arr[duarrlen(arr) - 1];
        arr[duarrlen(arr) - 1] = tmp;
    }
    return arr;
}

char **duarrconcat(char **first_arr, char **second_arr){
    char    **resulr_arr = NULL;

    resulr_arr = first_arr == NULL ? second_arr : first_arr;
    for (int i = 0; resulr_arr && i < duarrlen(second_arr); ++i)
        resulr_arr = stradd(second_arr[i], first_arr);
    return resulr_arr;
}