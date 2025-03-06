CC = g++
CFLAGS = -g -Wall -Wextra

default: Stacker

Stacker: main.o stacker.o
	$(CC) $(CFLAGS) -o Stacker main.o stacker.o

main.o: main.cpp stacker.h
	$(CC) $(CFLAGS) -c main.cpp

stacker.o: stacker.cpp stacker.h
	$(CC) $(CFLAGS) -c stacker.cpp

clean:
	$(RM) Stacker *.o *~
