#ifndef __USART_H__
#define __USART_H__

#include "types.h"
#include "devices.h"

#include "string.h"

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


/* this structure is only for internal usage */
struct _usart_device
{
    register_t buffer;  // also used as LSB for divisor latch

    struct IER 
    {
        volatile int received_data_interrupt :1;
        volatile int transmitter_empty_interrupt :1;
        volatile int receiver_line_status_interrupt :1;
        volatile int modem_status_interrupt :1;
        volatile int reserved :4;
    } IER;

    struct IIR
    {
        volatile int interrupt_pending :1;
        volatile int interrupt_id :3;
        volatile int reserved :2;
        volatile int fifos :2;
    } IIR;

    struct FCR
    {
        volatile int fifo_enable :1;
        volatile int receiver_fifo_rst :1;
        volatile int trasmitter_fifo_rst :1;
        volatile int dma_mode_select :1;
        volatile int reserved :1;
        volatile int receiver_trigger :2;
    } FCR;

    struct LCR
    {
        volatile int word_length :2;
        volatile int stop_bits :1;
        volatile int parity :1;
        volatile int even_parity :1;
        volatile int stick_parity :1;
        volatile int break_control :1;
        volatile int divisor_latch_access :1;
    } LCR;

    struct MCR
    {
        volatile int data_terminal_ready :1;
        volatile int request_to_send :1;
        volatile int out1;
        volatile int out2;
        volatile int loop;
        volatile int autoflow :1;
        volatile int reserved :2;
    } MCR;

    struct LSR 
    {
        volatile int data_ready :1;
        volatile int overrun_error :1;
        volatile int parity_error :1;
        volatile int framing_error :1;
        volatile int break_interrupt :1;
        volatile int transmitter_holder_empty :1;
        volatile int transmitter_empty :1;
        volatile int fifo_recv_error :1;
    } LSR;

    struct MSR
    {
        volatile int delta_cts :1;
        volatile int delta_data_set_ready :1;
        volatile int trailing_edge_ring_indicator :1;
        volatile int delta_data_carrier_detect :1;
        volatile int clear_to_send :1;
        volatile int data_set_ready :1;
        volatile int ring_indicator :1;
        volatile int data_carrier_detect :1;
    } MSR;

    register_t scratch;
};


// setup functions (wrappers)
void usart_set_baudrate(uint16_t baudrate);
void usart_set_parity(int mode);
void usart_set_stob_bits(int count);
void usart_set_word_length(int length);
void usart_set_autoflow(int mode);

inline void usart_init(uint16_t baudrate, int parity, int stop_bits); 

void usart_transmit(uint8_t data);
uint8_t usart_receive();

int usart_write(uint8_t *data, size_t size);
int usart_read(uint8_t *buffer, size_t count);

#endif // __USART__H__
