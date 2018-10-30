#include "types.h"
#include "usart.h"

void kmain(void)
{
    usart_init(USART_BAUDRATE_9600, USART_PARITY_EVEN, USART_STOP_BITS_1);
}
