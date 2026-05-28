// kernel/proc_stat.h

#ifndef _PROC_STAT_H_
#define _PROC_STAT_H_

#define PROC_NAME_LEN 16

#define PSTATE_UNUSED   0
#define PSTATE_USED     1
#define PSTATE_SLEEPING 2
#define PSTATE_RUNNABLE 3
#define PSTATE_RUNNING  4
#define PSTATE_ZOMBIE   5

struct proc_stat {
  int pid;
  int state;
  int priority;
  uint64 sz;
  char name[PROC_NAME_LEN];
};

#endif
