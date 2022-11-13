//
// Created by grafsky on 11/12/22.
// clang -std=c99 main.c
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdbool.h>
#include <errno.h>

typedef struct s_options{
    bool    a_flag;
    bool    R_flag;
    bool    r_flag;
    bool    l_flag;
    bool    t_flag;
}t_options;


char	    *ft_strchr(const char *s, int c);
int         ft_strlen(char *str);
char        *ft_strcpy(char *dest, char *src);
char        *get_permissions(struct stat fileStat);
int         ft_atoi(const char *str);
char	    *ft_itoa(int nb);
char        *get_username(uid_t uid);
char        *get_groupname(gid_t gid);
t_options   *get_output_options(char **args, int number);
char        **get_output_args(char **args, int number);
char	    **stradd(char *str, char **dst);
int         duarrlen(char **array);
char	    **duarrfree(char **arr);
char    	*ft_strdup(const char *s1);
char        **get_output_data(char **args, t_options *out_options);
int         ft_strcmp_nc(char *s1, char *s2);
char        to_lower(char chr);
char        **duarrbsort(char **arr);


int main(int argc, char **argv){
    t_options   *out_options = get_output_options(argv, argc);//Gather Options
    char        **out_list;

    if (argc > 1)
        out_list = get_output_args(argv, argc);//Gather the names
    if (argc == 1 || out_list == NULL)
        out_list = stradd("./", out_list);
    get_output_data(out_list, out_options);
//    char linkdata[1024];
//    readlink("./kek", linkdata, 1024);
//    printf("%s", linkdata);
//    while (tmp != NULL) {
//        lstat(tmp->d_name, &fileStat);
//        write(1, get_permissions(fileStat), 10);
//        write(1, "\t", 1);
//        write(1, ft_itoa((int) fileStat.st_nlink), ft_strlen(ft_itoa((int) fileStat.st_nlink)));
//        write(1, "\t", 1);
//        write(1, get_username(fileStat.st_uid), ft_strlen(get_username(fileStat.st_uid)));
//        write(1, "\t", 1);
//        write(1, get_groupname(fileStat.st_gid), ft_strlen(get_groupname(fileStat.st_gid)));
//        write(1, "\t", 1);
//        write(1, ft_itoa((int) fileStat.st_size), ft_strlen(ft_itoa( fileStat.st_size)));
//        write(1, "\t", 1);
//        write(1, ctime(&fileStat.st_atime), ft_strlen(ctime(&fileStat.st_atime)) - 1);
//        write(1, "\t", 1);
//        write(1, tmp->d_name, ft_strlen(tmp->d_name));
//        write(1, "\n", 1);
////        free(&fileStat);
//        tmp = readdir(opened);
//    }
//    closedir(opened);
    return 0;
}

char **get_output_data(char **args, t_options *out_options){
    DIR             *opened = NULL;
    struct dirent   *tmp = NULL;
    struct stat     fileStat;
    char            **output_strings = NULL;

    for (int i = 0; i < duarrlen(args); ++i) {
        opened = opendir(args[i]);
        while ((tmp = readdir(opened)) != NULL)
            if (tmp->d_name[0] != '.' || out_options->a_flag)
                output_strings = stradd(tmp->d_name, output_strings);
        closedir(opened);
    }
    output_strings = duarrbsort(output_strings);

    for (int i = 0; i < duarrlen(output_strings); ++i) {
        printf("%s  ", output_strings[i]);
    }
    return NULL;
}

char **duarrbsort(char **arr){
    for(int i = 0; i < duarrlen(arr); ++i)
        for (int j = 0; j < duarrlen(arr) - i - 1; ++j)
            if(ft_strcmp_nc(arr[j], arr[j+1]) > 0){
                char *str = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = str;
            }
    return arr;
}

char to_lower(char chr){
    return (chr >= 'A' && chr <= 'Z') ? (chr + ('a' - 'A')) : chr;
}

int	ft_strcmp_nc(char *s1, char *s2)//nc - no case
{
    int i;

    i = 0;
    while (to_lower(s1[i]) == to_lower(s2[i]) && s1[i] != '\0' && s2[i] != '\0')
        i++;
    return (to_lower(s1[i]) - to_lower(s2[i]));
}



//_____________________________functions___________________________
char **get_output_args(char **args, int number){
    int string_pos = 0;
    char **out_list = NULL;

    while (++string_pos < number)
        if (args[string_pos][0] != '-')
            out_list = stradd(args[string_pos], out_list);
    return out_list;
}

char	**stradd(char *str, char **dst)
{
    int		i;
    char	**tmp;

    if (!str)
        return (0);
    i = 0;
    tmp = (char **)malloc(sizeof (char *) * (duarrlen(dst) + 2));
    if (!tmp)
        return (dst);
    while (dst && i < duarrlen(dst))
    {
        tmp[i] = ft_strdup(dst[i]);
        i++;
    }
    tmp[i++] = ft_strdup(str);
    tmp[i] = NULL;
    duarrfree(dst);
    return (tmp);
}

