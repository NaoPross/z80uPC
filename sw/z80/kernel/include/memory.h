#ifndef __MEMORY_H__
#define __MEMORY_H__

#include "types.h"
#include "devices.h"

/* maximum number of pages on the system */
#define PAGES_MAX_COUNT 32

/* in our system there are only 16 pages since only 64KB can be addressed
 * to optimize the memory management in ROM and RAM only pages from this set
 * shall be used
 */
// ROM
#define ADDR_PAGE_0  0x0000
#define ADDR_PAGE_1  0x1000
#define ADDR_PAGE_2  0x2000
#define ADDR_PAGE_3  0x3000
// IOSPACE
#define ADDR_PAGE_4  0x4000
#define ADDR_PAGE_5  0x5000
#define ADDR_PAGE_6  0x6000
#define ADDR_PAGE_7  0x7000
// RAM
#define ADDR_PAGE_8  0x8000
#define ADDR_PAGE_9  0x9000
#define ADDR_PAGE_10 0xA000
#define ADDR_PAGE_11 0xB000
#define ADDR_PAGE_12 0xC000
#define ADDR_PAGE_13 0xD000
#define ADDR_PAGE_14 0xE000
#define ADDR_PAGE_15 0xF000

struct page
{
	uint used :1;
	uint8_t pid;     // process owner of the page
    uint16_t addr;   // physical address
};

extern struct page pages_table[PAGES_MAX_COUNT];

int mmu_write_table(void);

int page_map(int page, int pid, uint16_t addr);
int page_unmap(int page);

#endif // __MEMORY_H__