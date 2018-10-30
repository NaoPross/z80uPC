#include <avr/io.h>

#include "usart.h"
#include "pinmap.h"

// TODO: remove
#include <util/delay.h>


inline void io_init(void)
{
    ADDRL_DDR |= (_BV(ADDRL_bitE) | _BV(ADDRL_bitD));
    ADDRL_DDR |= (0x7<<ADDRL_bitA0); // 3 bits

    ADDRH_DDR |= (_BV(ADDRH_bitE) | _BV(ADDRH_bitD));
    ADDRH_DDR |= (0x7<<ADDRH_bitA0);

    // all output
    DATA_DDR = 0xFF;
}

int main(void)
{
    io_init();
    usart_init();

    // TODO: remove
    DATA_PORT |= _BV(1);

    while (1) {
        DATA_PORT ^= _BV(1);
        _delay_ms(500);

        usart_send('c');
    }

    return 0;
}
