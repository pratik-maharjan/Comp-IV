CC= g++
CFLAGS= -Wall -std=c++0x -pedantic
SFMLFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all:	NBody

NBody:	nbody.o
	$(CC) nbody.o -o NBody $(SFMLFLAGS)

nbody.o:	nbody.cpp nbody.hpp
	$(CC) -c nbody.cpp nbody.hpp $(CFLAGS)

clean:
	rm *.o
	rm NBody

