#include "usart.h"

void main(void)
{
    usart_init(USART_BAUDRATE_1200, USART_PARITY_EVEN, USART_STOP_BITS_1);
    usart_write("Hello, World!\n", 13);

    while(1) {
        usart_write("done\n", 5);
    }
}
