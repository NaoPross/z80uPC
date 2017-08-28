#include "usart.h"

void main(void)
{
    usart_init(USART_BAUDRATE_9600, USART_PARITY_EVEN, USART_STOP_BITS_1);
    usart_write("Hello, World!", 13);
}
