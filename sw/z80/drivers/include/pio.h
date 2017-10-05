#ifndef __PIO_H__
#define __PIO_H__

#include "addresses.h"
#include <stdint.h>

#define PIO_A       0
#define PIO_B       1

#define PIO_MODE_BYTE_IN   0
#define PIO_MODE_BYTE_OUT  1
#define PIO_MODE_BYTE_BI   2
#define PIO_MODE_BIT_IO    3

#define PIO_INT_ACTIVE_HIGH     (1<<5)
#define PIO_INT_AND_MODE        (1<<6)
#define PIO_INT_ENABLE          (1<<7)


inline void _pio_data(int port, uint8_t data);
inline void _pio_control(int port, uint8_t cmd);

/* the last argument is needed only for IO mode */
void pio_set_mode(int port, int mode, uint8_t io);

void pio_set_interrupts(int port, int control);
void pio_set_interrupts_mask(int port, int control, uint8_t mask);

// uint8_t pio_read_data(int port);
uint8_t pio_read(int port);
void pio_write(int port, uint8_t data);

inline int pio_read_pin(int port, uint8_t pin);
inline void pio_write_pin(int port, uint8_t pin);

// TODO: implement mode (in/out/both) and interrupt vector

#endif /* __PIO_H__ */
