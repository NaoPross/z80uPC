#ifndef DIRENT_H
#define DIRENT_H

#include "types.h"

struct dirent
{
    ino_t       i_number;       // inode referred
    uint8_t     name_size;    // size of the name
    char        name[];         // name of the referred inode
}

#endif
