#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int pid = fork();

  if(pid < 0){
    printf("fork failed\n");
    exit(1);
  }

  if(pid == 0){
    uint64 x;

    printf("child: trying to read sstatus in user mode...\n");

    asm volatile("csrr %0, sstatus" : "=r" (x));

    printf("[FAIL] child: read sstatus = %p\n", (void *)x);
    exit(0);
  }

  int status;
  wait(&status);

  if(status != 0)
    printf("[PASS] privileged CSR access was blocked. child status=%d\n", status);
  else
    printf("[FAIL] child accessed privileged CSR without trap\n");

  exit(0);
}