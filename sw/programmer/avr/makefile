###
# Project settings
#
TARGET := programmer
SOURCES := $(wildcard *.c)

###
# Compiler settings
#
CC   := avr-gcc
PORT := /dev/ttyUSB0
MCU  := atmega328p

CFLAGS  := -g -Wall -mcall-prologues -mmcu=$(MCU) -Os -I . \
			-DF_CPU=1000000UL
LDFLAGS := -Wl,-gc-sections -Wl,-relax

.PHONY: all clean program
all: $(TARGET).hex

clean:
	rm -f *.o *.hex *.obj *.bin

$(TARGET).hex: $(TARGET).bin
	avr-objcopy -R .eeprom -O ihex $(TARGET).bin $@

$(TARGET).bin: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@ $(LDFLAGS)

program: $(TARGET).hex
	avrdude -p $(MCU) -c usbasp -P usb -U flash:w:$(TARGET).hex
