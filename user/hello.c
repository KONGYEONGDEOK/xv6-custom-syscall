#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  printf("User: Calling hello() syscall...\n");

  int ret = hello();

  printf("User: hello() returned %d\n", ret);

  exit(0);
}
