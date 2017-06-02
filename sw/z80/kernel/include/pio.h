#ifndef __PIO_H__
#define __PIO_H__

#define PIO_A   0
#define PIO_B   1


void pio_data(int port, uint8_t data);
void pio_command(int port, uint8_t cmd);

uint8_t pio_read_data(int port);

inline int pio_read_pin(int port, uint8_t pin);
inline void pio_write_pin(int port, uint8_t pin);

// TODO: implement mode (in/out/both) and interrupt vector

#endif // __PIO_H__
