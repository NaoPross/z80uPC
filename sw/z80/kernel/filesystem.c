#include "filesystem.h"

struct filesystem * fs_parse_superblock(struct filesystem *fs)
{

}

/* resolves an arbitrary path */                                              
uint16_t fs_parse_path(const char *path)
{

}

/* gets inode from inumber */                                                   
inode_t * fs_get_inode(inode_t *buffer, uint16_t i_number)
{

}

inode_t * fs_new_inode(inode_t *inode, const char *name)
{

}

int fs_free_inode(const inode_t *inode)
{

}

void fs_chmod(inode_t *inode, uint8_t mode)
{

}

void fs_chown(inode_t *inode, uint8_t uid)
{

}

int fs_rename(inode_t *inode, const char *name)
{

}

