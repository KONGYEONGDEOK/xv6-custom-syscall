#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(argc != 3){
    fprintf(2, "usage: setprio pid priority\n");
    exit(1);
  }

  int pid = atoi(argv[1]);
  int priority = atoi(argv[2]);

  int r = set_prio(pid, priority);

  if(r < 0){
    fprintf(2, "set_prio failed: pid=%d priority=%d\n", pid, priority);
    exit(1);
  }

  printf("set_prio success: pid=%d priority=%d\n", pid, priority);
  exit(0);
}