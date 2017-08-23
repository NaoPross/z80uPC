#ifndef __FILESYSTEM_H__
#define __FILESYSTEM_H__

#include "types.h"

#define FS_OFFSET 0x1000

#define FS_BLOCKS_SIZE 512
#define FS_BLOCKS_N     12

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
    uint        magic :5;           /* identifier */
    uint        serial_port :3;     /* serial port id from serial.h */
    uint16_t    blk_size;           /* default is 512 bytes */
    uint16_t    imap_size;          /* size of the inode table in blocks */
    uint16_t    dmap_size;          /* size of the data blocks map in blocks */
};


struct fs_blk_entry
{
    uint16_t b_number;      /* block number */
    uint16_t data_size;     /* bytes used   */
};

typedef struct fs_inode
{

    uint16_t    i_number;       /* identifier */

    uint        i_mode :3;      /* inode mode (rwx) */
    uint        i_uid :3;       /* user (owner) id  */
    uint        i_type :2;      /* inode type */

    uint8_t     i_blocks;       /* number of blocks */
    struct fs_blk_entry   i_block[FS_BLOCKS_N];   /* direct blocks */
    
    uint16_t     parent;

} inode_t;

/* inode table structures */
/* i_number is derived from location */
struct fs_inode_entry
{
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

struct filesystem * fs_parse_superblock(struct filesystem *fs);

/* resolves an arbitrary path */
uint16_t fs_parse_path(const char *path);

/* gets inode from inumber */
inode_t * fs_get_inode(inode_t *buffer, uint16_t i_number);

inode_t * fs_new_inode(inode_t *inode, const char *name);

int fs_free_inode(const inode_t *inode);

void fs_chmod(inode_t *inode, uint8_t mode);

void fs_chown(inode_t *inode, uint8_t uid);

int fs_rename(inode_t *inode, const char *name);


#endif // __FILESYSTEM_H__
