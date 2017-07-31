#ifndef __FILESYSTEM_H__
#define __FILESYSTEM_H__

#include "types.h"

#define FS_OFFSET 0x1000

#define FS_BLOCK_SIZE   512
#define FS_BLOCKS_N     12
/* #define FS_IBLOCKS_N     1 */

#define INODE_TYPE_FILE 0
#define INODE_TYPE_DIR  1
#define INODE_TYPE_LINK 2

typedef struct time_s
{
    uint16_t time;
    uint16_t date;
} time_t;


/* on-disk structures */
struct fs_superblock
{
    uint8_t     magic;
    uint16_t    blk_size;   /* default is 512 bytes */
    uint16_t    imap_size;  /* size of the inode bitmap in blocks */
    uint16_t    dmap_size;  /* size of the data blocks map in blocks */
};


struct fs_blk
{
    uint    size;
};

typedef struct fs_inode
{
    uint        i_used :1; // inode is free
    uint        i_mode :3; // inode mode (rwx)

    uint8_t     i_uid;     // user (owner) id
    uint16_t    i_number;  // identifier

    uint16_t    i_blocks;  // number of blocks

    struct fs_blk   i_block[FS_BLOCKS_N];   // direct blocks
/*    struct fs_blk   i_iblock[FS_IBLOCKS_N]; // indirect blocks */
    
    inode_t     *parent;
} inode_t;

/* inode table structures */
struct fs_inode_entry
{
    uint16_t    i_number;
    uint8_t     str_len;
    char        name[24];
};

/* filesystem struct for the operating system */
struct filesystem
{
    size_t size;
    size_t fsize;
    inode_t *mntpt;
};

void fs_parse_superblock(struct filesystem *fs);

void fs_write_imap();
void fs_write_dmap();

/* void fs_ */

#endif // __FILESYSTEM_H__
