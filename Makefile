#Declaring variables for the Makefile

CC=g++


CFLAGS=-c -Wall

all: player

player: a1.o
	$(CC) -pthread a1.cpp a1.h -o player

a1.o: a1.cpp
	$(CC) $(CFLAGS) a1.cpp

clean:
	rm -rf *o player STACK.txt
