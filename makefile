CC = g++
CLAFGS = -g -Wall -Wextra

default: stegonography

stegonography:	Stegonography.o main.o
	$(CC) $(CFLAGS) -o stegonography Stegonography.o main.o

Stegonography.o:	Stegonography.cpp Steganography.h
	$(CC) $(CFLAGS) -c main.cpp

main.o: main.cpp Steganography.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) stegonography *.o *~
