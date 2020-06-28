CC= g++
CFLAGS= -g -Wall -Werror -std=c++0x -pedantic
SFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
Boost= -lboost_unit_test_framework

# Make ps5a & a dummy tester
all:	GuitarHero GStest GuitarHeroLite

# PS5B executable
GuitarHero:	GuitarHero.o GuitarString.o RingBuffer.o
	$(CC) GuitarHero.o GuitarString.o RingBuffer.o -o GuitarHero $(SFLAGS)

GuitarHeroLite:	GuitarHeroLite.o GuitarString.o RingBuffer.o
	$(CC) GuitarHeroLite.o GuitarString.o RingBuffer.o -o GuitarHeroLite $(SFLAGS)

# GStest executable
GStest:	GStest.o GuitarString.o RingBuffer.o
	$(CC) GStest.o GuitarString.o RingBuffer.o -o GStest $(Boost)

# Object files
GuitarHero.o: 	GuitarHero.cpp GuitarString.hpp
	$(CC) -c GuitarHero.cpp GuitarString.hpp $(CFLAGS)

GuitarHeroLite.o: 	GuitarHeroLite.cpp GuitarString.hpp
	$(CC) -c GuitarHeroLite.cpp GuitarString.hpp $(CFLAGS)

GuitarString.o: GuitarString.cpp GuitarString.hpp
	$(CC) -c GuitarString.cpp GuitarString.hpp $(CFLAGS)

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	$(CC) -c RingBuffer.cpp RingBuffer.hpp $(CFLAGS)

GStest.o:	GStest.cpp
	$(CC) -c GStest.cpp $(Boost)

# Cleanup object files
clean:
	rm *.o
	rm *.gch
	rm GuitarHero
	rm GuitarHeroLite
	rm GStest