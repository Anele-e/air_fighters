CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
LIBS = -lSDL2

SRC = $(wildcard src/*.c)
OUT = build/game

all:
	mkdir -p build
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LIBS)

run: all
	./$(OUT)

clean:
	rm -rf build