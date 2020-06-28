CC= g++
CFLAGS= -Wall -Wennor -ansi -pedantic
SFMLFLAGS= -lsfml-graphics -lsfml-window -lsfml-system

all:	NBody

NBody:	nbody.o
	$(CC) nbody.o -o NBody $(SFMLFLAGS)

nbody.o:	nbody.cpp nbody.hpp
	$(CC) -c nbody.cpp nbody.hpp $(CFLAGS)

clean:
	rm *.o
	rm NBody