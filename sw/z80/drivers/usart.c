#include "usart.h"

static volatile struct _usart_device *_usart = ((struct _usart_device *) ADDR_DEV_USART);

void usart_set_baudrate(uint16_t baudrate)
{
    // enable latch access
    _usart->LCR.divisor_latch_access = 1;
    _usart->buffer = 0x00FF & baudrate; // LSBs
    memcpy(&_usart->IER, &(baudrate >>8), 1);
    // _usart->IER    = 0x00FF & (baudrate >> 8); // MSBs
    _usart->LCR.divisor_latch_access = 0;
}

void usart_set_parity(int mode)
{
    if (mode == USART_PARITY_EVEN) {
        _usart->LCR.even_parity = 1;
    }
    else if (mode == USART_PARITY_ODD) {
        _usart->LCR.even_parity = 0;
    }

     _usart->LCR.parity = (mode == USART_PARITY_NONE) ? 0 : 1;
}

void usart_set_stop_bits(int count)
{
    _usart->LCR.stop_bits = (count == USART_STOP_BITS_1) ? 0 : 1;
}

void usart_word_length(int length)
{
    _usart->LCR.word_length = length;
}

void usart_set_autoflow(int mode)
{
    _usart->MCR.autoflow = (mode == USART_AUTOFLOW_OFF) ? 0 : 1;
    _usart->MCR.data_terminal_ready = (mode == USART_AUTOFLOW_ALL);
}

inline void usart_init(uint16_t baudrate, int parity, int stop_bits)
{
    usart_set_baudrate(baudrate);
    usart_set_parity(parity);
    usart_set_stop_bits(stop_bits);
    usart_set_autoflow(USART_AUTOFLOW_OFF);
}

void usart_transmit(uint8_t data)
{
    _usart->buffer = data;
    while (_usart->LSR.transmitter_holder_empty == 0); // wait
}

uint8_t usart_receive()
{
    return _usart->buffer;
}

int usart_write(uint8_t *data, size_t size)
{
    uint8_t *dp = data;

    while (size--) {
        _usart->buffer = *(dp++);
        while (_usart->LSR.transmitter_empty);
    }

    // TODO: do something that actually counts for sent bytes 
    return size;
}

int usart_read(uint8_t *buffer, size_t count)
{
    uint8_t *bp = buffer;
    size_t read_count = 0;

    while (count--) {
        *(bp++) = _usart->buffer;
        // check for errors
        if (_usart->LSR.framing_error || _usart->LSR.parity_error) {
            bp--; // delete last byte (?)
        } else {
            read_count++;
        }
    }

    return read_count;
}
