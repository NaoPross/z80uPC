# Drivers library

LIB     := build/drivers.a
SOURCES := $(wildcard *.c)
OBJECTS := $(patsubst %.c,build/%.rel,$(SOURCES))

CC := sdcc
AR := sdar
CFLAGS := -mz80 -Iinclude -I../arch/include -DDEBUG

.PHONY: dirs rebuild clean
$(LIB): $(OBJECTS)
	$(AR) vrcs $@ $(OBJECTS)

$(OBJECTS): build/%.rel: %.c $(SOURCES) dirs
	$(CC) $(CFLAGS) -c $< -o $@

rebuild: clean $(LIB)

dirs:
	mkdir -p build

clean:
	- rm -rd build
