#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
  pid_t pid = fork();
  if (pid == 0) {
    printf("Child pid = %d\n", getpid());
    printf("Parent pid = %d\n", getppid());
    exit(EXIT_SUCCESS);
  } else {
    printf ("Parent pid = %d\n", getpid());
    printf("Child pid = %d\n", getppid());
  }
  int status;
  pid_t child_pid = wait(&status);
  if (child_pid == -1) {
    exit(EXIT_FAILURE);
  }
  if (WIFEXITED(status)) {
    printf("Child exit-code = %d\n", WEXITSTATUS(status));
  }
  return EXIT_SUCCESS;
}