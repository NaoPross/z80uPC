#ifndef __TYPES_H__
#define __TYPES_H__

/* only types from primitive types are defined in this file */ 

#define register_t  volatile unsigned char

#define uint 		unsigned int

#define int8_t      char
#define uint8_t     unsigned char
#define int16_t     int
#define uint16_t    unsigned long int

#define size_t      uint16_t
#define pid_t 		uint8_t

#define ino_t       uint16_t

typedef struct {
    uint    data : 24;
} uint24_t;

#endif
