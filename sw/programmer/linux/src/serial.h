#ifndef __Z80PROG_SERIAL_H__
#define __Z80PROG_SERIAL_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <termio.h>
#include <err.h>
#include <linux/serial.h>

int serial_open(const char *devpath, unsigned long baudrate);

#endif
