####
# source code settings
#
OSNAME := helvetiOS
 
CSOURCES 	:=  $(wildcard *.c) \
				$(wildcard drivers/*.c)

OBJECTS 	:= $(patsubst %.c,build/%.rel,$(CSOURCES))
HEXFILE		:= build/$(OSNAME).hex
BINARY  	:= build/$(OSNAME).bin

### 
# compiler settings

CC 		:= sdcc

CFLAGS	:= -mz80 \
			-I include \
			-I include/drivers \
			-I libc/include \
			--opt-code-size \
			-DDEBUG

LDFLAGS := -mz80 --no-std-crt0 build/crt0.rel \
			--std-c89 -pedantic \
			--code-loc 0x0800 --data-loc 0x8000

.PHONY: dirs dis clean
all: $(BINARY)

# build binary
$(BINARY): $(OBJECTS) dirs
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(HEXFILE)
	makebin -s 16384 $(HEXFILE) $(BINARY)

$(OBJECTS): build/%.rel : %.c $(CSOURCES) dirs build/crt0.rel
	@printf "\n"
	$(CC) $(CFLAGS) -c $< -o $@

build/crt0.rel: crt0.s
	sdasz80 -o $<
	@mv crt0.rel build

dirs:
	mkdir -p build build/kernel build/libc build/kernel/drivers

dis: $(BINARY)
	dz80 -b -n $<

clean:
	- rm -rd build/*
	- rm crt0.rel
