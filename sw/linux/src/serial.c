#include "serial.h"

int serial_connect(const char *devpath, long baudrate)
{
    int fd;
    struct termios tty;
    // struct termios tty_old;
    
    // open device
    if ((fd = open(devpath, O_RDWR | O_NOCTTY)) < 0) {
        return -1;
    }

    // set parameters
    if (tcgetattr(fd, &tty) != 0) {
        return -1;
    }

    // cfsetospeed(&tty, 

    return fd;
}
