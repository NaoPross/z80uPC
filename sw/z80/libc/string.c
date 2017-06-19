#include "string.h"

void * memset(void *dest, const int8_t src, size_t n) {

    void *dp = dest;

    while (n--)
        *dp++ = src;

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

int8_t memcmp(const void *s1, const void *s2, size_t n) {

    uint8_t u1, u2;

    for ( ; n--; s1++, s2++) {

        u1 = *s1;
        u2 = *s2;

        if (u1 != u2)
            return u1 - u2;
    }

    return 0;
}