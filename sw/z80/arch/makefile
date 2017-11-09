# Drivers library

LIB     := build/arch.a
SOURCES := $(wildcard *.c)
OBJECTS := $(patsubst %.c,build/%.rel,$(SOURCES))

F_CPU := 10000

CC := sdcc
AR := sdar
CFLAGS := -mz80 \
			-Iinclude \
			-DDEBUG \
			-DF_CPU=$(F_CPU)

.PHONY: dirs clean
$(LIB): $(OBJECTS)
	$(AR) rcs $@ $(OBJECTS)

$(OBJECTS): build/%.rel: %.c $(SOURCES) dirs
	$(CC) $(CFLAGS) -c $< -o $@

dirs:
	mkdir -p build

clean:
	- rm -rd build
