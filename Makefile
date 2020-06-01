CC=g++
FLAGS="-Wall -O2"

all: prog

prog : main.o booking.o
	$(CC) -o booking main.o booking.o

main.o : main.cpp booking.h
	$(CC) -c main.cpp

booking.o : booking.cpp booking.h
	$(CC) -c booking.cpp

clean:
	rm -rf *.o booking
