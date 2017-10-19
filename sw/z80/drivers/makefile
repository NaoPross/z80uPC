# Drivers library

LIB     := build/drivers.a
SOURCES := $(wildcard *.c)
OBJECTS := $(patsubst %.c,build/%.rel,$(SOURCES))

CC := sdcc
AR := sdar
CFLAGS := -mz80 -Iinclude -I../arch -DDEBUG

.PHONY: dirs clean
$(LIB): $(OBJECTS)
	$(AR) rcs $@ $(OBJECTS)

$(OBJECTS): build/%.rel: %.c $(SOURCES) dirs
	$(CC) $(CFLAGS) -c $< -o $@

dirs:
	mkdir -p build

clean:
	- rm -rd build
