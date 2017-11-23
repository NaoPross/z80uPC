// #include "pio.h"

#include <stdint.h>

#define PIO_A_DATA  0x10
#define PIO_B_DATA  0x11
#define PIO_A_CMD   0x12
#define PIO_B_CMD   0x13

void main(void)
{
    __asm
    ;; output variable
    ld h, #0x00

    ;; set bit mode
    ld c, #PIO_B_CMD

    ld a, #0xCF
    out (c), a

    ;; set all pins to output
    ld a, #0x00
    out (c), a

    ;; disable interrupts
    ld a, #0x0C
    out (c), a

    ;; load data addr
    ld c, #PIO_B_DATA
loop:
    out (c), h
    ld a, h

    cpl
    ld h, a
    jr loop
    __endasm; 

    // uint8_t i = 0;

    // pio_set_mode(PIO_A, PIO_MODE_BIT_IO, 0x00);
    // pio_set_interrupts(PIO_A, PIO_INT_DISABLE);

    // while (1) {
    //     pio_write(PIO_A, i);
    //     i = ~i;
    // }
}