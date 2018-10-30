#ifndef __FD_H__
#define __FD_H__

#include "types.h"

#define FD_MAX 32

#define OPEN_READ       0x1
#define OPEN_WRITE      0x2 
#define OPEN_BIN        0x4
#define OPEN_APPEND     0x8
#define OPEN_ERASE      0x10
#define OPEN_DIR        0x20
#define OPEN_LINK       0x40

#define LS_ALL       0x1

/* declare dirent, not include */
#ifndef __DIRENT_H__
struct dirent;
#endif

/* set of operations callback for fd */
struct fd_operations
{
    size_t (*readline)(inode_t, fsize_t, char *, char term);
    size_t (*print)(inode_t, fsize_t, const char *);
    size_t (*append)(inode_t, fsize_t*, const char *);

    size_t (*read)(inode_t, fsize_t, void *, size_t);
    size_t (*write)(inode_t, fsize_t, const void *, size_t);
    size_t (*bin_append)(inode_t, fsize_t*, const void *, size_t);

    size_t (*ls)(inode_t, struct dirent *, uint8_t);
    size_t (*find)(inode_t, struct dirent *, const char *);
    int8_t (*mkdir)(inode_t, const char *);
    int8_t (*rmdir)(inode_t, const char *);
    int8_t (*touch)(inode_t, const char *);
    int8_t (*rm)(inode_t, const char *);
    int8_t (*ln)(inode_t, const char *, const char *);

    int8_t (*special)(inode_t, void *, size_t);
};

/* file descriptor */
struct file_desc
{
    inode_t                 inode;  // inode pointed
    fsize_t                 seek;   // virtual seek
    devsize_t               begin;  // beginning of blocks
    struct fd_operations    opers;  // bound operations
};

/* bitmap of used file descriptors */
extern struct uint8_t fd_bmap[FD_TABLE_SIZE / 8];

/* table of file descriptors */
extern struct file_desc fd_table[FD_TABLE_SIZE];

/* returns a free file descriptor */
int8_t __fd_new();

/* opens a file streaming of the cwd */
int8_t __open_c_inode(uint8_t flags);

/* opens a file streaming by a path */
int8_t open(const char *path, uint8_t flags); 

/* list content of directory */
size_t ls(int8_t fd, struct dirent *buf, uint8_t all);

/* find name through the directory entries */
size_t find(int8_t fd, struct dirent *buf, const char *name);

/* creates a new directory inside fd with the specified name */
int8_t mkdir(int8_t fd, const char *name);

/* creates a new file inside fd with the specified name */
int8_t touch(int8_t fd, const char *name);

/* creates a new symlink inside fd with the specified name */
int8_t ln(int8_t fd, const char *name);

/* change virtual seek position of the fd */
int8_t seek(int8_t fd, fsize_t pos);

/* reads a string from the fd until the terminator is reached */
size_t readline(int8_t fd, char *buf, char term);

/* writes a string into the fd */
int8_t print(int8_t fd, const char *str);

/* reads n bytes from the fd */
size_t read(int8_t fd, void *buf, size_t n);

/* writes n bytes into the fd */
int8_t write(int8_t fd, const void *buf, size_t n);

/* frees fd space */
void close(int8_t fd);

#endif  // __FD_H__
