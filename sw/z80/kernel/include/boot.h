#ifndef BOOT_H
#define BOOT_H

#define LOGIN_PC    // TODO find an address in ROM, to perform jumps

#define EXEC_STATUS // TODO find an address in Kernel space

struct exec_status {

    volatile int logged_in:1;   // authenticated
    volatile int k_control:1;   // no running programs
    volatile int program_id:1;  // current running program id, see "progman.h"
    volatile int hidden_pc:13;  // program counter of the paused program
};

void boot_init();

#endif