#include "boot.h"
#include "progman.h"
#include "string.h"

#define DEFAULT_EXEC_STATUS 0x4000

struct exec_status *status = EXEC_STATUS; 

void boot_init() {

    *status = DEFAULT_EXEC_STATUS;

    // TODO other stuff
}

int8_t authenticate(const char *pwd) {

    return !memcmp(PWD_ADDR, pwd, PWD_SIZE);
}

void set_pwd(const char *pwd) {

    memcpy(PWD_ADDR, pwd, PWD_SIZE);
}