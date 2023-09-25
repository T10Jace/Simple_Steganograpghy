CC = g++
CLAFGS = -g -Wall -Wextra

default: steganography

steganography:	Steganography.o main.o
	$(CC) $(CFLAGS) -o steganography Steganography.o main.o

Steganography.o:  Steganography.cpp Steganography.h
	$(CC) $(CFLAGS) -c Steganography.cpp

main.o: main.cpp Steganography.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) steganography *.o *~
