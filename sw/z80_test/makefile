####
# source code settings
#
OSNAME := sample
 
CSOURCES 	:=  $(wildcard *.c)

OBJECTS 	:= $(patsubst %.c,build/%.rel,$(CSOURCES))
HEXFILE		:= build/$(OSNAME).hex
BINARY  	:= build/$(OSNAME).bin

### 
# compiler settings

CC 		:= sdcc

CFLAGS	:= -mz80 \
			-I . \
			-DDEBUG

LDFLAGS := -mz80 --no-std-crt0 build/crt0.rel \
			--std-c89 -pedantic \
			--code-loc 0x0800 --data-loc 0x2000

.PHONY: dirs dis clean
all: $(BINARY)

# build binary
$(BINARY): $(OBJECTS) dirs
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(HEXFILE)
	@# xxd -r -p $(HEXFILE) $(BINARY)
	@# makebin -s 16384 $(HEXFILE) $(BINARY)
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
