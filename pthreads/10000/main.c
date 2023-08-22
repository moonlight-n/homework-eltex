#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *increment(void *args);

long a = 0;

int main(void) {
  int i, array[1000], *s;
  pthread_t thread[1000];

  for (i = 0; i < 1000; i++) {
    array[i] = i;
    pthread_create(&thread[i], NULL, increment, (void *)&array[i]);
  }

  for (i = 0; i < 1000; i++) {
    pthread_join(thread[i], (void **)&s);
  }
  printf("%ld\n", a);
  return 0;
}

void *increment(void *args) {
  a += 100000;
  printf("%ld\n", a);
  return NULL;
}