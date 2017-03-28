CC=gcc
PARAMS=-std=c99 -Wall

#all: solution


list.o: list.c list.h
	$(CC) $(PARAMS) -c -o list list.c

tree.o: tree.c tree.h list.h
	$(CC) $(PARAMS) -c -o tree tree.c

#solution.o: solution.c
#	$(CC) $(PARAMS) -c -o solution solution.c

#solution: list.o tree.o solution.o
#	$(CC) $(PARAMS) -o solution solution.o tree.o list.o

#clean:
#	rm -f *.o solution solution.dbg

#debug: list.o tree.o solution.o
#	$(CC) $(PARAMS) -g -o solution.dbg solution.o tree.o list.o
