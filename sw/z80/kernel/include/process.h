#ifndef __PROCESS_H__
#define __PROCESS_H__

#include "types.h"
#include "memory.h"

 /* maximum number of processes (i.e. pages in ram)
  * since each program can use only one page in ram
  */
#define PROC_COUNT 2 

/* the pid is defined with a single byte (pid_t is uint8_t), because of that 
 * there cannot be more than 255 processes open at the same time. this is a
 * limitation but for our purposes is more than enough
 */
#define PID_COUNT_MAX 255

struct executable
{
    void *text;
    size_t text_size;
    void *bss;
    size_t bss_size;
};

struct process
{
    uint blocked :1;      // process is waiting for hardware or locked
    uint running :1;      // pid is used
    uint pages;           // number of pages used by the process
    struct page page[4];  // pages used by the process
};

pid_t newpid(void);

int fork(void);
int exec(char *path, char *args);
int spawn(char *path, char *args);

pid_t getpid(void);
int kill(pid_t pid);

#endif // __PROCESS_H__
