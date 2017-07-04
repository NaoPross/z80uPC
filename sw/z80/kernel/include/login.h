#ifndef LOGIN_H
#define LOGIN_H

#include "types.h"

#define LOGIN_PC    // TODO find an address in ROM, to perform jumps

#define PWD_ADDR // TODO find an address in ROM, password
#define PWD_SIZE 8

/*
*   It returns 1 if succeded, otherwise 0
*/

int8_t authenticate(const char *pwd);

/*
*   It sets the password in the ROM space, maximum 8 characters
*/

void set_pwd(const char *pwd);

#endif