CC = gcc
CFLAGS = -pthread
TARGET = shop
SOURCE = shop.c

all: $(TARGET)

$(TARGET): 
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET) 

run:
	./$(TARGET)

format:
	clang-format -style=Google -i $(SOURCE)

clean:
	rm -rf *.o $(TARGET) 