#include "string.h"

void *memcpy(void *dest, void *src, size_t n)
{
    char *dp = dest;
    char *sp = src;

    while (n--) {
        *dp++ = *sp++;
    }

    return dest;
}
