#ifndef __FLASH_H__
#define __FLASH_H__

#include "serial.h"

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FLASH_BLOCK_SIZE 	512

struct flash_blk
{
	uint16_t addr;
	uint16_t size;
};

int flash_open(const char *devpath, unsigned long baudrate);
int flash_write(const char *romfile, void (*log)(const char *));
void flash_close(void);

#endif
