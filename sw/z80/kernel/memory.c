#include "memory.h"

struct page pages_table[PAGES_MAX_COUNT];

int mmu_write_table(void)
{
    int i;

    for (i = 0; i < PAGES_MAX_COUNT; i++) {
        if (pages_table[i].used) {
            // write to mmu table
        }
    }

    return 0;
}

int page_map(int page, int pid, uint16_t addr)
{
    if (page >= PAGES_MAX_COUNT)
        return -1;

    if (pages_table[page].used)
        return -2;

    pages_table[page].addr = addr;
    pages_table[page].pid = pid;

    pages_table[page].used = 1;
    return 0;
}

int page_unmap(int page)
{
    if (page >= PAGES_MAX_COUNT)
        return -1;

    if (pages_table[page].used == 0)
        return -2;

    pages_table[page].used = 0;
    return 0;
}

/* k_malloc manager */
/*
struct k_buf_entry k_buf_table[K_BUF_MAX_COUNT];

struct k_buf k_buffers[K_BUF_MAX_COUNT];

void * k_malloc()
{
    for (uint8_t i = 0; i < K_BUF_TABLE_COUNT; i++)
    {
        for (uint8_t bit = 0x80, j = 0; j < 8; bit >>= 1, j++)
        {
            if (bit & k_buf_table[i])
            {
                k_buf_table[i] |= bit;
                return &k_buffers[8 * i + j];
            }
        }
    }
}

void k_free(void * ptr)
{
    uint8_t index = (ptr - &k_buffers[0]) / K_BUF_SIZE;

    if (index < K_BUF_MAX_COUNT)
        k_buf_table[index / 8] ^= 0x80 >> index % 8;
}*/
