#include "stdio.h"

void putc(char ch, uint8_t *buffer)
{
    *buffer = ch;
    *(++buffer) = '\0';
}


int printf(const char *fmt, ...)
{
}
