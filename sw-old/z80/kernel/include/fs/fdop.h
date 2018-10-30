#ifndef __FDOP_H__
#define __FDOP_H__

#include "types.h"

#ifndef __DIRENT_H__
struct dirent;
#endif

/* macro for direct binding */

#define FD_BIND_AS_DIR(oper)    {       \
                                    oper.ls = &as_ls;   \
                                    oper.find = &as_find; \
                                    oper.mkdir = &as_mkdir; \
                                    oper.rmdir = &as_rmdir; \
                                    oper.touch = &as_touch; \
                                    oper.rm = &as_rm; \
                                    oper.ln = &as_ln; \
                                }

#define FD_BIND_SS_DIR(oper)    {       \
                                    oper.ls = &ss_ls;   \
                                    oper.find = &ss_find; \
                                    oper.mkdir = &ss_mkdir; \
                                    oper.rmdir = &ss_rmdir; \
                                    oper.touch = &ss_touch; \
                                    oper.rm = &ss_rm; \
                                    oper.ln = &ss_ln; \
                                }

#define FD_BIND_AS_FILE(opers, flags) {      \
                                    if (flags & OPEN_READ)  \
                                        opers.readline = as_readline;   \
                                    if (flags & OPEN_APPEND)    \
                                        opers.append = as_append;   \
                                    else if (flags & OPEN_WRITE)    \
                                        opers.print = as_print;     \
                                    }

#define FD_BIND_SS_FILE(opers, flags) {      \
                                    if (flags & OPEN_READ)  \
                                        opers.readline = ss_readline;   \
                                    if (flags & OPEN_APPEND)    \
                                        opers.append = ss_append;   \
                                    else if (flags & OPEN_WRITE)    \
                                        opers.print = ss_print;     \
                                     }

#define FD_BIND_AS_BINFILE(opers, flags) {     \
                                        if (flags & OPEN_READ)  \
                                            opers.read = as_read;   \
                                        if (flags & OPEN_APPEND)    \
                                            opers.bin_append = as_bin_append;   \
                                        else if (flags & OPEN_WRITE)    \
                                            opers.write = as_write;     \
                                        }

#define FD_BIND_SS_BINFILE(opers, flags) {     \
                                        if (flags & OPEN_READ)  \
                                            opers.read = ss_read;   \
                                        if (flags & OPEN_APPEND)    \
                                            opers.bin_append = ss_bin_append;   \
                                        else if (flags & OPEN_WRITE)    \
                                            opers.write = ss_write;     \
                                        }

/* Set of file descriptors operations */
/* Determines if to use the serial interface or the address space */

/* Address space section */

/* File functions */

size_t as_readline(inode_t inode, fsize_t seek, char *buf, char term);

size_t as_print(inode_t inode, fsize_t seek, const char *str);

size_t as_append(inode_t inode, fsize_t *seek_ptr, const char *str);


size_t as_read(inode_t inode, fsize_t seek, void *buf, size_t n);

size_t as_write(inode_t inode, fsize_t seek, const void *buf, size_t n);

size_t as_bin_append(inode_t inode, fsize_t *seek_ptr, const void *buf, size_t
n);

/* Directory functions */

size_t as_ls(inode_t inode, struct dirent *buf, uint8_t all);

size_t as_find(inode_t inode, struct dirent *buf, const char *name);

int8_t as_mkdir(inode_t inode, const char *name);

int8_t as_rmdir(inode_t inode, const char *name);

int8_t as_touch(inode_t inode, const char *name);

int8_t as_rm(inode_t inode, const char *name);

int8_t as_ln(inode_t inode, const char *path, const char *name);

/* Serial Space section */
/* Warning, it doesn't switch to the right driver */

/* File functions */

size_t ss_readline(inode_t inode, fsize_t seek, char *buf, char term);

size_t ss_print(inode_t inode, fsize_t seek, const char *str);

size_t ss_append(inode_t inode, fsize_t *seek_ptr, const char *str);


size_t ss_read(inode_t inode, fsize_t seek, void *buf, size_t n);

size_t ss_write(inode_t inode, fsize_t seek, const void *buf, size_t n);

size_t ss_bin_append(inode_t inode, fsize_t *seek_ptr, const void *buf, size_t
n);

/* Directory functions */

size_t ss_ls(inode_t inode, struct dirent *buf, uint8_t all);

size_t ss_find(inode_t inode, struct dirent *buf, const char *name);

int8_t ss_mkdir(inode_t inode, const char *name);

int8_t ss_rmdir(inode_t inode, const char *name);

int8_t ss_touch(inode_t inode, const char *name);

int8_t ss_rm(inode_t inode, const char *name);

int8_t ss_ln(inode_t, const char *path, const char *name);

#endif // __FDOP_H__
