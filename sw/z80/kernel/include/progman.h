#ifndef PROGRAM_MAN
#define PROGRAM_MAN

#include "types.h"

#define PROG_0 0x0
#define PROG_1 0x1

#define PROG_VSTART 0x1000
#define PROG_0_PREFIX 0xA000
#define PROG_1_PREFIX 0xC000

#define PROG_0_INFO     // TODO
#define PROG_1_INFO     // TODO find a space in the ram

struct program_info {

    volatile int enabled:1;
    volatile int running:1;
    volatile int exiting:1;
    volatile int heap_addr:13;
    volatile void (*quit_cb)(void);   // 16
};

/*
*   Initialize the program manager system
*/

void progman_init();

/*  
*   Check if it can start a new program
*   If it succedes, the program id is returned,
*   otherwise it is returned an error number
*/

#define PROG_REQ_FULL -1
#define PROG_REQ_ERR -2     // Maybe we don't need this, but just in case

int8_t prog_req(struct program_info *info);

/*
*   It allocates a program in the RAM
*   To obtain the right id call prog_req() first
*   Basic informations must be allocated and referenced by a program_base struct
*/

struct program_base {

    void * inst_set;    // pointer to the instructions set
    size_t inst_size;   // size of the instructions set
    void * bss_data;    // pointer to the bss/data space
    size_t data_size;   // size of the bss/data space
    size_t stack_size;  // size of the stack to determine the stack limit
};

void prog_alloc(int8_t id, struct program_info *info, const struct program_base *base);

/*
*   It jumps the program counter to the given one
*/

void prog_exec(int8_t id, struct program_info *info);

/*
*   It sets a quit callback
*/

void prog_0_qcb(void (*callback)(void));
void prog_1_qcb(void (*callback)(void));

/*
*   It quits a program, if a callback is set, it will be called
*/

void prog_0_quit();
void prog_1_quit();

/*
*   It forces a program to quit
*/

void prog_0_fquit();
void prog_1_fquit();

#endif