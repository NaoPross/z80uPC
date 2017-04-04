####
# source code settings
#
OSNAME := helvetiOS

CSOURCES 	:= $(wildcard *.c)
BINARY  	:= $(OSNAME).bin

### 
# compiler settings
#
CC 		:= zcc
CARGS 	:= -Wall -I . -DDEBUG -crt0 loader -asm z80asm -nostdlib

all: $(BINARY)

# build binary
$(BINARY): $(CSOURCES)
	cp loader.asm loader.opt
	$(CC) $(CARGS) $(CSOURCES) -o $@

dis: $(BINARY)
	z80dasm -a -g 0h $<

clean:
	- rm $(BINARY)
	- rm loader.opt
