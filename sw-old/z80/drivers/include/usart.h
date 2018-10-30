#ifndef __USART_H__
#define __USART_H__

#include "addresses.h"

#include <stdint.h>
#include <string.h>

// baudrate clock divisors
// values from TL16C550C datasheet (table 9 for 1.8432 MHz crystal)
#define USART_BAUDRATE_50       2304
#define USART_BAUDRATE_75       1536
#define USART_BAUDRATE_110      1047
#define USART_BAUDRATE_134_5    857
#define USART_BAUDRATE_150      768
#define USART_BAUDRATE_300      384
#define USART_BAUDRATE_600      192
#define USART_BAUDRATE_1200     96
#define USART_BAUDRATE_1800     64
#define USART_BAUDRATE_2000     58
#define USART_BAUDRATE_2400     48
#define USART_BAUDRATE_3600     32
#define USART_BAUDRATE_4800     24
#define USART_BAUDRATE_7200     16
#define USART_BAUDRATE_9600     12
#define USART_BAUDRATE_19200    6
#define USART_BAUDRATE_38400    3
#define USART_BAUDRATE_56000    3

// parity
#define USART_PARITY_NONE       0
#define USART_PARITY_EVEN       1
#define USART_PARITY_ODD        2

// stop bits
#define USART_STOP_BITS_1       10
#define USART_STOP_BITS_15      15
#define USART_STOP_BITS_2       20

// word lenght
#define USART_WORD_LENGTH_5     0
#define USART_WORD_LENGTH_6     1
#define USART_WORD_LENGTH_7     2
#define USART_WORD_LENGTH_8     3

// autoflow
#define USART_AUTOFLOW_ALL      3
#define USART_AUTOFLOW_CTS      2
#define USART_AUTOFLOW_OFF      0

typedef unsigned int        uint;
typedef volatile uint8_t    register_t;

/* stuctures for usart registers */
struct IER 
{
    volatile uint received_data_interrupt :1;
    volatile uint transmitter_empty_interrupt :1;
    volatile uint receiver_line_status_interrupt :1;
    volatile uint modem_status_interrupt :1;
    volatile uint reserved :4;
};

struct IIR
{
    volatile uint interrupt_pending :1;
    volatile uint interrupt_id :3;
    volatile uint reserved :2;
    volatile uint fifos :2;
};

struct FCR
{
    volatile uint fifo_enable :1;
    volatile uint receiver_fifo_rst :1;
    volatile uint trasmitter_fifo_rst :1;
    volatile uint dma_mode_select :1;
    volatile uint reserved :1;
    volatile uint receiver_trigger :2;
};

struct LCR
{
    volatile uint word_length :2;
    volatile uint stop_bits :1;
    volatile uint parity :1;
    volatile uint even_parity :1;
    volatile uint stick_parity :1;
    volatile uint break_control :1;
    volatile uint divisor_latch_access :1;
};

struct MCR
{
    volatile uint data_terminal_ready :1;
    volatile uint request_to_send :1;
    volatile uint out1;
    volatile uint out2;
    volatile uint loop;
    volatile uint autoflow :1;
    volatile uint reserved :2;
};

struct LSR 
{
    volatile uint data_ready :1;
    volatile uint overrun_error :1;
    volatile uint parity_error :1;
    volatile uint framing_error :1;
    volatile uint break_interrupt :1;
    volatile uint transmitter_holder_empty :1;
    volatile uint transmitter_empty :1;
    volatile uint fifo_recv_error :1;
};

struct MSR
{
    volatile uint delta_cts :1;
    volatile uint delta_data_set_ready :1;
    volatile uint trailing_edge_ring_indicator :1;
    volatile uint delta_data_carrier_detect :1;
    volatile uint clear_to_send :1;
    volatile uint data_set_ready :1;
    volatile uint ring_indicator :1;
    volatile uint data_carrier_detect :1;
};

/* this structure is only for internal use */
struct _usart_device
{
    register_t buffer;  // also used as LSB for divisor latch
    struct IER IER;
    struct IIR IIR;
    struct FCR FCR;
    struct LCR LCR;
    struct MCR MCR;
    struct LSR LSR;
    struct MSR MSR;
    register_t scratch;
};


// setup functions (wrappers)
void usart_set_baudrate(uint16_t baudrate);
void usart_set_parity(int mode);
void usart_set_stop_bits(int count);
void usart_set_word_length(int length);
void usart_set_autoflow(int mode);

inline void usart_init(uint16_t baudrate, int parity, int stop_bits); 

void usart_transmit(uint8_t data);
uint8_t usart_receive();

int usart_write(uint8_t *data, size_t size);
int usart_read(uint8_t *buffer, size_t count);

#endif // __USART__H__
