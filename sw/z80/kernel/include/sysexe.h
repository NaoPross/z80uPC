#ifndef SYS_EXE
#define SYS_EXE

#define SYS_EXEC_ADDR // TODO find an address in Kernel space

struct sys_progman {

    // program 0 enabled

    uint8_t prog_0_enabled:1;

    // program 1 enabled

    /*
    *   Obs: A program is enabled when its space is allocated 
    *        and its virtual program counter is stored in 
    *        the hardware or in the silent_pc.
    *        An enabled program is not necessarly running, it 
    *        could be paused too.
    */

    uint8_t prog_1_enabled:1;

    // running's program id

    uint8_t prog_running:1;
};

struct sys_exec {

    /*
    *   Virtual addresses are activated
    */

    uint8_t virtual_addr:1;

    struct sys_progman progman;

    /*
    *   The silent_pc is the place designed to store the 
    *   program counter of the program that's not running
    */

    uint8_t silent_pc:12;
};

/*
*   Function to access informations
*/

uint8_t vaddr_enabled();

struct sys_progman * sys_prog_data(struct sys_progman *data);

#endif