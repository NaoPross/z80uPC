#include "pio.h"

#if 0 /* old inline asm implementation */
inline void _pio_write(uint8_t reg, uint8_t data)
{
    __asm
    ;; pop function arguments
    pop hl
    ;; store data in A
    ld a, h
    ld h, #0
    ;; add ADDR_DEV_PIO to get the device address
    ld bc, #ADDR_DEV_PIO
    add hl, bc
    ;; load data
    ld (hl), a
    __endasm;
}

// incomplete
inline uint8_t _pio_read(uint8_t reg) __naked
{
    __asm
    ;; pop function argument
    pop l
    ld h, #0
    ;; add ADDR_DEV_PIO to get the device address
    ld bc, #ADDR_DEV_PIO
    add hl, bc
    ld l, (hl)
    ret
    __endasm;
}
#endif 

inline void _pio_write(uint8_t reg, uint8_t data)
{
    *((uint8_t *) (ADDR_DEV_PIO + reg)) = data;
}

inline uint8_t _pio_read(uint8_t reg)
{
    return *((uint8_t *) (ADDR_DEV_PIO + reg));
}

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
    _pio_write((PIO_REG_CTRL + port), (control | 0x07));
}

void pio_set_interrupts_mask(int port, int control, uint8_t mask)
{
    // 0x17 is a control sequence to set interrupts
    // AND interpret the next byte as a bitmask
    _pio_write((PIO_REG_CTRL + port),(control | 0x17));
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
