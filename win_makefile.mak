CC=g++
CFLAGS=-c -std=c++11 -Wall 
DEPS=Thread.h Headers.h 
all: Threading
	
Threading: main.o
	$(CC) main.cpp -o Threading

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
	
clean:
	rm -rf *.o Threading
