#ifndef __Z80PROG_SERIAL_H__
#define __Z80PROG_SERIAL_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

int serial_connect(const char *devpath, long baudrate);
void serial_close(int fd);

void serial_program(const char *rompath);
void serial_read_rom(const char *rom);

#endif
