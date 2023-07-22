#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX_NAME 30
#define MAX_ENTRY 5

struct book {
  char name[MAX_NAME];
  char name2[MAX_NAME];
  char number[20];
};

void search(struct book *phone_book, int *count);
void enter(struct book *phone_book, int *count);
void delete(struct book *phone_book, int *count);
void list(struct book *phone_book, int count);

int main(void) {
  struct book *phone_book = (struct book*)malloc(MAX_ENTRY * sizeof(struct book));
  int count = 0,c = 0;
  while(c != 5) {
    printf("\nВыберите пункт меню\n");
    printf("1. Добавить контакт\n");
    printf("2. Удалить контакт\n");
    printf("3. Вывести весь список\n");
    printf("4. Поиск\n");
    printf("5. Выход\n");
    scanf("%d", &c);
    switch(c) {
      case 1: enter(phone_book, &count);
        continue;
      case 2: delete(phone_book, &count);
        continue;
      case 3: list(phone_book, count);
        continue;
      case 4: search(phone_book,&count);
        continue;
      case 5:
        break;
      default:
        printf("Ожидается 1-5, повторите попытку\n"); 
        break;
    }
  }
  free(phone_book);
  return 0;
}


void enter(struct book *phone_book, int *count) {
  if (*count >= MAX_ENTRY) {
        printf("Нет места для новых контактов\n");
    } else { 
      printf("Введите имя\n");
      scanf("%s", phone_book[*count].name);
      printf("Введите фамилию\n");
      scanf("%s", phone_book[*count].name2);
      printf("Введите номер телефона\n");
      scanf("%s", phone_book[*count].number);
      printf("Контакт добавлен\n");
      *count = *count + 1;
    }
}

void list(struct book *phone_book, int count) {
   if (count == 0) {
        printf("\nВ телефонной книге нет контактов\n");
    } else {
      for (int i = 0; i < count; i++) {
        printf("%d. %s %s %s\n", i + 1, phone_book[i].name, phone_book[i].name2, phone_book[i].number);
      }
    }
}

void delete(struct book *phone_book, int *count) {
  if (*count  == 0){
        printf("Нет сохренных контактов\n");
    } else {
      list(phone_book, *count);
      printf("Выберите номер контакта, который нужно удалить\n");
      int c;
      scanf("%d", &c);
      for (c; c < *count - 1; c++) {
            phone_book[c] = phone_book[c + 1];
        }
        printf("Контакт удален\n");
        *count = *count - 1;
      }
}

void search(struct book *phone_book, int *count) {
  if (*count  == 0){
        printf("Нет сохренных контактов\n");
    } else {
      char search[MAX_NAME];
      printf("Введите текст для поиска\n");
      scanf("%s", search);
      for (int i = 0; i < MAX_NAME; i++) {
        if (strcmp(phone_book[i].name, search) == 0 || strcmp(phone_book[i].name2, search)==0) {
          printf("%d %s %s %s\n", i+1, phone_book[i].name, phone_book[i].name2, phone_book[i].number);
        }
      }
    }
}