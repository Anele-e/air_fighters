CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LIBS = -lSDL2

SRC = src/main.c
OUT = build/game

all:
	mkdir -p build
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LIBS)

run: all
	./$(OUT)

clean:
	rm -rf build