char	*ft_strdup(const char *s1)
{
    char	*str;
    size_t	i;
    size_t	lens;

    i = 0;
    lens = ft_strlen((char *)s1);
    if (!s1)
        return (0);
    str = (char *)malloc(sizeof(char) * lens + 1);
    if (str == NULL)
        return (0);
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

int	duarrlen(char **array)
{
    int	i;

    i = 0;
    while (array && array[i])
        i++;
    return (i);
}

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

char	*ft_strchr(const char *s, int c)
{
    char	*str = (char *)s;

    while (*str != c || *str != '\0')
        str++;
    return (*str == '\0' ? NULL : str);
}

int ft_strlen(char *str){
    int i = 0;
    while (str[++i]!='\0');
    return i;
}

char *ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *get_permissions(struct stat fileStat){
    char *permissions = malloc(sizeof(char) * 10);
    permissions[0] = (S_ISDIR(fileStat.st_mode)) ? 'd' : '-';
    permissions[0] = (S_ISLNK(fileStat.st_mode)) ? 'l' : '-';
    permissions[1] = (fileStat.st_mode & S_IRUSR) ? 'r' : '-';
    permissions[2] = (fileStat.st_mode & S_IWUSR) ? 'w' : '-';
    permissions[3] = (fileStat.st_mode & S_IXUSR) ? 'x' : '-';
    permissions[4] = (fileStat.st_mode & S_IRGRP) ? 'r' : '-';
    permissions[5] = (fileStat.st_mode & S_IWGRP) ? 'w' : '-';
    permissions[6] = (fileStat.st_mode & S_IXGRP) ? 'x' : '-';
    permissions[7] = (fileStat.st_mode & S_IROTH) ? 'r' : '-';
    permissions[8] = (fileStat.st_mode & S_IWOTH) ? 'w' : '-';
    permissions[9] = (fileStat.st_mode & S_IXOTH) ? 'x' : '-';
    return permissions;
}

int	ft_atoi(const char *str)
{
    int	res;
    int	negative;

    negative = 1;
    res = 0;
    while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
                    *str == '\v' || *str == '\f' || *str == '\r'))
        ++str;
    if (*str == '-')
        negative = -1;
    if (*str == '-' || *str == '+')
        ++str;
    while (*str && *str >= '0' && *str <= '9')
    {
        res = res * 10 + (*str - 48);
        ++str;
    }
    return (res * negative);
}

int		len(long nb)
{
    int		len;

    len = 0;
    if (nb < 0)
    {
        nb = nb * -1;
        len++;
    }
    while (nb > 0)
    {
        nb = nb / 10;
        len++;
    }
    return (len);
}

char	*ft_itoa(int nb)
{
    char *str;
    long	n;
    int		i;

    n = nb;
    i = len(n);
    if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
        return (NULL);
    str[i--] = '\0';
    if (n == 0)
    {
        str[0] = 48;
        return (str);
    }
    if (n < 0)
    {
        str[0] = '-';
        n = n * -1;
    }
    while (n > 0)
    {
        str[i] = 48 + (n % 10);
        n = n / 10;
        i--;
    }
    return (str);
}

char    *get_username(uid_t uid){
    struct passwd *pws;
    pws = getpwuid(uid);
    return pws->pw_name;
}
char    *get_groupname(gid_t gid){
    struct group *grp;
    grp = getgrgid(gid);
    return grp->gr_name;
}



/*output{
DIR *opened = opendir("./");
struct dirent *tmp = readdir(opened);
struct stat fileStat;

while (tmp != NULL) {
stat(tmp->d_name, &fileStat);
write(1, get_permissions(fileStat), 10);
write(1, "\t", 1);
write(1, ft_itoa((int) fileStat.st_nlink), ft_strlen(ft_itoa((int) fileStat.st_nlink)));
write(1, "\t", 1);
write(1, get_username(fileStat.st_uid), ft_strlen(get_username(fileStat.st_uid)));
write(1, "\t", 1);
write(1, get_groupname(fileStat.st_gid), ft_strlen(get_groupname(fileStat.st_gid)));
write(1, "\t", 1);
write(1, ft_itoa((int) fileStat.st_size), ft_strlen(ft_itoa((int) fileStat.st_size)));
write(1, "\t", 1);
write(1, ctime(&fileStat.st_atime), ft_strlen(ctime(&fileStat.st_atime)) - 1);
write(1, "\t", 1);
write(1, tmp->d_name, ft_strlen(tmp->d_name));
write(1, "\n", 1);
//        free(&fileStat);
tmp = readdir(opened);
}
}*/