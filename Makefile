CC=g++
CFLAGS=-c -g -Wall -Werror -ansi -pedantic
LIBS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
all: GuitarHero

GuitarHero: GuitarString.o GuitarHero.o RingBuffer.o
	$(CC) $(LDFLAGS) -o GuitarHero GuitarString.o GuitarHero.o RingBuffer.o $(LIBS)

GuitarHero.o: GuitarHero.cpp GuitarString.hpp
	$(CC) $(CFLAGS) GuitarHero.cpp

GuitarString.o: GuitarString.cpp GuitarString.hpp
	$(CC) $(CFLAGS) GuitarString.cpp

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	$(CC) $(CFLAGS) RingBuffer.cpp

clean:
	rm *.o GuitarHero *~
