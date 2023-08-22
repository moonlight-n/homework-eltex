#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER 1024

int main() {
    int server = 0;
    struct sockaddr_in server_addr, client_addr;
    socklen_t address_length = sizeof(client_addr);
    char buffer[BUFFER];
    char message[BUFFER] = "Hello, client!";

    // Создание сокета и проверка на создание
    if ((server  = socket(AF_INET, SOCK_DGRAM,0)) == -1) {
        perror("Проблема с созданием сокета");
        exit(1);
    }

    // Настройка адреса сервера
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7001);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Привязка сокета к адресу сервера
    if (bind(server, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Проблема с bind");
        exit(1);
    }

    // Ждем сообщения 
    memset(buffer, 0, sizeof(buffer));
    if (recvfrom(server, buffer, BUFFER, 0, (struct sockaddr*)&client_addr,&address_length) == -1) {
        perror("Проблема с recvfrom");
        exit(1);
    }
    printf("Message from client: %s\n", buffer);

    // Отправляем
    if (sendto(server, message, strlen(message), 0, (struct sockaddr*)&client_addr, address_length) == -1) {
        perror("Ошибка sendto server");
        exit(1);
    }
    printf("Message \"%s\" sent\n", message);

    if(close(server) == -1) {
        perror("Ошибка close server");
        exit(1);
    }

    return 0;
}
