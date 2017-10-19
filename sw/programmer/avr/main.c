#include "usart.h"

#include <stdio.h>
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


struct file_blk
{
    uint16_t addr;
    uint16_t size;
};

void eeprom_set_addr(uint16_t addr);
void eeprom_write(uint16_t addr, uint8_t byte);
uint8_t eeprom_read(uint16_t addr);

int main(void)
{
    uint8_t *buffer, i;
    size_t read;

    struct file_blk *blk = malloc(sizeof(struct file_blk));

    DDRB = 0x7F;
    DDRC = 0x1F;
    DDRD = 0xFD;

    /* get configuration */
    usart_init(1200); 

    while (usart_read((uint8_t *) blk, sizeof(struct file_blk))) {
        buffer = malloc(blk->size);
        read = usart_read(buffer, blk->size);

        for (i = 0; i < read; i++) {
            eeprom_write(blk->addr +i, buffer[i]);
            _delay_ms(5);
            eeprom_read(blk->addr +i); // != buffer[i];
        }

        free(buffer);
        usart_send_byte(0x06);
        usart_send_byte(0x06);
        usart_send_byte(0x06);
    }

    free(blk);
    return 0;
}

void eeprom_set_addr(uint16_t addr)
{
    int bit;

    for (bit = 0; bit < 8; bit++) {
        // clear bits
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

        _delay_ms(5);
    }
}

void eeprom_write(uint16_t addr, uint8_t byte)
{
    eeprom_set_addr(addr);

    DDRC |= 0x18; // ED1 ED0
    DDRD |= 0xFC; // ED7-ED2

    /* set data */
    EEPROMDR = byte & 0xFC;

    // because EEPROMDR0 and EEPROMDR1 are used by Tx and Rx
    EEPROMCR = (PINC & 0xE7) | (byte & 0x03)<<3;

    /* enable address output */
    EEPROMCR &= ~(_BV(ADDR_EH) | _BV(ADDR_EL));

    /* write eeprom */
    EEPROMCR &= ~_BV(EEPROM_WR);
    _delay_ms(5);

    /* reset */
    EEPROMCR |= _BV(EEPROM_WR);
    EEPROMCR |= _BV(ADDR_EH) | _BV(ADDR_EL);
}

uint8_t eeprom_read(uint16_t addr)
{
    uint8_t data;

    eeprom_set_addr(addr);

    DDRC &= ~0x18;
    DDRD &= ~0xFC;

    /* enable address output */
    EEPROMCR &= ~(_BV(ADDR_EH) | _BV(ADDR_EL));

    /* enable read eeprom */
    EEPROMCR &= ~_BV(EEPROM_RD);
    data = (PINC & 0x18) | (PIND & 0xFB);
    _delay_ms(5);

    /* reset */
    EEPROMCR |= _BV(EEPROM_RD);
    EEPROMCR |= _BV(ADDR_EH) | _BV(ADDR_EL);

    return data;
}
