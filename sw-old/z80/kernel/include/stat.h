#ifndef __STAT_H__
#define __STAT_H__

#include "types.h"

struct stat
{
    inode_t     inode;      /* inode reference */

    uint        mode :3;    /* mode */
    uint        uid :3;     /* owner id */
    uint        type :2;    /* file, dir or link */

    devsize_t   size;       /* file size */

    size_t      blk_size;   /* single block size */
    size_t      blk_used;   /* blocks used by the file */

    time_t      ctime;      /* creation time */
}

struct stat * stat(const char *path, struct stat *buffer);

#endif  // __STAT_H__
