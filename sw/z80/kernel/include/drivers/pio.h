#ifndef __PIO_H__
#define __PIO_H__

#include "devices.h"
#include "types.h"

#define PIO_A       0
#define PIO_B       1

#define PIO_MODE_0  0
#define PIO_MODE_1  1
#define PIO_MODE_2  2
#define PIO_MODE_3  3

#define PIO_INT_ACTIVE_HIGH     (1<<5)
#define PIO_INT_AND_MODE        (1<<6)
#define PIO_INT_ENABLE          (1<<7)


void _pio_data(int port, uint8_t data);
void _pio_command(int port, uint8_t cmd);

void pio_set_mode(int port, int mode);
void pio_set_interrupts(int port, int control);
void pio_set_interrupts_mask(int port, uint8_t mask);
void pio_set_io(int port, uint8_t io);

// uint8_t pio_read_data(int port);

inline int pio_read_pin(int port, uint8_t pin);
inline void pio_write_pin(int port, uint8_t pin);

// TODO: implement mode (in/out/both) and interrupt vector

#endif // __PIO_H__
