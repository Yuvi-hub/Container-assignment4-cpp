CXX = g++
CXXFLAGS = -std=c++17 -Wall -I.

TARGET = main

all: Main

Main: Main.o
	$(CXX) $(CXXFLAGS) -o main Main.o

Main.o: Main.cpp MyContainer.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o Main.o

test: Test.o
	$(CXX) $(CXXFLAGS) -o test Test.o 
 
Test.o: Test.cpp MyContainer.hpp
	$(CXX) $(CXXFLAGS) -c Test.cpp -o Test.o

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all ./test

clean: 
	rm -f Main.o main Test.o test
