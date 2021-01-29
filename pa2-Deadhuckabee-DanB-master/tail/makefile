# MACROS
CC = gcc
CFLAGS = 

# Dependency rules for non-target files
all: tail
clobber: clean
	rm -f *~ \#*\#
clean:
	rm -f main *.o

# Dependency rules for file targets
tail: main.o tail.o
	$(CC) $(CFLAGS) main.o tail.o -o tail
main.o: main.c tail.h
	$(CC) $(CFLAGS) -c main.c
tail.o: tail.c tail.h
	$(CC) $(CFLAGS) -c tail.c
