#ifndef __USART_H__
#define __USART_H__
/*** 
 * USART REGISTERS {{{
 *
 * UCSR: control and status regisers, composed from 3 registers:
 *  +------------------------------------------------------------------------+
 *  | UCSRA :| RXC   | TXC   | UDRE  | FE    | DOR   | PE    | U2X   | MPCM  | 
 *  +------------------------------------------------------------------------+
 *   UCSRA is a status register (read only)
 *   Relevant bits:
 *       - RXC : set to 1 if data is present on the receive buffer
 *       - TXC : set to 1 when data is transferred to the transfer register 
 *       - UDRE: set to 1 when trasmit buffer is empty (data sent)
 *  +------------------------------------------------------------------------+
 *  | UCSRB :| RXCIE | TXCIE | UDRIE | RXEN  | TXEN  | UCSZ2 | RXB8  | TXB8  | 
 *  +------------------------------------------------------------------------+
 *   UCSRB is used to setup hardware configuration
 *   Relevant bits:
 *       - RXCIE: RX complete interrupt enabled when set to 1
 *       - TXCIE: TX complete interrupt enabled when set to 1
 *       - UDRIE: data register empty interrupt enabled when set to 1
 *       - RXEN : uart receiver enabled  when set to 1
 *       - TXEN : uart transmitter enabled when set to 1
 *  +------------------------------------------------------------------------+
 *  | UCSRC :| URSEL | UMSEL | UPM1  | UPM0  | USBS  | UCSZ1 | UCSZ0 | UCPOL | 
 *  +------------------------------------------------------------------------+
 *   UCSRB is used to setup protocol configuration
 *   Relevant bits:
 *       - URSEL: register select (location is shared with UBRRH and UCSRC)
 *       - UMSEL: mode select
 *              1 -> synchronous
 *              0 -> asynchronous
 *       - UMP1 + UPM0: set parity
 *              00 -> no parity
 *              01 -> reserved
 *              10 -> even
 *              11 -> odd
 *       - UCSZ2 + UCSZ1 + UCSZ0: set data frame (char size)
 *              000 -> 5 bit
 *              001 -> 6 bit
 *              010 -> 7 bit
 *              011 -> 8 bit
 *              100 to 110 -> reserved
 *              111 -> 9 bit
 *
 * UBRR: baudrate register
 *  +------------------------------------------------------------------------+
 *  | UBRRH :| URSEL |       |       |       | UBRR11| UBRR10| UBRR9 | UBRR8 | 
 *  +------------------------------------------------------------------------+
 *  | UBRRL :| UBRR7 | UBRR6 | UBRR5 | UBRR4 | UBRR3 | UBRR2 | UBRR1 | UBRR0 | 
 *  +------------------------------------------------------------------------+
 *    UBRR is composed of 2 8 bit registers to store a 12 bit baudrate value.
 *    The value to be stored in this register is calculated with the following
 *    formula (approximate to integer):
 *       UBRR = ( XTAL_frequency ) / ( 16 * BAUDRATE ) -1
 *
 *    in C code corresponds to:
 *       #define USART_BAUDRATE 9600
 *       #define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
 *
 *    Relevant bits:
 *       - URSEL: register select (location is share with UCSRC)
 *
 * UDR : data register
 *   This register is shared between RX and TX
 *
 * }}}
 */

#include <stdint.h>
#include <stdlib.h>

#include <avr/io.h>

#define USART_TIMEOUT   5000

// struct usart_conf
// {
//     uint16_t baudrate;
// };

void usart_init(uint16_t baudrate);
// void usart_init_conf(struct usart_conf *conf);

void usart_send_byte(uint8_t data);
void usart_send(uint8_t *data, size_t len);

void usart_print(char *str);

int usart_read_byte(uint8_t *byte);
uint8_t usart_read_byte_nt(void);
size_t usart_read(uint8_t *buffer, size_t len);
int uart_read_line(uint8_t *buffer, size_t len);

#endif
