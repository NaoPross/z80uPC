#ifndef USERS_H
#define USERS_H

#include "types.h"

#define USERS_MAX   8
#define USER_ROOT   0 

/* current user in use */
extern struct fs_user c_user;

struct fs_user
{
    char        name[32];
    ino_t       home;
    uint8_t     perm;       // TODO, permissions 
};

/* all users are in rom device */

#endif
