#include "pio.h"

static uint8_t *pio_port = (uint8_t *) ADDR_DEV_PIO;
static uint8_t *pio_ctrl = (uint8_t *) (ADDR_DEV_PIO + 2);

inline void _pio_data(int port, uint8_t data)
{
    *(pio_port + port) = data;
}

inline void _pio_control(int port, uint8_t cmd)
{
    *(pio_ctrl + port) = cmd;
}

void pio_set_mode(int port, int mode, uint8_t io)
{
    // 0x0F is a control sequence to set mode
    _pio_control(port, ((mode << 6) | 0x0F));

    // this mode requires an additional argument that sets
    // a mode for each pin
    if (mode == PIO_MODE_BIT_IO) {
        _pio_control(port, io);
    }
}

void pio_set_interrupts(int port, int control)
{
    // 0x07 is a control sequence to set interrupts
    _pio_control(port, (control | 0x07));
}

void pio_set_interrupts_mask(int port, int control, uint8_t mask)
{
    // 0x17 is a control sequence to set interrupts
    // and to interpret the next byte as a mask
    _pio_control(port, (control | 0x17));
    _pio_control(port, mask);
}
