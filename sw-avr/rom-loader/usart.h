#ifndef USART_H
#define USART_H

#include <stdint.h>

void usart_init(void);
void usart_send(uint8_t c);
uint8_t usart_recv(void);

#endif
