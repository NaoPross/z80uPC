####
# source code settings
#
NAME := pio_test
 
CSOURCES 	:= $(wildcard *.c)

OBJECTS 	:= $(patsubst %.c,build/%.rel,$(CSOURCES))
HEXFILE		:= build/$(NAME).hex
BINARY  	:= build/$(NAME).bin

### 
# compiler settings
#
CC 		:= sdcc

CFLAGS	:= -mz80 \
			-pedantic \
			-I . \
			-I ../../arch \
			-I ../../drivers/include \
			-DDEBUG

LDFLAGS := -mz80 \
			-L ../../drivers/build/ \
			-l drivers.a \
			--no-std-crt0 build/crt0.rel \
			--code-loc 0x0800 \
			--data-loc 0x2000

.PHONY: dirs dis clean
all: $(BINARY)

# build binary
$(BINARY): $(OBJECTS) dirs
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(HEXFILE)
	makebin -s 8192 $(HEXFILE) $(BINARY)

$(OBJECTS): build/%.rel : %.c $(CSOURCES) dirs build/crt0.rel
	@printf "\n"
	$(CC) $(CFLAGS) -c $< -o $@

build/crt0.rel: crt0.s
	sdasz80 -o $<
	@mv crt0.rel build/

dirs:
	mkdir -p build

dis: $(BINARY)
	@# z80dasm -a -l -g 0h $< -o build/$(OSNAME).s
	dz80 -b -n $<

clean:
	- rm -rd build/*
	- rm crt0.rel
