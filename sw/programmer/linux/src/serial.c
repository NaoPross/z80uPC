#include "serial.h"

int serial_open(const char *devpath, unsigned long baudrate)
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

    // TODO: update UI or add support for custom baudrate
    // cfsetospeed(&tty, 
    // cfsetispeed(&tty, 

    tty.c_cflag &= ~PARENB;  // no parity
    tty.c_cflag &= ~CSTOPB;  // no stop bit
    tty.c_cflag |= CS8;      // 8 bit data
    tty.c_cflag &= ~CRTSCTS; // no flow control

    tty.c_lflag     =  0;  // no signaling chars, no echo, no canonical processing
    tty.c_oflag     =  0;  // no remapping, no delays
    tty.c_cc[VMIN]  =  0;  // no block read
    tty.c_cc[VTIME] = .5;  // .5 seconds read timeout

    tty.c_cflag |= CREAD | CLOCAL;      // turn on read and ignore ctrl lines
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // turn off s/w flow ctrl
    tty.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); // make raw
    tty.c_oflag &= ~OPOST; // make raw

    tcflush(fd , TCIFLUSH);
    // if (tcsetaddr(

    return fd;
}

