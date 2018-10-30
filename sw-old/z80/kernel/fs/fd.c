#include "fs/fd.h"
#include "fs/fdop.h"
#include "fs/fs.h"

/* from fd.h */
struct file_desc fd_table[FD_TABLE_SIZE];
struct uint8_t  fd_bmap[FD_TABLE_SIZE / 8];

/* File descriptors implementation */

int8_t open(const char *path, uint8_t flags)
{
    // TODO
    return 0; 
}

size_t ls(int8_t fd, struct dirent *buf, uint8_t all)
{
    // TODO
    return 0; 
}

size_t find(int8_t fd, struct dirent *buf, const char *name)
{
    // TODO
    return 0; 
}

int8_t mkdir(int8_t fd, const char *name)
{
    // TODO
    return 0; 
}

int8_t touch(int8_t fd, const char *name)
{
    // TODO
    return 0; 
}

int8_t ln(int8_t fd, const char *name)
{
    // TODO
    return 0; 
}

int8_t seek(int8_t fd, fsize_t pos)
{
    // TODO
    return 0; 
}

size_t readline(int8_t fd, char *buf, char term)
{
    // TODO
    return 0; 
}

int8_t print(int8_t fd, const char *str)
{
    // TODO
    return 0; 
}

size_t read(int8_t fd, void *buf, size_t n)
{
    // TODO
    return 0; 
}

int8_t write(int8_t fd, const void *buf, size_t n)
{
    // TODO
    return 0; 
}

void close(int8_t fd)
{
    // TODO
    return 0; 
}

/* Set of file descriptors operations */
/* Determines if to use the serial interface or the address space */

/* Address space section */

/* File functions */

size_t as_readline(inode_t inode, fsize_t seek, char *buf, char term)
{
    // TODO
    return 0;
}

size_t as_print(inode_t inode, fsize_t seek, const char *str)
{
    // TODO
    return 0;
}

size_t as_append(inode_t inode, fsize_t *seek_ptr, const char *str)
{
    // TODO
    return 0;
}

size_t as_read(inode_t inode, fsize_t seek, void *buf, size_t n)
{
    // TODO
    return 0;
}

size_t as_write(inode_t inode, fsize_t seek, const void *buf, size_t n)
{
    // TODO
    return 0;
}

size_t as_bin_append(inode_t inode, fsize_t *seek_ptr, const void *buf, size_t
n)
{
    // TODO
    return 0;
}

/* Directory functions */

size_t as_ls(inode_t inode, struct dirent *buf, uint8_t all)
{
    // TODO
    return 0;
}

size_t as_find(inode_t inode, struct dirent *buf, const char *name)
{
    // TODO
    return 0;
}

int8_t as_mkdir(inode_t inode, const char *name)
{
    // TODO
    return 0;
}

int8_t as_rmdir(inode_t inode, const char *name)
{
    // TODO
    return 0;
}

int8_t as_touch(inode_t inode, const char *name)
{
    // TODO
    return 0;
}

int8_t as_rm(inode_t inode, const char *name)
{
    // TODO
    return 0;
}

int8_t as_ln(inode_t inode, const char *path, const char *name)
{
    // TODO
    return 0;
}

/* Serial Space section */
/* Warning, it doesn't switch to the right driver */

/* File functions */

size_t ss_readline(inode_t inode, fsize_t seek, char *buf, char term)
{
    // TODO
    return 0;
}

size_t ss_print(inode_t inode, fsize_t seek, const char *str)
{
    // TODO
    return 0;
}

size_t ss_append(inode_t inode, fsize_t *seek_ptr, const char *str)
{
    // TODO
    return 0;
}

size_t ss_read(inode_t inode, fsize_t seek, void *buf, size_t n)
{
    // TODO
    return 0;
}

size_t ss_write(inode_t inode, fsize_t seek, const void *buf, size_t n)
{
    // TODO
    return 0;
}

size_t ss_bin_append(inode_t inode, fsize_t *seek_ptr, const void *buf, size_t
n)
{
    // TODO
    return 0;
}

/* Directory functions */

size_t ss_ls(inode_t inode, struct dirent *buf, uint8_t all)
{
    // TODO
    return 0;
}

size_t ss_find(inode_t inode, struct dirent *buf, const char *name)
{
    // TODO
    return 0;
}

int8_t ss_mkdir(inode_t inode, const char *name)
{
    // TODO
    return 0;
}

int8_t ss_rmdir(inode_t inode, const char *name)
{
    // TODO
    return 0;
}

int8_t ss_touch(inode_t inode, const char *name)
{
    // TODO
    return 0;
}

int8_t ss_rm(inode_t inode, const char *name)
{
    // TODO
    return 0;
}

int8_t ss_ln(inode_t, const char *path, const char *name)
{
    // TODO
    return 0;
}
