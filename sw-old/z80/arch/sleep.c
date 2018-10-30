#include "sleep.h"

void usleep(uint16_t microseconds)
{
    __asm
    pop hl
loop:
    ld bc, #SLEEP_UNIT
unit:
    nop
    dec bc
    jr nz, unit
    dec hl
    jr nz,loop
    __endasm;
}