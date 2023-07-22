
all: build main.o main 

build:
	gcc add.c -c
	gcc sub.c -c 
	gcc div.c -c
	gcc mul.c -c
	ar rc libcalc.a add.o sub.o div.o mul.o

main.o:
	gcc -c main.c -o main.o

main:
	gcc -o calculator main.o -L. -lcalc

clear:
	-rm *.o
	-rm *.a
	-rm calculator