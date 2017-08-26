#ifndef SIO_H
#define SIO_H

#include "types.h"

#define SIO_ROM 0x0

#define SIO_PORT_1 0x1
#define SIO_PORT_2 0x2
#define SIO_PORT_3 0x3
#define SIO_PORT_4 0x4
#define SIO_PORT_5 0x5
#define SIO_PORT_6 0x6
#define SIO_PORT_7 0x7

/* initialize serial interface */
void sio_init();

/* return the device address in the address space */
void * sio_dev_addr(uint8_t dev);
/* return the driver id to be used on dev */
uint8_t sio_dev_driver(uint8_t dev);

/* set current device in use */
void sio_set_dev(uint8_t dev);
/* get current device in use */
uint8_t sio_cdev();

/* get pointer in given device */
uint16_t sio_tellg(uint8_t dev);
/* get pointer in current device */
uint16_t sio_ctellg();

/* set pointer in given device */
int sio_seekg(uint8_t dev, uint16_t value);
/* set pointer in current device */
int sio_seekg(uint16_t value);

/* syscall: read one byte from the current device */
uint8_t sio_recv();
/* syscall: write one byte into the current device */
void sio_send(uint8_t value);

/* read n bytes from the current device */
char * sio_read(uint8_t *buffer, size_t n);
/* write n bytes into the current device */
int sio_write(const uint8_t *buffer, size_t n);

#endif
