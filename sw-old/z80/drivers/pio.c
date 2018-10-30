#include "pio.h"

#ifdef PIO_ASM_INTERFACE
// TODO: set inline
void _pio_write(uint8_t reg, uint8_t data)
{
    __asm
    ;;  pop function arguments data in h, reg in a (l)
    pop hl
    ld a, l
    ;; add ADDR_DEV_PIO to get the device address
    add a, #ADDR_DEV_PIO
    ld c, a
    ;; load data
    out (c), h
    __endasm;
}

inline uint8_t _pio_read(uint8_t reg)
{
    // TODO: check "dec sp"
    __asm
    ;; pop function argument
    dec sp
    pop hl
    ld a, l
    ;; add ADDR_DEV_PIO to get the device address
    add a, #ADDR_DEV_PIO
    ld c, a
    ;; read data
    in l, (c)
    ret
    __endasm;
}

#else

inline void _pio_write(uint8_t reg, uint8_t data)
{
    *((uint8_t *) (ADDR_DEV_PIO + reg)) = data;
}

inline uint8_t _pio_read(uint8_t reg)
{
    return *((uint8_t *) (ADDR_DEV_PIO + reg));
}

#endif

void pio_set_mode(int port, int mode, uint8_t io)
{
    // 0x0F is a control sequence to set mode
    _pio_write((PIO_REG_CTRL + port), ((mode << 6) | 0x0F));

    // this mode requires an additional argument that sets
    // a mode for each pin
    if (mode == PIO_MODE_BIT_IO) {
        _pio_write((PIO_REG_CTRL + port), io);
    }
}

void pio_set_interrupts(int port, int control)
{
    // 0x07 is a control sequence to set interrupts
    _pio_write((PIO_REG_CTRL + port), (control<<4 | 0x07));
}

void pio_set_interrupts_mask(int port, int control, uint8_t mask)
{
    // 0x17 is a control sequence to set interrupts
    // AND interpret the next byte as a bitmask
    _pio_write((PIO_REG_CTRL + port),(control | 0x97));
    _pio_write((PIO_REG_CTRL + port), mask);
}

uint8_t pio_read(int port)
{
    return _pio_read((PIO_REG_DATA + port));
}

void pio_write(int port, uint8_t data)
{
    _pio_write((PIO_REG_DATA + port), data);
}
