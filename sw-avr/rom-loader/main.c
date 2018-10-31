#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>


#include "usart.h"
#include "pinmap.h"

inline void io_init(void)
{
    ADDRL_DDR |= (_BV(ADDRL_bitE) | _BV(ADDRL_bitD));
    ADDRL_DDR |= (0x7<<ADDRL_bitA0); // 3 bits

    ADDRH_DDR |= (_BV(ADDRH_bitE) | _BV(ADDRH_bitD));
    ADDRH_DDR |= (0x7<<ADDRH_bitA0);

    // all output
    DATA_DDR = 0xFF;
}

inline void set_addr(uint16_t addr)
{
    uint8_t i;

    // disable 74LS259 chips
    ADDRL_PORT &= ~(_BV(ADDRL_bitE));
    ADDRH_PORT &= ~(_BV(ADDRH_bitE));

    for (i = 0; i < 8; i++) {
        ADDRL_PORT &= ~(0x7<<ADDRL_bitA0);
        ADDRL_PORT |= (i<<ADDRL_bitA0);

        if (bit_is_set(addr, i))
            ADDRL_PORT |= _BV(ADDRL_bitD);
        else
            ADDRL_PORT &= ~(_BV(ADDRL_bitD));

        if (bit_is_set(addr, i+8))
            ADDRH_PORT |= _BV(ADDRH_bitD);
        else
            ADDRH_PORT &= ~(_BV(ADDRH_bitD));
    }
    
    // enable 74LS259 chips
    ADDRL_PORT |= _BV(ADDRL_bitE);
    ADDRH_PORT |= _BV(ADDRH_bitE);
}

int main(void)
{
    uint16_t addr = 0;

    io_init();
    usart_init();

    while (1) {
        DATA_PORT = usart_recv();
        set_addr(addr);

        _delay_ms(1);

        addr++;
    }

    return 0;
}
