#ifndef __SERIAL_H__
#define __SERIAL_H__

#include "types.h"

// define all
#define USART_BAUD_9600
#define USART_BAUD_115200

uint8_t usart_registers[8];
usart_registers = 0x80FF; // TODO: set real address

void usart_init(int16_t baudprescale);

#endif
