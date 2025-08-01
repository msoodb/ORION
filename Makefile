CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c99
SRC = src/orion.c test_orion.c
OBJ = $(SRC:.c=.o)
TARGET = test_orion

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

# Simple test entry point
src/orion.o: src/orion.c include/orion.h

.PHONY: all test clean
