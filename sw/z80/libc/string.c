#include "string.h"

void *memset(void *dest, const int8_t src, size_t n) {

    char *dp = (char *) dest;

    while (n--)
        *(dp++) = src;

    return dest;
}

void *memcpy(void *dest, void *src, size_t n)
{
    char *dp = dest;
    char *sp = src;

    while (n--) {
        *dp++ = *sp++;
    }

    return dest;
}

int8_t memcmp(void *s1, void *s2, size_t n)
{
    char *u1 = (char *) s1;
    char *u2 = (char *) s2;

    for ( ; n--; u1++, u2++) {

        if (*u1 != *u2)
            return u1 - u2;
    }

    return 0;
}