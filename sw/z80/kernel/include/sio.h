#ifndef __SIO_H__
#define __SIO_H__

#include "types.h"

#define SIO_PORT_0 0x0
#define SIO_PORT_1 0x1
#define SIO_PORT_2 0x2
#define SIO_PORT_3 0x3
#define SIO_PORT_4 0x4
#define SIO_PORT_5 0x5
#define SIO_PORT_6 0x6
#define SIO_PORT_7 0x7

/* current port in use */
extern uint8_t      sio_port;

/* current seek in the device */
extern devsize_t    sio_seek;

struct dev_buffer
{
   // TODO, bytes needed to the device buffer interface
};

/* points to the buffers mapped in the I/O space */
/* to be defined precisely in assembly */
extern volatile struct dev_buffer sio_buffers[8];

/* initialize serial interface */
void sio_init();

/* syscall: read one byte from the current device */
uint8_t sio_recv();
/* syscall: write one byte into the current device */
void sio_send(uint8_t value);

/* read n bytes from the current port */
size_t sio_read(void *buffer, size_t n);
/* write n bytes into the current port */
int8_t sio_write(const void *buffer, size_t n);

#endif  // __SIO_H__
