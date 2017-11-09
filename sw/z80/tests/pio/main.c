#include "pio.h"

#include <stdint.h>

void main(void)
{
    uint8_t i = 0;

    pio_set_mode(PIO_A, PIO_MODE_BIT_IO, 0x00);
    pio_set_interrupts(PIO_A, PIO_INT_DISABLE);

    while (1) {
        pio_write(PIO_A, i);
        i = ~i;
    }
}
