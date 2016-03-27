CC=g++
CFLAGS=-pthread -std=c++11 -Wall -pedantic 
DEPS=LiThread.h Thread.h Headers.h 
OBJ=main.o

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

SysThreading: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ 
	./SysThreading

	
