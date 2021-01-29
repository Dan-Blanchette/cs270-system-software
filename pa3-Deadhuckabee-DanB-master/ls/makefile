CC = gcc


# Dependency rules for non-file targets
all: ls1
clobber: clean
	rm -f ~*\#*\#
clean:
	rm -f main *.o

# Dependency rules for file targets
ls1: main.o ls.o
	$(CC) main.o ls.o -o ls1
main.o: main.c ls.h
	$(CC) -c main.c
ls.o: ls.c ls.h
	$(CC) -c ls.c