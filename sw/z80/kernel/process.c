#include "process.h"

struct process proc_table[255];

pid_t newpid(void)
{
    static pid_t last_pid = 0;
    return ++last_pid;
}

int fork(void)
{
    
}

int exec(char *path, char *args)
{
    
}

int spawn(char *path, char *args)
{
    
}
