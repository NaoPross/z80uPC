#ifndef INODE_H
#define INODE_H

#include "types.h"

#define FS_OFFSET 0x1000

#define FS_BLOCKS_SIZE 512
#define FS_BLOCKS_N     8
#define FS_BLOCKS_IND   6

#define INODE_TYPE_FILE   0x0
#define INODE_TYPE_DIR    0x1
#define INODE_TYPE_HLINK    0x2
#define INODE_TYPE_SLINK    0x3

typedef struct time_s
{
    struct
    {
        uint    minutes :6;
        uint    hour    :5;

    } time;

    struct
    {
        uint    day     :5;
        uint    month   :4;
        uint    year    :12;

    } date;

} time_t;

struct fs_superblock
{
    uint8_t     magic;           // identifier

    uint16_t    blk_size;           // size of a single block
    uint16_t    imap_size;          // quantity of inodes
    uint16_t    dmap_size;          // quantity of blocks
}

struct fs_inode
{
    
    /* inode meta data */
    uint        mode :3;  // chmod
    uint        uid :3;   // chown
    uint        type :2;  // file, dir, hard-link, sym-link

    /* data storage informations */
    uint24_t     size;
    uint16_t     blocks[FS_BLOCKS_N];

}

struct fs_inumber
{
    uint    dev : 4;    // device id, global in the fs
    ino_t   rel;    // inode id relative to the volume
}

#endif
