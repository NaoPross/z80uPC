#include "process.h"

static struct process proc_table[PID_COUNT_MAX];
static struct process *current_proc;

pid_t newpid(void)
{
    int i;
    static pid_t last_pid = 0;

    for (i = 0; i < PID_COUNT_MAX; i++, last_pid++) {
        if (last_pid == PID_COUNT_MAX) {
            last_pid = 0;
            continue;            
        }

        if (!proc_table[last_pid].running)
            break;
    }

    if (i >= PID_COUNT_MAX)
        return 0;

    return last_pid;
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
