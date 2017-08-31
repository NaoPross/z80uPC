#include "fs/fs.h"
#include "fs/users.h"
#include "fs/dev.h"

/* from users.h */
struct fs_user c_user;

/* from inode.h */
inode_t c_inode;

struct fs_dev devices[FS_MOUNT_LIMIT];

/* filesystem basic implementation */

devsize_t fs_block(blk_t block)
{
    // TODO
    return 0;
}

devsize_t fs_inode(struct fs_inode *buf)
{
    struct fs_superblock * sb;
    devsize_t seek;

    if (FS_USE_ROM(c_inode))
    {
        seek = FS_ROM_SPACE;
        sb = (struct fs_superblock*) seek; 

    } else {

        seek = 0;

        if (c_inode.dev > 0x7)
            panic("Invalid device");    // TODO, still to implement

        sb = &devices[c_inode.dev].superblock; 
    }

    if (c_inode.inode >= sb->imap_size)
    {
        // TODO, set errno
        return 0;   // inode doesn't exist
    }

    seek += sizeof(struct fs_superblock) + 
            sizeof(struct fs_inode) * c_inode.inode;

    if (FS_USE_ROM(c_inode))
        *buf = *(struct fs_inode*)seek;
    else
    {
        /* set sio port */
        sio_port = devices[c_inode.dev].port_no;
        sio_seek = seek;

        if (sio_read((void *)buf, INODE_META_SIZE) < INODE_META_SIZE)
        {
            // TODO, set errno
            return 0;   // cannot read to device
        }
    }

    return seek + INODE_META_SIZE;
}

/* from fd.h */
int8_t __fd_new()
{
    int8_t fd;
    for (int8_t = 0; i < FD_TABLE_SIZE / 8; i++)
    {
        for (uint8_t bit = 0x80, j = 0; bit > 0; bit >>= 1, j++)
        {
            if (!(bit & fd_bmap[i]))
                return i * 8 + j;
        }
    }

    return -1;
}

/* from fd.h */
int8_t __open_c_inode(uint8_t flags)
{
    /* read meta data */
    struct fs_inode inode;

    /* init file_desc buffer */
    struct file_desc desc = {c_inode, 0};
    
    desc.begin = fs_inode(&inode);
    
    /* bind operations */

    if (flags & OPEN_DIR)
    {
        /* dir handler */

        if (inode.type == INODE_TYPE_DIR)
        {
            /* bind dir functions */
            if (FS_USE_ROM(c_inode))
                /* bind address space functions */
                FD_BIND_AS_DIR(desc.opers)
            else
                /* bind serial space functions */
                FD_BIND_SS_DIR(desc.opers)

        } else {

            // TODO, set errno
            return -1;  // not a directory
        }

    } else if (flags & OPEN_LINK) {
        
        /* link handler */

        if (inode.type == INODE_TYPE_LINK)
        {
            if (FS_USE_ROM(c_inode))
                FD_BIND_AS_FILE(desc.opers, flags)
            else
                FD_BIND_SS_FILE(desc.opers, flags)

            if (flags & OPEN_ERASE)
                /* empty file content */
                __inode_empty(desc.begin);

        } else {
            
            // TODO, set errno
            return -1;  // not a link
        }

    } else {

        /* file */

        if (inode.type == INODE_TYPE_FILE)
            ;   // do nothing
        else if (inode.type == INODE_TYPE_SPECIAL) {
            
            // TODO, bind special callbacks
            
        } else {

            // TODO, set errno
            return -1;
        }

        /* bind operations */

        if (FS_USE_ROM(c_inode))
        {
            if (flags & OPEN_BIN)
                FD_BIND_AS_BINFILE(desc.opers, flags)
            else
                FD_BIND_AS_FILE(desc.opers, flags) 

        } else {
            
            if (flags & OPEN_BIN)
                FD_BIND_SS_BINFILE(desc.opers, flags)
            else
                FD_BIND_SS_FILE(desc.opers, flags)
        }
    }

    /* find a free fd space */
    
    int8_t fd = __fd_new();

    if (fd < 0)
    {
        // TODO, set errno, fd not available

    } else
        fd_table[fd] = desc; // copy buffer into the table

    return fd;
}

inode_t fs_rec_path(const char *path);

inode_t fs_parse_path(const char *path)
{
    inode_t ino, cwd = c_inode;

    switch (path[0])
    {
        case '0':
        FS_INODE_NULL(ino)
        return ino;

        case '/':
        FS_INODE_ROOT(ino)
        c_inode = ino;       // set cwd to root
        path++;
        break;

        case '~':

        if (path[1] = '/')
        {
            c_inode.dev = FS_DEV_ROM;
            c_inode.inode = c_user.home;  // set cwd to home
            path += 2;
        }
            
        break;
   }

   ino = fs_rec_path(path);
   c_inode = cwd;
   return ino;
}

inode_t fs_rec_path(const char *path)
{
    devsize_t inode = fs_inode(c_inode.inode); 
    inode_t rel;

    if (!inode)   // if not exists
    {
        FS_INODE_NULL(rel)
        return rel;
    }

    // TODO, check if dir or file
    // TODO, if dir, find name
    // TODO, set fs_cwd to new inode
    // TODO, recall fs_rec_path
}
