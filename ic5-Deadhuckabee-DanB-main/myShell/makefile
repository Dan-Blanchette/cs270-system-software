CC = gcc


# non-dependency rules
all: shell
clobber: clean 
	rm -f ~#/*#/#
clean:
	rm -f main *.o

# dependency rules

shell: main.o shell.o
	$(CC) main.o shell.o -o shell
main.o: main.c shell.h
	$(CC) -c main.c
shell.o: shell.c shell.h
	$(CC) -c shell.c