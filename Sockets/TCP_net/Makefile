all : client server
client : client_tcp.o
	gcc client_tcp.o -o client
client_tcp.0 : lr11_client.c
	gcc -c -g -Wall -std=c99 client_tcp.c

server : server_tcp.o
	gcc server_tcp.o -o server
server_tcp.0 : server_tcp.c
	gcc -c -g -Wall -std=c99 client_tcp.c

clean:
	rm -f client server client_tcp.o server_tcp.o
