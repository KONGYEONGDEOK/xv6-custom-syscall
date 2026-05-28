#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/param.h"
#include "kernel/proc_stat.h"
#include "user/user.h"

static char*
state_name(int state)
{
  switch(state){
  case PSTATE_UNUSED:
    return "UNUSED";
  case PSTATE_USED:
    return "USED";
  case PSTATE_SLEEPING:
    return "SLEEPING";
  case PSTATE_RUNNABLE:
    return "RUNNABLE";
  case PSTATE_RUNNING:
    return "RUNNING";
  case PSTATE_ZOMBIE:
    return "ZOMBIE";
  default:
    return "UNKNOWN";
  }
}

void
print_state(char *s)
{
  int len = strlen(s);

  printf("%s", s);

  for(int i = len; i < 12; i++){
    printf(" ");
  }
}

int
main(int argc, char *argv[])
{
  int max = NPROC;
  struct proc_stat *list;

  list = malloc(sizeof(struct proc_stat) * max);
  if(list == 0){
    fprintf(2, "pinfo: malloc failed\n");
    exit(1);
  }

  int n = getprocs(list, max);
  if(n < 0){
    fprintf(2, "pinfo: getprocs failed\n");
    free(list);
    exit(1);
  }

  printf("PID\tSTATE       PRIO\tSZ\tNAME\n");

  for(int i = 0; i < n; i++){
    printf("%d\t", list[i].pid);
    print_state(state_name(list[i].state));
    printf("%d\t%d\t%s\n",
         list[i].priority,
         (int)list[i].sz,
         list[i].name);
}

  free(list);
  exit(0);
}