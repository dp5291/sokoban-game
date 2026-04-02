CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
# Your .hpp files
DEPS = Sokoban.hpp
# Your compiled .o files
OBJECTS = Sokoban.o main.o
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework


.PHONY: all Sokoban clean lint test


all: Sokoban Sokoban.a test

# Wildcard recipe to make .o files from corresponding .cpp file
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<
test: Sokoban.o test.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)
Sokoban.a: Sokoban.o
	ar rcs $@ $^ 

Sokoban: Sokoban.o main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)


clean:
	-rm -f *.o Sokoban Sokoban.a test

lint:
	cpplint *.cpp *.hpp
