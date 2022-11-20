//
// Created by grafsky on 11/20/22.
//
#include "../ft_ls.h"



char    *get_groupname(gid_t gid){
    struct group *grp;
    grp = getgrgid(gid);
    return grp->gr_name;
}



