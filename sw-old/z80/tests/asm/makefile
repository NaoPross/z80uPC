####
# source code settings
#
OSNAME := ram_test
 
CSOURCES 	:=  $(wildcard *.s)

OBJECTS 	:= $(patsubst %.s,build/%.rel,$(SOURCES))
HEXFILE		:= build/$(OSNAME).hex
BINARY  	:= build/$(OSNAME).bin

### 
# compiler settings
#
ASM		:= sdasz80
LD		:= sdldz80

FLAGS	:= 
LDFLAGS :=

.PHONY: flash dirs dis clean
all: $(BINARY)

flash: $(BINARY)
	minipro -p M28C64 -w $< 

# build binary
$(BINARY): $(OBJECTS) dirs
	$(LD) $(LDFLAGS) $(OBJECTS) -o $(HEXFILE)
	makebin -s 8192 -yo 1 $(HEXFILE) $(BINARY)

$(OBJECTS): build/%.rel : %.s $(SOURCES) dirs
	@printf "\n"
	$(ASM) $(FLAGS) $< -o

build/crt0.rel: crt0.s
	sdasz80 -o $<
	@mv crt0.rel build/

dirs:
	mkdir -p build

dis: $(BINARY)
	r2 -a z80 $< -c 'pd 0x10; s 0x100; pd 10; s 0x200; pd 10'

clean:
	- rm -rd build
