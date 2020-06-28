CC = g++
CFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
OBJECTS = main.o PTree.o

all: $(OBJECTS)
	$(CC) -o tree main.o PTree.o $(CFLAGS)

main.o: main.cpp
	$(CC) -c main.cpp

PTree.o: PTree.cpp PTree.hpp
	$(CC) -c PTree.cpp

clean:
	rm $(OBJECTS) tree