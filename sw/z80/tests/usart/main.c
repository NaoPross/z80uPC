#include "usart.h"
#include <stdint.h>

void main(void)
{
    usart_init(USART_BAUDRATE_1200, USART_PARITY_NONE, USART_STOP_BITS_1);

    while (1) {
        usart_write("Hello World!\n", 13);
    }
}