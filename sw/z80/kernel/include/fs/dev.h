#ifndef DEV_H
#define DEV_H

#include "types.h"

#define FS_MOUNT_LIMIT 16

struct fs_superblock
{
    uint8_t     magic;           // identifier

    size_t      blk_size;           // size of a single block
    size_t      imap_size;          // quantity of inodes
    size_t      dmap_size;          // quantity of blocks
};

struct fs_dev
{
    uint                    enabled :1;     // in use
    uint                    port_no :3;     // serial port number
    uint                            :4; 
    inode_t                 inode;          // dir mounted
    struct fs_superblock    superblock;     // block informations
};

/* list of devices */ 
extern struct fs_dev devices[FS_MOUNT_LIMIT];

#endif
