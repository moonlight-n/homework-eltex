#include <pthread.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAG 5
#define POK 3

void buy(void* arg);
void delivery();

typedef struct {
  int num;
  int potreb;
} buyer_t;

pthread_t buyer_thread[POK];
pthread_t deliver_thread;
pthread_mutex_t MUTEX[MAG];

int items[MAG];

buyer_t buyer[POK];

int main() {
  int status;
  int i = 0;
  srand(time(NULL));

  for (i = 0; i < POK; i++) {  // Заполнение структуры для всех покупателей
    buyer[i].num = i;
    buyer[i].potreb = 10000;
  }

  for (i = 0; i < MAG; i++) {
    pthread_mutex_init(&MUTEX[i], NULL);
    items[i] = 1000;
    printf("Магазин %d открылся, в нем %d товаров\n", i, items[i]);
  }

  status = pthread_create(&deliver_thread, NULL, delivery, NULL);
  if (status != 0) {
    perror("Проблема с созданием потока погрузчика");
    exit(1);
  }

  for (i = 0; i < POK; i++) {
    status = pthread_create(&buyer_thread[i], NULL, buy, &buyer[i]);
    if (status != 0) {
      perror("Проблема с созданием потока покупателя");
      exit(1);
    }
  }

  for (i = 0; i < POK; i++) {
    pthread_join(buyer_thread[i], NULL);
  }

  pthread_cancel(deliver_thread);

  for (i = 0; i < MAG; i++) {
    pthread_mutex_destroy(&MUTEX[i]);
  }

  return 0;
}

void buy(void* arg) {
  int tmp = *(int*)arg;
  while (buyer[tmp].potreb > 0) {
    int shop = rand() % MAG;
    pthread_mutex_lock(&MUTEX[shop]);
    if (items[shop] >= 200) {
      items[shop] -= 200;
      buyer[tmp].potreb -= 200;
      printf("В магазине %d осталось %d товара\n", shop, items[shop]);
      printf("Покупатель %d купил, оставшаяся потребность %d\n", tmp,
             buyer[tmp].potreb);
    } else {
      printf("В магазине сейчас нет товара, приходите позже\n");
    }
    pthread_mutex_unlock(&MUTEX[shop]);
    sleep(1);
  }
  return 0;
}

void delivery() {
  int i = 0;
  while (1) {
    for (i = 0; i < MAG; i++) {
      pthread_mutex_lock(&MUTEX[i]);
      if (items[i] <= 500) {
        items[i] += 500;
        printf("В магазин %d пришла поставка, товаров в магазине стало %d\n", i,
               items[i]);
      }
      pthread_mutex_unlock(&MUTEX[i]);
    }
    sleep(2);
  }
}
