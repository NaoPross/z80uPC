#ifndef MOUNT_H
#define MOUNT_H

#include "fs.h"

#define FS_MOUNT_LIMIT 16

struct fs_mount_point
{
    struct fs_inumber       inode;          // dir mounted
    uint                    serial_port :4;
    struct fs_superblock    superblock;     // block informations
}

#endif
