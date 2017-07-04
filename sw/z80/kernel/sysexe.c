#include "sysexe.h"

volatile struct sys_exec *exec_data = SYS_EXEC_ADDR;

uint8_t vaddr_enabled() {

    return exec_data->virtual_addr;
}

struct sys_progman * sys_prog_data(struct sys_progman *data) {

    *data = exec_data->sys_progman;
    return data;
}