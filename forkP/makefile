CC = gcc

all: fork1

clean:
	rm -f main *.o

fork1: main.o fork1.o
	$(CC) main.o fork1.o -o fork1
main.o: main.c fork1.h
	$(CC) -c main.c
fork1.o: fork1.c fork1.h
	$(CC) -c fork1.c