//
// Created by ahmad on 11/16/17.
//

#include <iostream>
#include <unistd.h>
#include "single_thread.h"
#include "multi_process.h"
#include "eratosthenes.h"
#include "multi_thread.h"
#include <sys/resource.h>
#include <cstring>
#include <climits>


typedef struct statstruct_proc {
    int           pid;                      /** The process id. **/
    char          exName [_POSIX_PATH_MAX]; /** The filename of the executable **/
    char          state; /** 1 **/          /** R is running, S is sleeping,
			   D is sleeping in an uninterruptible wait,
			   Z is zombie, T is traced or stopped **/
    unsigned      euid,                      /** effective user id **/
            egid;                      /** effective group id */
    int           ppid;                     /** The pid of the parent. **/
    int           pgrp;                     /** The pgrp of the process. **/
    int           session;                  /** The session id of the process. **/
    int           tty;                      /** The tty the process uses **/
    int           tpgid;                    /** (too long) **/
    unsigned int	flags;                    /** The flags of the process. **/
    unsigned int	minflt;                   /** The number of minor faults **/
    unsigned int	cminflt;                  /** The number of minor faults with childs **/
    unsigned int	majflt;                   /** The number of major faults **/
    unsigned int  cmajflt;                  /** The number of major faults with childs **/
    int           utime;                    /** user mode jiffies **/
    int           stime;                    /** kernel mode jiffies **/
    int		cutime;                   /** user mode jiffies with childs **/
    int           cstime;                   /** kernel mode jiffies with childs **/
    int           counter;                  /** process's next timeslice **/
    int           priority;                 /** the standard nice value, plus fifteen **/
    unsigned int  timeout;                  /** The time in jiffies of the next timeout **/
    unsigned int  itrealvalue;              /** The time before the next SIGALRM is sent to the process **/
    int           starttime; /** 20 **/     /** Time the process started after system boot **/
    unsigned int  vsize;                    /** Virtual memory size **/
    unsigned int  rss;                      /** Resident Set Size **/
    unsigned int  rlim;                     /** Current limit in bytes on the rss **/
    unsigned int  startcode;                /** The address above which program text can run **/
    unsigned int	endcode;                  /** The address below which program text can run **/
    unsigned int  startstack;               /** The address of the start of the stack **/
    unsigned int  kstkesp;                  /** The current value of ESP **/
    unsigned int  kstkeip;                 /** The current value of EIP **/
    int		signal;                   /** The bitmap of pending signals **/
    int           blocked; /** 30 **/       /** The bitmap of blocked signals **/
    int           sigignore;                /** The bitmap of ignored signals **/
    int           sigcatch;                 /** The bitmap of catched signals **/
    unsigned int  wchan;  /** 33 **/        /** (too long) **/
    int		sched, 		  /** scheduler **/
            sched_priority;		  /** scheduler priority **/

} procinfo;

int get_proc_info(pid_t pid, procinfo * pinfo)
{
    char szFileName [_POSIX_PATH_MAX],
            szStatStr [2048],
            *s, *t;
    FILE *fp;
    struct stat st;

    if (NULL == pinfo) {
        errno = EINVAL;
        return -1;
    }

    sprintf (szFileName, "/proc/%u/stat", (unsigned) pid);

    if (-1 == access (szFileName, R_OK)) {
        return (pinfo->pid = -1);
    } /** if **/

    if (-1 != stat (szFileName, &st)) {
        pinfo->euid = st.st_uid;
        pinfo->egid = st.st_gid;
    } else {
        pinfo->euid = pinfo->egid = -1;
    }


    if ((fp = fopen (szFileName, "r")) == NULL) {
        return (pinfo->pid = -1);
    } /** IF_NULL **/

    if ((s = fgets (szStatStr, 2048, fp)) == NULL) {
        fclose (fp);
        return (pinfo->pid = -1);
    }

    /** pid **/
    sscanf (szStatStr, "%u", &(pinfo->pid));
    s = strchr (szStatStr, '(') + 1;
    t = strchr (szStatStr, ')');
    strncpy (pinfo->exName, s, t - s);
    pinfo->exName [t - s] = '\0';

    sscanf (t + 2, "%c %d %d %d %d %d %u %u %u %u %u %d %d %d %d %d %d %u %u %d %u %u %u %u %u %u %u %u %d %d %d %d %u",
            /*       1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33*/
            &(pinfo->state),
            &(pinfo->ppid),
            &(pinfo->pgrp),
            &(pinfo->session),
            &(pinfo->tty),
            &(pinfo->tpgid),
            &(pinfo->flags),
            &(pinfo->minflt),
            &(pinfo->cminflt),
            &(pinfo->majflt),
            &(pinfo->cmajflt),
            &(pinfo->utime),
            &(pinfo->stime),
            &(pinfo->cutime),
            &(pinfo->cstime),
            &(pinfo->counter),
            &(pinfo->priority),
            &(pinfo->timeout),
            &(pinfo->itrealvalue),
            &(pinfo->starttime),
            &(pinfo->vsize),
            &(pinfo->rss),
            &(pinfo->rlim),
            &(pinfo->startcode),
            &(pinfo->endcode),
            &(pinfo->startstack),
            &(pinfo->kstkesp),
            &(pinfo->kstkeip),
            &(pinfo->signal),
            &(pinfo->blocked),
            &(pinfo->sigignore),
            &(pinfo->sigcatch),
            &(pinfo->wchan));
    fclose (fp);
    return 0;
}
int main() {
    long long size;
    struct rusage usage, usage2;
    struct timeval start, end;

    std::cout << "Hello, World!" << std::endl;

    std::cin >> size;

    getrusage(RUSAGE_SELF, &usage);
    start = usage.ru_utime;
    start_single_thread(size);
    getrusage(RUSAGE_SELF, &usage);
    end = usage.ru_utime;
    printf("Started at: %ld.%lds\n", start.tv_sec, start.tv_usec);
    printf("Ended at: %ld.%lds\n", end.tv_sec, end.tv_usec);
    getrusage(RUSAGE_SELF, &usage2);
    printf("My process ID : %d\n", getpid());
    print_status(getpid());
//    printf("integral shared memory size: %ld\n", usage2.ru_ixrss);
//    printf("integral unshared memory size: %ld\n", usage2.ru_idrss);
//    printf("integral unshared stack size: %ld\n", usage2.ru_isrss);
//    start_multi_thread(start);
//    start_multi_process(start);
//    print();
    return 0;
}