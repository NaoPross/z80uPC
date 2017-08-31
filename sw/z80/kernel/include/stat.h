#ifndef STAT_H
#define STAT_H

struct stat
{
    dev_t dev;        /* device id */
    ino_t       inumber;    /* inode number inside the volume */

    uint        mode :3;    /* mode */
    uint        uid :3;     /* owner id */
    uint        type :2;    /* file, dir or link */

    devsize_t   size;       /* file size */

    size_t      blk_size;   /* single block size */
    size_t      blk_used;   /* blocks used by the file */

    time_t      ctime;      /* creation time */
}

struct stat * stat(const char *path, struct stat *buffer);
struct stat * lstat(const char *link, struct stat *buffer);

#endif
