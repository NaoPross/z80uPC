####
# source code settings
#
OSNAME := helvetiOS
 
CSOURCES 	:= $(wildcard kernel/*.c) $(wildcard libc/*.c)
HEXFILE		:= build/$(OSNAME).hex
BINARY  	:= build/$(OSNAME).bin

### 
# compiler settings

CC 		:= sdcc

CFLAGS	:= -mz80 --no-std-crt0 crt0.rel \
			-I kernel/include -I libc/include -DDEBUG

LDFLAGS := --code-loc 0x0800 --data-loc 0x8000

all: $(BINARY)

# build binary
$(BINARY): $(CSOURCES) crt0.rel
	mkdir -p build
	$(CC) $(CFLAGS) $(LDFLSGS) $(CSOURCES) -o $(HEXFILE)
	xxd -r -p $(HEXFILE) $(BINARY)

crt0.rel: crt0.s
	sdasz80 -o $<

dis: $(BINARY)
	z80dasm -a -g 0h $< -o $(OSNAME).s

clean:
	- rm build/*
	- rm $(OSNAME).s
	- rm crt0.rel
