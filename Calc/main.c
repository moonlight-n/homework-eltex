#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main(void) {
    int c = 0;
    double a,b;
    printf("Введите 2 числа\n");
    scanf("%lf %lf", &a, &b);
    printf("a = %lf, b = %lf\n", a, b);

    while(c != 5) {
        printf("\nВыберите пункт меню\n");
        printf("1. Сложение\n");
        printf("2. Вычитание\n");
        printf("3. Умножение\n");
        printf("4. Деление\n");
        printf("5. Выход\n");
        scanf("%d", &c);
        switch(c) { 
            case 1:
                printf("%lf+%lf=%lf\n", a, b,add(a, b));
                break;
            case 2:
                printf("%lf-%lf=%d\n", a, b,sub(a, b));
                break;
            case 3:
                printf("%lf*%lf=%d\n", a, b,mul(a, b));
                break;
            case 4:
                printf("%lf/%lf=%.2lf\n", a, b,del(a, b));
                break;
            case 5:
                break;
            default:
                printf("Ожидается 1-5, повторите попытку\n"); 
                break;
            }
    }
  return 0;
}