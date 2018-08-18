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


    sprintf (szFileName, "/proc/%u/stat", (unsigned) pid);




    if ((fp = fopen (szFileName, "r")) == NULL) {
        return (pinfo->pid = -1);
    } /** IF_NULL **/


    fscanf (fp, "%c %d %d %d %d %d %u %u %u %u %u %d %d %d %d %d %d %u %u %d %u %u %u %u %u %u %u %u %d %d %d %d %u",
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

#include <fstream>

void process_mem_usage(double& vm_usage, double& resident_set)
{
    using std::ios_base;
    using std::ifstream;
    using std::string;

    vm_usage     = 0.0;
    resident_set = 0.0;

    // 'file' stat seems to give the most reliable results
    //
    ifstream stat_stream("/proc/self/stat",ios_base::in);

    // dummy vars for leading entries in stat that we don't care about
    //
    string pid, comm, state, ppid, pgrp, session, tty_nr;
    string tpgid, flags, minflt, cminflt, majflt, cmajflt;
    string utime, stime, cutime, cstime, priority, nice;
    string O, itrealvalue, starttime;

    // the two fields we want
    //
    unsigned long vsize;
    long rss;

    stat_stream >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr
                >> tpgid >> flags >> minflt >> cminflt >> majflt >> cmajflt
                >> utime >> stime >> cutime >> cstime >> priority >> nice
                >> O >> itrealvalue >> starttime >> vsize >> rss; // don't care about the rest

    stat_stream.close();

    long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // in case x86-64 is configured to use 2MB pages
    vm_usage     = vsize / 1024.0;
    resident_set = rss * page_size_kb;
}

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "sys/times.h"
#include "sys/vtimes.h"

static clock_t lastCPU, lastSysCPU, lastUserCPU;
static int numProcessors;

void init(){
    FILE* file;
    struct tms timeSample;
    char line[128];

    lastCPU = times(&timeSample);
    lastSysCPU = timeSample.tms_stime;
    lastUserCPU = timeSample.tms_utime;

    file = fopen("/proc/cpuinfo", "r");
    numProcessors = 0;
    while(fgets(line, 128, file) != NULL){
        if (strncmp(line, "processor", 9) == 0) numProcessors++;
    }
    fclose(file);
}

double getCurrentValue(){
    struct tms timeSample;
    clock_t now;
    double percent;

    now = times(&timeSample);
    if (now <= lastCPU || timeSample.tms_stime < lastSysCPU ||
        timeSample.tms_utime < lastUserCPU){
        //Overflow detection. Just skip this value.
        percent = -1.0;
    }
    else{
        percent = (timeSample.tms_stime - lastSysCPU) +
                  (timeSample.tms_utime - lastUserCPU);
        percent /= (now - lastCPU);
        percent /= numProcessors;
        percent *= 100;
    }
    lastCPU = now;
    lastSysCPU = timeSample.tms_stime;
    lastUserCPU = timeSample.tms_utime;

    return percent;
}

int main() {
    long long size;


    std::cin >> size;


    init();
    start_single_thread(size);
    double a = getCurrentValue();
    procinfo t;

    printf("My process ID : %d\n", getpid());
    get_proc_info(getpid(), &t);
    printf("Virtual Memory usage : %u\nRss : %u\nCPU Usage: %lf\n",t.vsize, t.rss, a);

//    printf("integral shared memory size: %ld\n", usage2.ru_ixrss);
//    printf("integral unshared memory size: %ld\n", usage2.ru_idrss);
//    printf("integral unshared stack size: %ld\n", usage2.ru_isrss);
//    start_multi_thread(start);
//    start_multi_process(start);
//    print();
    return 0;
}