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
    char buffer[BUFFER] = "Hi, server";
    if ((client = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Ошибка создания сокета");
        exit(1);
    }

   memset(&serv_addr, 0, sizeof(struct sockaddr_in));
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_port = htons(7001);

   if ((inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)) == -1) {
        perror("Проблема с inet_pton");
        exit(1);
    }

    if (connect(client, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr_in)) == -1) {
        perror("Нет коннекта");
        exit(1);
    }

    send(client, buffer, BUFFER, 0);

    memset(buffer, 0, BUFFER);
    recv(client, buffer, BUFFER, 0);
    printf("Message from server: %s\n", buffer);

    if((close(client)) == -1) {
        perror("Ошибка close client");
        exit(1);
    }

    return 0;

}




    