#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/param.h"
#include "kernel/proc_stat.h"
#include "user/user.h"

static void
test_addr(char *label, struct proc_stat *addr)
{
  int r = getprocs(addr, NPROC);

  if(r < 0)
    printf("[PASS] %s: getprocs returned -1\n", label);
  else
    printf("[FAIL] %s: getprocs returned %d\n", label, r);
}

int
main(int argc, char *argv[])
{
  test_addr("NULL pointer", (struct proc_stat *)0);
  test_addr("read-only text area", (struct proc_stat *)main);
  test_addr("too high address", (struct proc_stat *)0xffffffffffffffffL);

  exit(0);
}