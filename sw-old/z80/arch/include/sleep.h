#ifndef __SLEEP_H__
#define __SLEEP_H__

#ifndef F_CPU
#error undefined CPU clock speed
#endif

#define SLEEP_UNIT ((F_CPU/4)/2)

#include <stdint.h>

void usleep(uint16_t microseconds);

#endif // __SLEEP_H__