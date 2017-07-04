####
# source code settings
#
OSNAME := helvetiOS
 
CSOURCES 	:=  $(wildcard kernel/*.c) \
				$(wildcard kernel/drivers/*.c) \
				$(wildcard libc/*.c) 

OBJECTS 	:= $(patsubst %.c,build/%.rel,$(CSOURCES))
HEXFILE		:= build/$(OSNAME).hex
BINARY  	:= build/$(OSNAME).bin

### 
# compiler settings

CC 		:= sdcc

CFLAGS	:= -mz80 \
			-I kernel/include \
			-I kernel/include/drivers \
			-I libc/include \
			-DDEBUG

LDFLAGS := -mz80 --no-std-crt0 crt0.rel \
			--code-loc 0x0800 --data-loc 0x8000

.PHONY: dirs dis clean
all: $(BINARY)

# build binary
$(BINARY): $(OBJECTS) dirs
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(HEXFILE)
	@# xxd -r -p $(HEXFILE) $(BINARY)
	makebin -s 16384 $(HEXFILE) $(BINARY)

$(OBJECTS): build/%.rel : %.c $(CSOURCES) dirs crt0.rel
	@printf "\n"
	$(CC) $(CFLAGS) -c $< -o $@

crt0.rel: crt0.s
	sdasz80 -o $<

dirs:
	mkdir -p build build/kernel build/libc

dis: $(BINARY)
	@# z80dasm -a -l -g 0h $< -o build/$(OSNAME).s
	dz80 -b -n $<

clean:
	- rm -rd build/*
	- rm crt0.rel
