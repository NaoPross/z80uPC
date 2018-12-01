#include "serial.hpp"

#include <ios>

extern "C" {
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
}

serial::serial(const std::string& port, speed_t baud)
{
    m_fd = open(port.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);

    if (m_fd < 0) {
        throw std::ios_base::failure("Failed to open serial port " + port);
    }

    tcgetattr(m_fd, &m_settings);

    // set input and output baudrate
    cfsetispeed(&m_settings, baud);
    cfsetospeed(&m_settings, baud);

    // disable parity, 1 stop bit, clear data size
    m_settings.c_cflag &= ~(PARENB | CSTOPB | CSIZE);
    // set data size to 8
    m_settings.c_cflag |= CS8;

    // disable hw flow control
    m_settings.c_cflag &= ~CRTSCTS;
    // enable receiver and ignore modem lines
    m_settings.c_cflag |= CREAD | CLOCAL;

    // disable XON / XOFF flow control
    m_settings.c_iflag &= ~(IXON | IXOFF | IXANY);
    // non canonical mode
    m_settings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);

    // no output processing
    m_settings.c_oflag &= ~OPOST;
    
    // input buffer of 8 bytes
    m_settings.c_cc[VMIN] = 8;
    // set indefinite timeout
    m_settings.c_cc[VTIME] = 0;

    if ((tcsetattr(m_fd, TCSANOW, &m_settings)) != 0)
        throw std::ios_base::failure("Failed to set attributes");

    // clean rx buffer
    tcflush(m_fd, TCIFLUSH);
}

serial::~serial()
{
    if (m_fd > 0)
        ::close(m_fd);
}

int serial::write(const std::string& data) const
{
    write(data.c_str(), data.length());
}

int serial::write(const char * const data, size_t len) const
{
    return ::write(m_fd, data, len);
}

char serial::read() const
{
    char ch;

    if (::read(m_fd, &ch, 1) < 0)
        throw std::ios_base::failure("Failed to read");

    return ch;
}

std::string serial::read(size_t howmany) const
{
    char data[howmany] = {};

    if (::read(m_fd, data, howmany) < 0)
        throw std::ios_base::failure("Failed to read");

    return std::string(data);
}
