# MACROS
CC = gcc
CFLAGS =

# non-target dependencies
all: move
clobber: clean 
	rm -f *~ \#*\#
clean:
	rm -f mv1 *.o

# dependency rules for file targets
move: mv1.o mv.o
	$(CC) $(CFLAGS) mv1.o mv.o -o move
mv1.o: mv1.c mv.h
	$(CC) $(CFLAGS) -c mv1.c
mv.o: mv.c mv.h
	$(CC) $(CFLAGS) -c mv.c