#ifndef __TYPES_H__
#define __TYPES_H__

/* only types from primitive types are defined in this file */ 

typedef volatile unsigned char      register_t;

typedef unsigned int                uint;

typedef char                        int8_t;
typedef unsigned char               uint8_t;
typedef int                         int16_t;
typedef unsigned int                uint16_t;
typedef long int                    int32_t;
typedef unsigned long int           uint32_t;

typedef uint16_t                    size_t;
typedef int16_t                     ssize_t;

typedef uint8_t                     pid_t;
typedef uint16_t                    ino_t;

typedef uint8_t                     dev_t;
typedef uint32_t                    devsize_t;
typedef uint8_t                     fd_t;
typedef uint16_t                    blk_t;
typedef uint8_t                     user_t;

typedef struct {
    uint8_t member[3];

} uint24_t;

typedef uint32_t                    fsize_t;

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
