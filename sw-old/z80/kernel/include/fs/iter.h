#ifndef __ITER_H__
#define __ITER_H__

struct inode_iter
{
    devsize_t   dev_seek;       /* seek position in the volume */
    devsize_t   blk_end;        /* end of the block */

    int16_t     blk_index;      /* index of the block */

    int8_t      blk_level;      /* recursion level, indirect blocks */
    
    fsize_t     fseek;          /* virtual seek in the file */
    fsize_t     size;           /* file size */
};

#endif  // __ITER_H__
