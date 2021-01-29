# Macros
CC = gcc
CFLAGS =

# Dependency rules for non-file targets
all: who3
clobber: clean
	rm -f *~ \#*\#
clean:
	rm -f who *.o

# Dependency rules for file targets

who3: who3.o utmplib.o
	$(CC) $(CFLAGS) who3.o utmplib.o -o who3
who3.o: who3.c utmplib.h
	$(CC) $(CFLAGS) -c who3.c
utmplib.o: utmplib.c utmplib.h
	$(CC) $(CFLAGS) -c utmplib.c