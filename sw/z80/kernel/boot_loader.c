#include "boot.h"
#include "progman.h"

#define DEFAULT_EXEC_STATUS 0x4000

struct exec_status *status = EXEC_STATUS; 

void boot_init() {

    *status = DEFAULT_EXEC_STATUS;

    // TODO other stuff
}

int8_t authenticate(const char *pwd) {

    const char *c_pwd = PWD_ADDR, *c_req = pwd;
    
    for (uint8_t i = 0; i < PWD_SIZE; i++) {

        if (*c_pwd != *c_req)
            return 0;

        c_pwd++;
        c_req++;
    }

    return 1;
}

void set_pwd(const char *pwd) {

    char *c_pwd = PWD_ADDR;
    const char *c_req = pwd;

    for (uint8_t i = 0; i < PWD_SIZE; i++) {

        *c_pwd = *c_req;

        c_pwd++;
        c_req++;
    }
}