#include "drivers/pio.h"

static uint8_t *pio_port = (uint8_t *) ADDR_DEV_PIO;
static uint8_t *pio_ctrl = (uint8_t *) (ADDR_DEV_PIO + 2);

void _pio_data(int port, uint8_t data)
{
    *(pio_port + port) = data;
}

void _pio_command(int port, uint8_t cmd)
{
    *(pio_ctrl + port) = cmd;
}

void pio_set_mode(int port, int mode)
{
	
}
