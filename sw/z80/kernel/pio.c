#include "pio.h"

static uint8_t *pio_port_a = (uint8_t *) ADDR_DEV_PIO;
static uint8_t *pio_port_b = (uint8_t *) ADDR_DEV_PIO + 1;
static uint8_t *pio_ctrl_a = (uint8_t *) ADDR_DEV_PIO + 2;
static uint8_t *pio_ctrl_b = (uint8_t *) ADDR_DEV_PIO + 3;

void pio_data(int port, uint8_t data)
{
    if (port == PIO_A)
        *pio_port_a = cmd;
    else
        *pio_port_b = cmd;
}

void pio_command(int port, uint8_t cmd)
{
    if (port == PIO_A)
        *pio_ctrl_a = cmd;
    else
        *pio_ctrl_b = cmd;
}



inline int pio_read_pin(int port, uint8_t pin)
{

}
