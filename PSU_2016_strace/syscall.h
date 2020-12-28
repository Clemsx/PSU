/*
** syscall.h for syscall in /home/lblouard/delivery/Annee2/PSU/PSU_2016_strace/system
** 
** Made by Leo Blouard
** Login   <lblouard@epitech.net>
** 
** Started on  Thu Apr 13 20:59:55 2017 Leo Blouard
** Last update Sun Apr 16 10:24:17 2017 clement xia
*/

#ifndef SYSCALL_H_
# define SYSCALL_H_

# include "strace.h"

t_sys sysc_gl[] =
  {
    { 0, "read", 3, 1},
    { 1, "write", 3, 1},
    { 2, "open", 2, 1},
    { 3, "close", 1, 1},
    { 4, "stat", 2, 1},
    { 5, "fstat", 2, 1},
    { 6, "lstat", 2, 1},
    { 7, "poll", 3, 1},
    { 8, "lseek", 3, 1},
    { 9, "mmap", 6, 1},
    { 10, "mprotect", 3, 1},
    { 11, "munmap", 2, 1},
    { 12, "brk", 1, 1},
    { 13, "sigaction", 3, 1},
    { 14, "sigprocmask", 3, 1},
    { 15, "sigreturn", 1, 1},
    { 16, "ioctl", 3, 1},
    { 21, "access", 2, 1},
    { 22, "pipe", 1, 1},
    { 24, "sched_yield", 0, 1},
    { 25, "mremap", 5, 1},
    { 26, "msync", 3, 1},
    { 27, "mincore", 3, 1},
    { 28, "madvise", 3, 1},
    { 29, "shmget", 3, 1},
    { 30, "shmat", 3, 1},
    { 31, "shmctl", 3, 1},
    { 32, "dup", 1, 1},
    { 33, "dup2", 2, 1},
    { 34, "pause", 0, 1},
    { 35, "nanosleep", 2, 1},
    { 36, "getitimer", 2, 1},
    { 37, "alarm", 1, 1},
    { 38, "setitimer", 3, 1},
    { 39, "getpid", 0, 1},
    { 40, "sendfile", 4, 1},
    { 41, "socket", 3, 1},
    { 42, "connect", 3, 1},
    { 43, "accept", 3, 1},
    { 44, "sendto", 6, 1},
    { 45, "recvfrom", 6, 1},
    { 46, "sendmsg", 3, 1},
    { 47, "recvmsg", 3, 1},
    { 48, "shutdown", 2, 1},
    { 49, "bind", 3, 1},
    { 50, "listen", 2, 1},
    { 51, "getsockname", 3, 1},
    { 52, "getpeername", 3, 1},
    { 53, "socketpair", 4, 1},
    { 54, "setsockopt", 5, 1},
    { 55, "getsockopt", 5, 1},
    { 56, "clone", 7, 1},
    { 57, "fork", 0, 1},
    { 58, "vfork", 0, 1},
    { 59, "execve", 3, 1},
    { 61, "wait4", 4, 1},
    { 62, "kill", 2, 1},
    { 63, "uname", 1, 1},
    { 64, "semget", 3, 1},
    { 65, "semop", 3, 1},
    { 66, "semctl", 4, 1},
    { 67, "shmdt", 1, 1},
    { 68, "msgget", 2, 1},
    { 69, "msgsnd", 4, 1},
    { 70, "msgrcv", 5, 1},
    { 71, "msgctl", 3, 1},
    { 72, "fcntl", 3, 1},
    { 73, "flock", 2, 1},
    { 74, "fsync", 1, 1},
    { 75, "fdatasync", 1, 1},
    { 78, "getdents", 3, 1},
    { 80, "chdir", 1, 1},
    { 81, "fchdir", 1, 1},
    { 82, "rename", 2, 1},
    { 83, "mkdir", 2, 1},
    { 84, "rmdir", 1, 1},
    { 85, "creat", 2, 1},
    { 86, "link", 2, 1},
    { 87, "unlink", 1, 1},
    { 88, "symlink", 2, 1},
    { 89, "readlink", 3, 1},
    { 90, "chmod", 2, 1},
    { 91, "fchmod", 2, 1},
    { 92, "chown", 3, 1},
    { 93, "fchown", 3, 1},
    { 94, "lchown", 3, 1},
    { 95, "umask", 1, 1},
    { 96, "gettimeofday", 2, 1},
    { 97, "getrlimit", 2, 1},
    { 98, "getrusage", 2, 1},
    { 99, "sysinfo", 1, 1},
    { 100, "times", 1, 1},
    { 102, "getuid", 0, 1},
    { 103, "syslog", 3, 1},
    { 104, "getgid", 0, 1},
    { 105, "setuid", 1, 1},
    { 106, "setgid", 1, 1},
    { 107, "geteuid", 0, 1},
    { 108, "getegid", 0, 1},
    { 109, "setpgid", 2, 1},
    { 110, "getppid", 0, 1},
    { 111, "getpgrp", 0, 1},
    { 112, "setsid", 0, 1},
    { 113, "setreuid", 2, 1},
    { 114, "setregid", 2, 1},
    { 115, "getgroups", 2, 1},
    { 116, "setgroups", 2, 1},
    { 117, "setresuid", 3, 1},
    { 118, "getresuid", 3, 1},
    { 119, "setresgid", 3, 1},
    { 120, "getresgid", 3, 1},
    { 121, "getpgid", 1, 1},
    { 122, "setfsuid", 1, 1},
    { 123, "setfsgid", 1, 1},
    { 124, "getsid", 1, 1},
    { 125, "capget", 2, 1},
    { 126, "capset", 2, 1},
    { 127, "sigpending", 1, 1},
    { 128, "sigtimedwait", 3, 1},
    { 130, "sigsuspend", 1, 1},
    { 131, "sigaltstack", 2, 1},
    { 132, "utime", 2, 1},
    { 133, "mknod", 3, 1},
    { 134, "uselib", 1, 1},
    { 135, "personality", 1, 1},
    { 136, "ustat", 2, 1},
    { 137, "statfs", 2, 1},
    { 138, "fstatfs", 2, 1},
    { 139, "sysfs", 2, 1},
    { 140, "getpriority", 2, 1},
    { 141, "setpriority", 3, 1},
    { 142, "sched_setparam", 2, 1},
    { 143, "sched_getparam", 2, 1},
    { 144, "sched_setscheduler", 3, 1},
    { 145, "sched_getscheduler", 1, 1},
    { 146, "sched_get_priority_max", 1, 1},
    { 147, "sched_get_priority_min", 1, 1},
    { 148, "sched_rr_get_interval", 2, 1},
    { 149, "mlock", 2, 1},
    { 150, "munlock", 2, 1},
    { 151, "mlockall", 1, 1},
    { 153, "vhangup", 0, 1},
    { 154, "modify_ldt", 3, 1},
    { 155, "pivot_root", 2, 1},
    { 156, "_sysctl", 1, 1},
    { 157, "prctl", 5, 1},
    { 158, "arch_prctl", 2, 1},
    { 159, "adjtimex", 1, 1},
    { 160, "setrlimit", 2, 1},
    { 161, "chroot", 1, 1},
    { 162, "sync", 0, 0},
    { 163, "acct", 1, 1},
    { 164, "settimeofday", 2, 1},
    { 166, "umount2", 2, 1},
    { 167, "swapon", 2, 1},
    { 168, "swapoff", 1, 1},
    { 169, "reboot", 4, 1},
    { 170, "sethostname", 2, 1},
    { 171, "setdomainname", 2, 1},
    { 172, "iopl", 1, 1},
    { 173, "ioperm", 3, 1},
    { 174, "create_module", 2, 1},
    { 175, "init_module", 3, 1},
    { 176, "delete_module", 2, 1},
    { 177, "get_kernel_syms", 1, 1},
    { 178, "query_module", 5, 1},
    { 179, "quotactl", 4, 1},
    { 180, "nfsservctl", 3, 1},
    { 186, "gettid", 0, 1},
    { 187, "readahead", 3, 1},
    { 188, "setxattr", 5, 1},
    { 189, "lsetxattr", 5, 1},
    { 190, "fsetxattr", 5, 1},
    { 191, "getxattr", 4, 1},
    { 192, "lgetxattr", 4, 1},
    { 193, "fgetxattr", 4, 1},
    { 194, "listxattr", 3, 1},
    { 195, "llistxattr", 3, 1},
    { 196, "flistxattr", 3, 1},
    { 197, "removexattr", 2, 1},
    { 198, "lremovexattr", 2, 1},
    { 199, "fremovexattr", 2, 1},
    { 200, "tkill", 2, 1},
    { 201, "time", 1, 1},
    { 202, "futex", 6, 1},
    { 203, "sched_setaffinity", 3, 1},
    { 204, "sched_getaffinity", 3, 1},
    { 205, "set_thread_area", 1, 1},
    { 206, "io_setup", 2, 1},
    { 207, "io_destroy", 1, 1},
    { 208, "io_getevents", 5, 1},
    { 209, "io_submit", 3, 1},
    { 210, "io_cancel", 3, 1},
    { 211, "get_thread_area", 1, 1},
    { 212, "lookup_dcookie", 3, 1},
    { 213, "epoll_create", 1, 1},
    { 216, "remap_file_pages", 5, 1},
    { 217, "getdents64", 3, 1},
    { 218, "set_tid_address", 1, 1},
    { 219, "restart_syscall", 0, 1},
    { 220, "semtimedop", 4, 1},
    { 222, "timer_create", 3, 1},
    { 223, "timer_settime", 4, 1},
    { 224, "timer_gettime", 2, 1},
    { 225, "timer_getoverrun", 1, 1},
    { 226, "timer_delete", 1, 1},
    { 227, "clock_settime", 2, 1},
    { 228, "clock_gettime", 2, 1},
    { 229, "clock_getres", 2, 1},
    { 230, "clock_nanosleep", 4, 1},
    { 231, "exit_group", 1, 0},
    { 232, "epoll_wait", 4, 1},
    { 233, "epoll_ctl", 4, 1},
    { 234, "tgkill", 3, 1},
    { 235, "utimes", 2, 1},
    { 237, "mbind", 6, 1},
    { 238, "set_mempolicy", 3, 1},
    { 239, "get_mempolicy", 5, 1},
    { 240, "mq_open", 2, 1},
    { 241, "mq_unlink", 1, 1},
    { 242, "mq_timedsend", 5, 1},
    { 243, "mq_timedreceive", 5, 1},
    { 244, "mq_notify", 2, 1},
    { 245, "mq_getsetattr", 3, 1},
    { 246, "kexec_load", 4, 1},
    { 247, "waitid", 4, 1},
    { 248, "add_key", 5, 1},
    { 249, "request_key", 4, 1},
    { 250, "keyctl", 2, 1},
    { 251, "ioprio_set", 3, 1},
    { 252, "ioprio_get", 2, 1},
    { 253, "inotify_init", 0, 1},
    { 254, "inotify_add_watch", 3, 1},
    { 255, "inotify_rm_watch", 2, 1},
    { 256, "migrate_pages", 4, 1},
    { 257, "openat", 3, 1},
    { 258, "mkdirat", 3, 1},
    { 259, "mknodat", 4, 1},
    { 260, "fchownat", 5, 1},
    { 261, "futimesat", 3, 1},
    { 263, "unlinkat", 3, 1},
    { 264, "renameat", 4, 1},
    { 265, "linkat", 5, 1},
    { 266, "symlinkat", 3, 1},
    { 267, "readlinkat", 4, 1},
    { 268, "fchmodat", 4, 1},
    { 269, "faccessat", 4, 1},
    { 271, "ppoll", 4, 1},
    { 272, "unshare", 1, 1},
    { 273, "set_robust_list", 2, 1},
    { 274, "get_robust_list", 3, 1},
    { 275, "splice", 6, 1},
    { 276, "tee", 4, 1},
    { 278, "vmsplice", 4, 1},
    { 279, "move_pages", 6, 1},
    { 280, "utimensat", 4, 1},
    { 281, "epoll_pwait", 5, 1},
    { 282, "signalfd", 3, 1},
    { 283, "timerfd_create", 2, 1},
    { 284, "eventfd", 2, 1},
    { 285, "fallocate", 4, 1},
    { 286, "timerfd_settime", 4, 1},
    { 287, "timerfd_gettime", 2, 1},
    { 288, "accept4", 4, 1},
    { 291, "epoll_create1", 1, 1},
    { 292, "dup3", 3, 1},
    { 293, "pipe2", 2, 1},
    { 294, "inotify_init1", 1, 1},
    { 298, "perf_event_open", 5, 1},
    { 299, "recvmmsg", 5, 1},
    { 300, "fanotify_init", 2, 1},
    { 301, "fanotify_mark", 5, 1},
    { 303, "name_to_handle_at", 5, 1},
    { 304, "open_by_handle_at", 3, 1},
    { 306, "syncfs", 1, 1},
    { 307, "sendmmsg", 4, 1},
    { 308, "setns", 2, 1},
    { 309, "getcpu", 3, 1},
    { 310, "process_vm_readv", 6, 1},
    { 311, "process_vm_writev", 6, 1},
    { 312, "kcmp", 5, 1},
    { 313, "finit_module", 3, 1},
    { 314, "sched_setattr", 3, 1},
    { 315, "sched_getattr", 4, 1},
    { 316, "renameat2", 5, 1},
    { 317, "seccomp", 3, 1},
    { 318, "getrandom", 3, 1},
    { 319, "memfd_create", 2, 1},
    { 320, "kexec_file_load", 5, 1},
    { 321, "bpf", 3, 1},
    { 322, "execveat", 5, 1},
    { 324, "membarrier", 2, 1},
    { 325, "mlock2", 3, 1},
    { 326, "copy_file_range", 6, 1},
    { 329, "pkey_mprotect", 4, 1},
    { 330, "pkey_alloc", 2, 1},
    { 331, "pkey_free", 1, 1},
    { -1, "tailx", -1, -1 }
};

#endif /* !SYSCALL_H_ */