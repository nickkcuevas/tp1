CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror
FILE_OUTPUT = pruebas
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes 

build: *.c
	$(CC) $(CFLAGS) *.c -o pruebas

valgrind: build
	valgrind $(VFLAGS) ./pruebas

run: build valgrind
