#ifndef __FS_H__
#define __FS_H__

#include "types.h"

#define FS_OFFSET 0x1000

#define FS_BLOCKS_SIZE 512
#define FS_BLOCKS_N     8
#define FS_BLOCKS_IND   6

#define INODE_TYPE_FILE   0x0
#define INODE_TYPE_DIR    0x1
#define INODE_TYPE_SLINK    0x2
#define INODE_TYPE_SPECIAL  0x3

#define INODE_META_SIZE 8

/* inode basic structure */
struct fs_inode
{
    /* inode meta data */

    uint        mode :3;  // chmod
    uint        uid :3;   // chown
    uint        type :2;  // file, dir, sym-link, special

    time_t      ctime;          // creation time

    uint24_t     size;              // inode size

    /* data storage informations */
    /* it doesn't allocate memory, virtual size FS_BLOCKS_N */ 
    blk_t     blocks[];
};

#define FS_DEV_ROM      0x7f    /* 01111111 */
#define FS_DEV_NULL     0x80    /* 10000000 */

#define FS_ROM_SPACE    0x2000  // second rom 

#define FS_INO_ROOT   0x0       // first inode

#define FS_INODE_ROOT(inode)   {inode.dev = 0xff; inode.inode = 0x0}
#define FS_INODE_NULL(inode)   {inode.dev = 0x80; inode.inode = 0x0}

#define FS_USE_ROM(inode)   inode.dev == 0x7f

/* get block seek in current device */
devsize_t fs_block(blk_t block);

/* get common inode seek in current device */
/* c_inode must be set first */
/* returns seek at the beginning of blocks field */
devsize_t fs_inode(struct fs_inode *buf);

/* common inode for syscalls */
extern inode_t c_inode;

/* parse a path, absolute or relative to c_inode */
inode_t fs_parse_path(const char *path);

#endif  // __FS_H__
