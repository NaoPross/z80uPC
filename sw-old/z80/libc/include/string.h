#ifndef __STRING_H__
#define __STRING_H__

#include "types.h"

void * memset(void *dest, const int8_t src, size_t n);

void *memcpy(void *dest, const void *src, size_t n);

int8_t memcmp(const void *s1, const void *s2, size_t n);

#endif
