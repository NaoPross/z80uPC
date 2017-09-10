#include "memory.h"

static struct page pages_table[PAGES_MAX_COUNT];

int mmu_write_table(void)
{
    int i;

    for (i = 0; i < PAGES_MAX_COUNT; i++) {
        if (pages_table[i].pid != 0) {
            // write to mmu table
        }
    }

    return 0;
}

int page_new(void)
{
    int i, addr, used;
    for (addr = ADDR_PAGE_FIRST; addr < ADDR_PAGE_LAST; addr += PAGE_SIZE) {
        used = 0;

        for (i = 0; i < PAGES_MAX_COUNT; i++) {
            if (page_map[i].addr == addr) {
                used = 1;
                break;
            }
        }

        if (!used)
            return i;
    }

    return -1;
}

int page_map(int page, int pid, uint16_t addr)
{
    if (page >= PAGES_MAX_COUNT)
        return -1;

    if (pages_table[page].pid != 0)
        return -2;

    pages_table[page].addr = addr;
    pages_table[page].pid = pid;

    return 0;
}

int page_unmap(int page)
{
    if (page >= PAGES_MAX_COUNT)
        return -1;

    if (pages_table[page].pid == 0)
        return -2;

    pages_table[page].pid = 0;
    pages_table[page].addr = 0;
    return 0;
}
