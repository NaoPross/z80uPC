####
# source code settings
#
OSNAME := pio_test
 
CSOURCES 	:=  $(wildcard *.c)

OBJECTS 	:= $(patsubst %.c,build/%.rel,$(CSOURCES))
HEXFILE		:= build/$(OSNAME).hex
BINARY  	:= build/$(OSNAME).bin

### 
# compiler settings
#
CC 		:= sdcc

CFLAGS	:= -mz80 \
			--allow-unsafe-read \
			-I . \
			-I ../../arch \
			-I ../../drivers/include \
			-DDEBUG

LDFLAGS := -mz80 \
			--no-std-crt0 build/crt0.rel \
			-L ../../drivers/build \
			-l drivers.a \
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
	r2 -a z80 $< -A \
	-c 'afr main 0x200; \
		pd 0x10; \
		s 0x100; \
		pd 10; \
		s 0x200; \
		pd 0x40' \

clean:
	- rm -rd build
