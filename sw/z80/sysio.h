#ifndef __SYSIO_H__
#define __SYSIO_H__

#include "types.h"

/*
* 	Memory management
*/

void * malloc(uint16_t size);
uint16_t malloc_size(void * address);
void free(void * address);

/*
*	File management
*/

#define F_WRITE "w"
#define F_READ "r"
#define F_BIN_WRITE "wb"
#define F_BIN_READ "rb"

#define F_READ_CODE 0x0
#define F_WRITE_CODE 0x1
#define F_BIN_READ_CODE 0x2
#define F_BIN_WRITE_CODE 0x3

#define F_PERM_READ 0x0
#define F_PERM_WRITE 0x1
#define F_PERM_RW 0x2

struct file {

	const char * path;
	unsigned int mode:4;
	unsigned int permission:4;
};

#define FILE struct file

FILE * fopen(const char * path, const char * mode);
uint8_t fclose(FILE * file);

// TODO: other functions

/*
*	Processes management
*/

#define PID uint16_t

void exit();	// exit this program
void interrupt(PID)

#endif