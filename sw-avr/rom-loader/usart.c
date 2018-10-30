#include "usart.h"

#include <avr/io.h>
#include <util/setbaud.h>

void usart_init(void)
{
    // automated by util/setbaud.h
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

#if USE_2X
    UCSR0A |= _BV(U2X0);
#else
    UCSR0A &= ~(_BV(U2X0));
#endif

    // 8 bit data
    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);

    // enable TX and RX pins
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);
}

void usart_send(uint8_t c)
{
    UDR0 = c;    
    // wait until transmission ready
    loop_until_bit_is_set(UCSR0A, TXC0); 
}

uint8_t usart_recv(void)
{
    // wait until data exists
    loop_until_bit_is_set(UCSR0A, RXC0);
    return UDR0;
}
