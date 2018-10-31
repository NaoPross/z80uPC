#pragma once

#include <string>

extern "C" {
#include <termios.h>
}

class serial
{
public:
    serial(const std::string& port, speed_t baud);
    ~serial();

    int write(const std::string& data) const;
    int write(const char * const data, size_t len) const;

    char read() const;
    std::string read(size_t howmany) const;

private:
    int m_fd;
    struct termios m_settings;
};
