#include "fileinfo.h"
#include "usart.h"
#include <util/delay.h>

#define EEPROM_TICK_MS  10

#define ADDRCR      PORTB
#define EEPROMCR    PORTC
#define EEPROMDR    PORTD

#define ADDR_BIT    0
#define ADDR_EL     3
#define ADDR_EH     4
#define ADDR_DL     5
#define ADDR_DH     6

#define EEPROM_WR   0
#define EEPROM_RD   1
#define EEPROM_CLK  2


void eeprom_write(uint16_t addr, uint8_t byte);
void eeprom_tick();

int main(void)
{
    uint8_t *buffer, i;
    uint16_t addr;
    size_t read;

    struct file_info *finfo =  malloc(sizeof(struct file_info));

    DDRB = 0x7F;
    DDRC = 0x83;
    DDRD = 0xFC;

    /* get configuration */
    usart_init(1200); 

    usart_print("EEPROM Programmer\n\r");

    do {
        usart_print("Waiting for configuration\n\r");
        read = usart_read((uint8_t *) finfo, sizeof(struct file_info));
    } while (read != sizeof(struct file_info));

    usart_print("Programmer Ready\n<waiting for binary>\n\r");

    buffer = malloc(finfo->blklen);
    addr = finfo->start_addr;

    /* read file */
    while ((read = usart_read(buffer, finfo->blklen))) {
        for (i = 0; i < read; i++) {
            eeprom_write(addr + i, *(buffer++));
        }

        addr += finfo->blklen;
    }

    return 0;
}


void eeprom_write(uint16_t addr, uint8_t byte)
{
    int bit;

    /* set address */
    for (bit = 0; bit < 8; bit++) {
        // clear bit
        ADDRCR &= ~0x07;
        // select the bit
        ADDRCR |= bit;

        // write bit for lower byte
        if (addr & _BV(bit))
            ADDRCR |= _BV(ADDR_DL);
        else
            ADDRCR &= ~_BV(ADDR_DL);

        // write bit for higher byte
        if ((addr>>8) & _BV(bit))
            ADDRCR |= _BV(ADDR_DH);
        else
            ADDRCR &= ~_BV(ADDR_DH);
    }

    /* set data */
    EEPROMDR = byte;
    EEPROMCR &= ~(_BV(ADDR_EH) | _BV(ADDR_EL));

    /* write eeprom */
    EEPROMCR &= ~_BV(EEPROM_WR);
    eeprom_tick();

    EEPROMCR |= _BV(EEPROM_WR);
    EEPROMCR |= _BV(ADDR_EH) | _BV(ADDR_EL);
}

/* pulse the clock line for the eeprom */
void eeprom_tick()
{
    EEPROMCR |= _BV(EEPROM_CLK);
    _delay_ms(EEPROM_TICK_MS);         
    EEPROMCR &= ~_BV(EEPROM_CLK);
    _delay_ms(EEPROM_TICK_MS);         
}

