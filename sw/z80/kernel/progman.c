#include "progman.h"
#include "string.h"
#include "syscall.h"
#include "sysexe.h"

#define EMPTY_PROG_INFO 0x0

volatile struct prog_data *prog_0 = PROG_0_INFO,
                    *prog_1 = PROG_1_INFO;

void progman_init() {

    *prog_0 = EMPTY_PROG_INFO;
    *prog_1 = EMPTY_PROG_INFO;

    // TODO other stuff
}

int8_t prog_req() {

    struct sys_progman data;

    sys_prog_data(&data);

    if (data.prog_0_enabled)
        return PROG_0;
    else if (data.prog_1_enabled)
        return PROG_1;

    return PROG_REQ_FULL;
}

void prog_alloc(int8_t id, struct prog_data *data, const struct prog_space *space) {

    void *addr = (id ? PROG_1_PREFIX : PROG_0_PREFIX) + PROG_VSTART;

    memcpy(addr, base->inst_set, base->inst_size);

    addr += base->inst_size;

    memcpy(addr, base->bss_data, base->data_size);

    addr += base->data_size;

    // TODO, empty heap and stack
}

void prog_exec(int8_t id, struct prog_data *data) {

    if (id)
        prog_exec_1();  // system call
    else
        prog_exec_0();  // system call
}

void prog_0_set_qcb(void (*callback)(void)) {

    prog_0->quit_cb = callback;
}

void prog_1_set_qcb(void (*callback)(void)) {

    prog_1->quit_cb = callback;
}

void prog_0_quit(uint8_t force) {
    
    if (!prog_0->enabled || prog_0->exiting)
        return;

    if (!force && prog_0->quit_cb)
        prog_0->quit_cb();

    *prog_0 = EMPTY_PROG_INFO;

    prog_stop_0();  // system call
}

void prog_1_quit(uint8_t force) {
    
    if (!prog_1->enabled || prog_1->exiting)
        return;

    if (!force && prog_1->quit_cb)
        prog_1->quit_cb();

    *prog_1 = EMPTY_PROG_INFO;

    prog_stop_1();  // system call
}