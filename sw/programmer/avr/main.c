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

void eeprom_write(uint16_t addr, uint8_t byte);
void eeprom_tick();

int main(void)
{
    uint8_t *buffer, i;
    size_t read;
    char str[64];

    struct file_blk *blk = malloc(sizeof(struct file_blk));

    DDRB = 0x7F;
    DDRC = 0x83;
    DDRD = 0xFC;

    /* get configuration */
    usart_init(1200); 
    usart_print("programmer Ready\n<waiting for binary>\n\r");

    while (usart_read((uint8_t *) blk, sizeof(struct file_blk))) {
        buffer = malloc(blk->size);
        read = usart_read(buffer, blk->size);

#ifdef DEBUG
        sprintf(str, "info : reading block from addr %d of size %d\n\r", 
                blk->addr, blk->size);
        usart_print(str);

        if (read != blk->size) {
            sprintf(str, "error: expected %d but read %d\n\r", 
                    blk->size, read);
            usart_print(str);
        }
#endif

        for (i = 0; i < read; i++) {
            eeprom_write(blk->addr +i, buffer[i]);
        }

        free(buffer);
    }

    free(blk);
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

