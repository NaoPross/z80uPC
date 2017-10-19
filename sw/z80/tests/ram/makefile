####
# source code settings
#
OSNAME := ram_test
 
CSOURCES 	:=  $(wildcard *.c)

OBJECTS 	:= $(patsubst %.c,build/%.rel,$(CSOURCES))
HEXFILE		:= build/$(OSNAME).hex
BINARY  	:= build/$(OSNAME).bin

### 
# compiler settings
#
CC 		:= sdcc

CFLAGS	:= -mz80 \
			-I . \
			-DDEBUG

LDFLAGS := -mz80 \
			--no-std-crt0 build/crt0.rel \
			-pedantic 

			# --code-loc 0x0120 \
			# --data-loc 0x2000

.PHONY: flash dirs dis clean
all: $(BINARY)

flash: $(BINARY)
	minipro -p M28C64 -w $< 

# build binary
$(BINARY): $(OBJECTS) dirs
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(HEXFILE)
	makebin -s 8192 -yo 1 $(HEXFILE) $(BINARY)

$(OBJECTS): build/%.rel : %.c $(CSOURCES) dirs build/crt0.rel
	@printf "\n"
	$(CC) $(CFLAGS) -c $< -o $@

build/crt0.rel: crt0.s
	sdasz80 -o $<
	@mv crt0.rel build/

dirs:
	mkdir -p build

dis: $(BINARY)
	#dz80 -b -n $<
	r2 -a z80 $< -c 'pd 0x10; s 0x100; pd 10; s 0x200; pd 10'

clean:
	- rm -rd build
