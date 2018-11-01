.PHONY: all disassemble clean
all: hello.bin

disassemble: hello.bin
	z80dasm $<

clean:
	rm -f hello.bin

hello.bin: hello.s
	z80asm -o $@ $<
