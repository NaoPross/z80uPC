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
    int i, p;
    pid_t child_pid = newpid();

    if (child_pid == 0)
        return -1;


    for (i = 0; i < current_proc.pages; i++) {
        p = page_new();

        if (p == -1) {
            
            return -2;
        }

        proc_table[child_pid].page[i] = p;
    }
}

int exec(char *path, char *args)
{
    
}

int spawn(char *path, char *args)
{
    
}
