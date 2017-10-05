#include "pio.h"

void main(void)
{
    uint8_t j = 0;

    pio_set_mode(PIO_A, PIO_MODE_BYTE_OUT, 0);

    while (1) {
        pio_write(PIO_A, j++);
    }
}
