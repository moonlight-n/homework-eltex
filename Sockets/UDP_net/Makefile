all : client server

client : client_udp.o
	gcc client_udp.o -o client

client_udp.0 : lr11_client.c
	gcc -c -g -Wall -std=c99 client_udp.c

server : server_udp.o
	gcc server_udp.o -o server
	
server_udp.0 : server_udp.c
	gcc -c -g -Wall -std=c99 client_udp.c

clean:
	rm -f client server client_udp.o server_udp.o
