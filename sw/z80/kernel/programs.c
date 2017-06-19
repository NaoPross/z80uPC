#include "progman.h"
#include "string.h"

#define EMPTY_PROG_INFO 0x0

struct program_info *prog_0 = PROG_0_INFO,
                    *prog_1 = PROG_1_INFO;

void progman_init() {

    *prog_0 = EMPTY_PROG_INFO;
    *prog_1 = EMPTY_PROG_INFO;

    // TODO other stuff
}

int8_t prog_req(struct program_info *info) {

    uint8_t prog;

    if (!prog_0->enabled) {

        prog = PROG_0;
        *info = *prog_0;

    } else if (!prog_1->enabled) {

        prog = PROG_1;
        *info = *prog_1;

    } else {

        return PROG_REQ_FULL;
    }

    return prog;
}

void prog_alloc(int8_t id, struct program_info *info, const struct program_base *base) {

    void *addr = (id ? PROG_1_PREFIX : PROG_0_PREFIX) + PROG_VSTART;

    if (info->enabled) {

        if (id)
            prog_1_fquit(); // force quit operation
        else
            prog_0_fquit();
    }
        

    memcpy(addr, base->inst_set, base->inst_size);

    addr += base->inst_size;

    memcpy(addr, base->bss_data, base->data_size);

    addr += base->data_size;

    // TODO, empty heap and stack
}

/*
*   TODO Called from the assembly, system calls
*/

extern void exec_0(void);
extern void exec_1(void);

void prog_exec(int8_t id, struct program_info *info) {

    // TODO, perform a program counter jump
}

void prog_0_qcb(void (*callback)(void)) {

    prog_0->quit_cb = callback;
}

void prog_1_qcb(void (*callback)(void)) {

    prog_1->quit_cb = callback;
}

void prog_0_quit() {
    
    if (!prog_0->enabled || prog_0->exiting)
        return;

    if (prog_0->quit_cb)
        prog_0->quit_cb();

    // TODO free space in RAM

    *prog_0 = EMPTY_PROG_INFO;

    // TODO jump program counter
}

void prog_1_quit() {
    
    if (!prog_1->enabled || prog_1->exiting)
        return;

    if (prog_1->quit_cb)
        prog_1->quit_cb();

    // TODO free space in RAM

    *prog_1 = EMPTY_PROG_INFO;

    // TODO jump program counter
}

void prog_0_fquit() {

    if (!prog_0->enabled)
        return;

    // TODO free space in RAM

    *prog_0 = EMPTY_PROG_INFO;

    // TODO jump program counter
}

void prog_1_fquit() {

    if (!prog_1->enabled)
        return;

    // TODO free space in RAM

    *prog_1 = EMPTY_PROG_INFO;

    // TODO jump program counter
}