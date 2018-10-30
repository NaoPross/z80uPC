CC=avr-gcc
CARGS=-Wall -mmcu=atmega328p -D__AVR_ATmega328p__ -Os -I.

SOURCES=main.c

.PHONY: all flash clean
all: rom-loader.bin

flash: rom-loader.bin
	avrdude -c usbasp -p atmega328p

clean:
	rm rom-loader.bin

rom-loader.bin: $(SOURCES)
	$(CC) $(CARGS) $< -o $@

