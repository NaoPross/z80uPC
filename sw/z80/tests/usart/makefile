####
# source code settings
#
OSNAME := usart_test
 
CSOURCES 	:=  $(wildcard *.c)
LIBS 		:= ../../arch/build/arch.a \
			   ../../drivers/build/drivers.a

OBJECTS 	:= $(patsubst %.c,build/%.rel,$(CSOURCES))
HEXFILE		:= build/$(OSNAME).hex
BINARY  	:= build/$(OSNAME).bin

### 
# compiler settings
#
CC 		:= sdcc

CFLAGS	:= -mz80 \
			--no-std-crt0 build/crt0.rel \
			--allow-unsafe-read \
			-I . \
			-I ../../arch/include \
			-I ../../drivers/include \
			-DDEBUG

LDFLAGS := -mz80 \
			--no-std-crt0 build/crt0.rel \
			-L ../../drivers/build \
			-l drivers.a \
			-pedantic \
			--code-loc 0x0200
			# --data-loc 0x2000

.PHONY: flash dirs dis clean
all: $(BINARY)

flash: $(BINARY)
	minipro -p M28C64 -w $< 

# build binary
$(BINARY): $(OBJECTS) dirs
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(HEXFILE)
	makebin -s 8192 -yo 1 $(HEXFILE) $(BINARY)

$(OBJECTS): build/%.rel : %.c $(CSOURCES) dirs build/crt0.rel $(LIBS)
	@printf "\n"
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBS): %.a:
	@printf "\n"
	make -C $(shell printf $@ | sed 's:build.*.::')

build/crt0.rel: crt0.s
	sdasz80 -o $<
	@mv crt0.rel build/

dirs:
	mkdir -p build

dis: $(BINARY)
	dz80 -b -n -t $(BINARY)
	r2 -a z80 $< \
	-c 'afn main 0x200; \
		pd 0x10; \
		s 0x100; \
		pd 10; \
		s 0x200; \
		pd 0x95'

clean:
	- rm -rd build
