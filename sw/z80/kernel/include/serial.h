#ifndef __SERIAL_H__
#define __SERIAL_H__

#include "types.h"
#include "devices.h"

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
    }

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
        volatile int transmitter_register :1;
        volatile int transmitter_emtpy :1;
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
} *_usart = (_usart_device *) ADDR_DEV_USART;


#endif // __SERIAL__H__
