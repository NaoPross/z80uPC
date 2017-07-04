#include "login.h"
#include "string.h"

int8_t authenticate(const char *pwd) {

    return !memcmp(PWD_ADDR, pwd, PWD_SIZE);
}

void set_pwd(const char *pwd) {

    memcpy(PWD_ADDR, pwd, PWD_SIZE);
}