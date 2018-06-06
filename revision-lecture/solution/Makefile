CC=gcc
CFLAGS=-Wall -Werror -g
BIN=testList

all: testList.o list.o
	$(CC) $(CFLAGS) -o $(BIN) testList.o list.o

testList.o: list.h testList.c
	$(CC) $(CFLAGS) -c testList.c

list.o: list.h list.c
	$(CC) $(CFLAGS) -c list.c

clean:
	rm *.o
	rm $(BIN)
