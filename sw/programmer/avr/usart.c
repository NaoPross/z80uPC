#include "usart.h"

static uint16_t usart_baudrate;
static uint16_t usart_baud_prescale;

void usart_init(uint16_t baudrate)
{
    // enable RX and TX
    UCSR0B |= _BV(RXEN0) | _BV(TXEN0);
    
    // set 8 bit size char
    UCSR0C |= _BV(UCSZ01) | _BV(UCSZ00);

    // set baudrate 
    usart_baudrate = baudrate;
    usart_baud_prescale = (F_CPU / (usart_baudrate * 16)) -1;
    
    UBRR0L = usart_baud_prescale;
    UBRR0H = usart_baud_prescale >> 8;
}

void usart_send_byte(uint8_t data)
{
    while (!(UCSR0A & _BV(UDRE0)));
    UDR0 = data;
}

void usart_send(uint8_t *data, size_t len)
{
    uint8_t *p = data;

    while (len--) {
        usart_send_byte(*(p++));
    }
}

void usart_print(char *str)
{
    char *p = str;
    size_t len = 0;

    while (*p++ != '\0') {
        len++;
    }

    usart_send((uint8_t *) str, len);
}

int usart_read_byte(uint8_t *byte)
{
    uint16_t timeout = USART_TIMEOUT;

    do {
        if (UCSR0A & _BV(RXC0)) {
            *byte = UDR0;
            return 0;
        }
    } while (timeout--);

    return -1;
}

uint8_t usart_read_byte_nt(void)
{
    while ((UCSR0A & _BV(RXC0)) == 0);
    return UDR0;
}


size_t usart_read(uint8_t *buffer, size_t len)
{
    size_t read = 0;
    uint8_t *p = buffer;

    while (len--) {
        if (usart_read_byte(p) == 0) {
            p++; 
            read++;
        }
    }

    return read;
}

int usart_read_line(uint8_t *buffer, size_t len)
{
    uint8_t ch;
    uint8_t *p = buffer;
    size_t read = 0;

    while (len--) {
        if (usart_read_byte(&ch) != 0)
            continue;
        else
            read++;

        if (ch == '\n')
            break;
        else
            *(p++) = ch;
    }

    if (ch != '\n')
        return -1;

    return 0;
}
