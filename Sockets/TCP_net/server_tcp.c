#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER 1024

int main() {
    int server = 0, client = 0;
    struct sockaddr_in server_addr, client_addr;
    socklen_t address_length;
    char buffer[BUFFER];

    // Создание сокета и проверка на создание
    if ((server  = socket(AF_INET, SOCK_STREAM,0)) == -1) {
        perror("Проблема с созданием сокета");
        exit(1);
    }

    // Настройка адреса сервера
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7001);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Привязка сокета к адресу сервера
    if (bind(server, (struct sockaddr *)& server_addr, sizeof(server_addr)) == -1) {
        perror("Проблема с bind");
        exit(1);
    }

    // Ожидание подключения клиентов
    if (listen(server,1) == -1) {
        perror("Проблема с listen");
        exit(1);
    }

    printf("Сервер готов! Параметры: IP-адрес - %s, Порт - %d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));

    // Клиент подключается
    if ((client = accept(server,(struct sockaddr *)&client_addr, &address_length)) == -1) {
        perror("Accept ошибка");
        exit(1);
    }

    printf("Подключился клиент [%s]!\n", inet_ntoa(client_addr.sin_addr));

    // Получаем сообщение
    if (recv(client, buffer, BUFFER, 0) == -1) {
        perror("Ошибка recv");
        exit(1);
    }

    printf("Message from client : %s\n", buffer);

    // Отправляем
    if (send(client, "Hello, client!", BUFFER, 0) == -1) {
        perror("Ошибка send");
        exit(1);
    }

    // Закрываем сокеты
    if(close(client) == -1) {
        perror("Ошибка close client");
        exit(1);
    }

    if(close(server) == -1) {
        perror("Ошибка close server");
        exit(1);
    }

    return 0;
}