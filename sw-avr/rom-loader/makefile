SOURCES := main.c usart.c
OBJECTS := $(patsubst %.c,%.o,$(SOURCES))

CFLAGS  := -Wall -mmcu=atmega328p -Os -I. \
            -D__AVR_ATmega328p__ -DF_CPU=1000000UL -DBAUD=9600
LDFLAGS := 

.PHONY: all flash clean
all: rom-loader.hex

flash: rom-loader.hex
	avrdude -c usbasp -p atmega328p -U flash:w:$<

clean:
	rm -f *.bin *.hex *.o

rom-loader.hex: rom-loader.bin
	avr-objcopy -R .eeprom -O ihex $< $@

rom-loader.bin: $(OBJECTS)
	avr-gcc $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.c
	avr-gcc $(CFLAGS) $< -c -o $@ $(LDFLAGS)
