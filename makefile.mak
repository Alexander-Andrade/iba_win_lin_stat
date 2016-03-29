CC=g++
CFLAGS=-std=c++11 
DEPS=WinThread.h LiThread.h Thread.h Headers.h 
OBJ=main.o

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

SysThreading: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ 

	
