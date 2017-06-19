#ifndef BOOT_H
#define BOOT_H

#include "types.h"

#define LOGIN_PC    // TODO find an address in ROM, to perform jumps

#define EXEC_STATUS // TODO find an address in Kernel space

#define PWD_ADDR // TODO find an address in ROM, password
#define PWD_SIZE 8

struct exec_status {

    volatile int logged_in:1;   // authenticated
    volatile int k_control:1;   // no running programs
    volatile int program_id:1;  // current running program id, see "progman.h"
    volatile int hidden_pc:13;  // program counter of the paused program
};

void boot_init();

/*
*   It returns 1 if succeded, otherwise 0
*/

int8_t authenticate(const char *pwd);

/*
*   It sets the password in the ROM space, maximum 8 characters
*/

void set_pwd(const char *pwd);

#endif