#ifndef __STDIO_H__
#define __STDIO_H__

#include "types.h"

extern uint8_t *stdout, stderr;

void putc(char ch, uint8_t *buffer);
int printf(const char *fmt, ...);

#endif 
