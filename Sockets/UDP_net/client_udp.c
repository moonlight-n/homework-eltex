#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER 1024

int main() {
    int client = 0;
    struct sockaddr_in serv_addr;
    char message[BUFFER] = "Hi, server";
    socklen_t address_length = sizeof(serv_addr);
    char buffer[BUFFER] = {0};
    if ((client = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Ошибка создания сокета");
        exit(1);
    }

   serv_addr.sin_family = AF_INET;
   serv_addr.sin_port = htons(7001);

   if ((inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)) == -1) {
        perror("Проблема с inet_pton");
        exit(1);
    }

    // Отправляем
    if (sendto(client, message, strlen(message), 0, (struct sockaddr*)&serv_addr, address_length) == -1) {
        perror("Ошибка sendto client");
        exit(1);
    }
    printf("Message \"%s\" sent\n", message);

    memset(buffer, 0, BUFFER);
    recvfrom(client, buffer, BUFFER, 0,(struct sockaddr *)&serv_addr, &address_length);
    printf("Message from server: %s\n", buffer);

    if(close(client) == -1) {
        perror("Ошибка close client");
        exit(1);
    }

    return 0;

}




    
