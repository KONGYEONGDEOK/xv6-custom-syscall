#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(argc != 2){
    fprintf(2, "usage: scount pid\n");
    exit(1);
  }

  int pid = atoi(argv[1]);
  int count = getsyscalls(pid);

  if(count < 0){
    fprintf(2, "getsyscalls failed: pid=%d\n", pid);
    exit(1);
  }

  printf("pid %d syscall count: %d\n", pid, count);
  exit(0);
}