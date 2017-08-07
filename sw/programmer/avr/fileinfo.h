#ifndef __FILEINFO_H__
#define __FILEINFO_H__

#include <stdio.h>

struct file_info
{
    size_t size;
    size_t blklen;
    uint16_t start_addr;
};

#endif 
