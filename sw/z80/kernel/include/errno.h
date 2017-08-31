#ifndef ERRNO_H
#define ERRNO_H

extern int errno;

#define EPERM       1       /* Operation not permitted */
#define ENOENT      2       /* No such file or directory */
#define ESRCH       3       /* No such process */
#define EINTR       4       /* Interrupted system call */
#define EIO         5       /* Input/output error */
#define ENXIO       6       /* Device not configured */
#define E2BIG       7       /* Argument list too long */
#define ENOEXEC     8       /* Exec format error */
#define EBADF       9       /* Bad file descriptor */
#define ECHILD      10      /* No child processes */
#define EDEADLK     11      /* Resource deadlock avoided */

#define ENOMEM      12      /* Cannot allocate memory */
#define EACCES      13      /* Permission denied */
#define EFAULT      14      /* Bad address */

#define ENOTBLK     15      /* Block device required */
#define EBUSY       16      /* Device busy */
#define EEXIST      17      /* File exists */

#define EXDEV       18      /* Cross-device link */
#define ENODEV      19      /* Operation not supported by device */
#define ENOTDIR     20      /* Not a directory */
#define EISDIR      21      /* Is a directory */
#define EINVAL      22      /* Invalid argument */
#define ENFILE      23      /* Too many open files in system */
#define EMFILE      24      /* Too many open files */
#define ENOTTY      25      /* Inappropriate ioctl for device */

#endif
