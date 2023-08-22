TARGET = main
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lpthread
SRC = main.c
OBJ = main.o

all: $(TARGET)

$(TARGET): $(OBJ)
		$(CC) $^ $(LDFLAGS) -o $@ 

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(TARGET) $(OBJ)
