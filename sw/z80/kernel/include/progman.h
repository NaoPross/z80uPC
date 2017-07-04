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

struct prog_status {

    // The program is in execution

    uint8_t running:1;

    // The program is executing its quit callback

    uint8_t exiting:1;

    uint8_t unused:6;  // TODO, find a usage for these bits
}:

struct prog_data {

    struct prog_status status;

    /*
    *   The following addresses are needed to map 
    *   map the usable memory for dynamic allocations
    */

    // Virtual address of the heap

    uint8_t heap_addr:12;

    // Virtual address of the stack limit

    uint8_t stack_limit:12;

    /*
    *   Function called when the program exits normally
    */

    void (*quit_cb)(void);   // 16
};

/*
*   Initialize the program manager system
*/

void progman_init();

/*  
*   Check if it can start a new program
*   If it succedes, the program id is returned,
*   otherwise it is returned an error number
*
*   ! Disable virtual addresses when this function is called
*/

#define PROG_REQ_FULL -1

int8_t prog_req();

/*
*   It allocates a program in the RAM
*   To obtain the right id call prog_req() first
*   Basic informations must be allocated and referenced by a program_base struct
*
*   ! Disable virtual addresses when this function is called
*/

struct prog_space {

    void * inst_set;    // pointer to the instructions set
    size_t inst_size;   // size of the instructions set
    void * bss_data;    // pointer to the bss/data space
    size_t data_size;   // size of the bss/data space
};

void prog_alloc(int8_t id, struct prog_data *data, const struct prog_space *space);

/*
*   It jumps the program counter to the given one
*/

void prog_exec(int8_t id, struct prog_data *data);

/*
*   It sets a quit callback
*/

void prog_0_set_qcb(void (*callback)(void));
void prog_1_set_qcb(void (*callback)(void));

/*
*   It quits a program, if a callback is set, it will be called
*/

void prog_0_quit(uint8_t force);
void prog_1_quit(uint8_t force);

#endif