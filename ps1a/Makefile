CC= g++
CFLAGS= -Wall -Werror -ansi -pedantic -std=c++11
Boost= -lboost_unit_test_framework

all:	main.out ps1a

ps1a:	test.o LFSR.o
	$(CC) test.o LFSR.o -o ps1a $(Boost)

test.o:	test.cpp LFSR.hpp
	$(CC) -c test.cpp LFSR.hpp $(CFLAGS)

main.out:	main.o LFSR.o
	$(CC) main.o LFSR.o -o main.out

main.o:	main.cpp LFSR.hpp
	$(CC) -c main.cpp $(CFLAGS)

LFSR.o:	LFSR.cpp LFSR.hpp
	$(CC) -c LFSR.cpp $(CFLAGS)

clean:
	rm test.o main.o LFSR.o
	rm ps1a main.out
	rm LFSR.hpp.gch
