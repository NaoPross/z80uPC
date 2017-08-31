#ifndef __TYPES_H__
#define __TYPES_H__

/* only types from primitive types are defined in this file */ 

#define register_t  volatile unsigned char

#define uint 		unsigned int

#define int8_t      char
#define uint8_t     unsigned char
#define int16_t     int
#define uint16_t    unsigned short int

#define uint32_t    unsigned long int

#define size_t      uint16_t
#define ssize_t     int16_t
#define pid_t 		uint8_t

#define ino_t       uint16_t

#define dev_t       uint8_t
#define devsize_t   uint32_t

#define fd_t        uint8_t

#define blk_t       uint16_t

#define user_t      int8_t

typedef struct
{
    uint8_t member[3];

} uint24_t;

#define fsize_t     uint32_t

typedef struct 
{
    dev_t   dev;    // device id, global in the fs
    ino_t   inode;    // inode id relative to the volume

} inode_t;

typedef struct time_s
{
    struct
    {
        uint    minutes :6;
        uint    hour    :5;

    } time;

    struct
    {
        uint    day     :5;
        uint    month   :4;
        uint    year    :12;

    } date;

} time_t;

#endif
