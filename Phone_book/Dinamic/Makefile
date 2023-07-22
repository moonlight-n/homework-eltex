all: build

build: main.o
	gcc main.c -o main

main.o : main.c
	gcc main.c -o main.o

clean: 
	rm -rf ./*.o
