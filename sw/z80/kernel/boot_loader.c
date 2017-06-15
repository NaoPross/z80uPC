#include "boot.h"
#include "progman.h"

#define DEFAULT_EXEC_STATUS 0x4000

struct exec_status *status = EXEC_STATUS; 

void boot_init() {

    *status = DEFAULT_EXEC_STATUS;

    // TODO other stuff
}