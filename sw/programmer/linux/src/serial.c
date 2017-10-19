#include "serial.h"

static int rate_to_constant(int baudrate) {
#define B(x) case x: return B##x
    switch(baudrate) {
        B(50);     B(75);     B(110);    B(134);    B(150);
        B(200);    B(300);    B(600);    B(1200);   B(1800);
        B(2400);   B(4800);   B(9600);   B(19200);  B(38400);
        B(57600);  B(115200); B(230400); B(460800); B(500000); 
        B(576000); B(921600); B(1000000);B(1152000);B(1500000); 
    default: return 0;
    }
#undef B
}

int serial_open(const char *devpath, unsigned long baudrate)
{
    int fd, speed;
    struct termios tty;
    struct serial_struct serinfo;
    // struct termios tty_old;
    
    // open device
    if ((fd = open(devpath, O_RDWR | O_NOCTTY)) < 0) {
        return -1;
    }

    speed = rate_to_constant(baudrate);
    if (speed == 0) {
        /* custom divisor */
        serinfo.reserved_char[0] = 0;
        if (ioctl(fd, TIOCGSERIAL, &serinfo) < 0)
            return -1;
        serinfo.flags &= ~ASYNC_SPD_MASK;
        serinfo.flags |= ASYNC_SPD_CUST;
        serinfo.custom_divisor = (serinfo.baud_base + (baudrate / 2)) / baudrate;

        if (serinfo.custom_divisor < 1) 
            serinfo.custom_divisor = 1;
        if (ioctl(fd, TIOCSSERIAL, &serinfo) < 0)
            return -1;
        if (ioctl(fd, TIOCGSERIAL, &serinfo) < 0)
            return -1;
        if (serinfo.custom_divisor * baudrate != serinfo.baud_base) {
            warnx("actual baudrate is %d / %d = %f",
                  serinfo.baud_base, serinfo.custom_divisor,
                  (float)serinfo.baud_base / serinfo.custom_divisor);
        }
    }

    // set custom baudrate
    ioctl(fd, TIOCGSERIAL, &serinfo);
    serinfo.flags = ASYNC_SPD_CUST | ASYNC_LOW_LATENCY; 
    serinfo.custom_divisor = serinfo.baud_base / baudrate; 
    ioctl(fd, TIOCSSERIAL, &serinfo);

    // set parameters
    if (tcgetattr(fd, &tty) != 0) {
        // perror("failed tcgetattr");
        return -1;
    }

    cfsetispeed(&tty, speed ?: B38400);
    cfsetospeed(&tty, speed ?: B38400);
    cfmakeraw(&tty);

    tty.c_cflag &= ~PARENB;  // no parity
    tty.c_cflag &= ~CSTOPB;  // no stop bit
    tty.c_cflag |= CS8;      // 8 bit data
    tty.c_cflag &= ~CRTSCTS; // no flow control

    tty.c_lflag     =  0;  // no signaling chars, no echo, no canonical processing
    tty.c_oflag     =  0;  // no remapping, no delays
    tty.c_cc[VMIN]  =  0;  // no block read
    tty.c_cc[VTIME] =  5;  // .5 seconds read timeout

    tty.c_cflag |= CREAD | CLOCAL;      // turn on read and ignore ctrl lines
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // turn off s/w flow ctrl
    tty.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); // make raw
    tty.c_oflag &= ~OPOST; // make raw

    tcflush(fd , TCIFLUSH); // ?

    if (tcsetattr (fd, TCSANOW, &tty) != 0) {
        // perror("failed tcsetattr to set serial port.\n");
        return -1;
    }

    return fd;
}
