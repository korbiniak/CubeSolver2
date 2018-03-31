CXX := /usr/bin/g++
CXXFLAGS := -O2 -lm -std=c++14 -Wall -Wshadow -W
INCLUDE := ./src/include

all: bin/Solver

bin/Solver: bin/main.o bin/cube.o bin/gen.o bin/solve.o 
	$(CXX) $(CXXFLAGS) -o bin/Solver bin/main.o bin/cube.o bin/solve.o bin/gen.o

bin/main.o: src/main.cpp 
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -c -o bin/main.o src/main.cpp 

bin/cube.o: src/cube.cpp src/include/cube.h 
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -c -o bin/cube.o src/cube.cpp

bin/gen.o: src/gen.cpp src/include/gen.h
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -c -o bin/gen.o src/gen.cpp

bin/solve.o: src/solve.cpp src/include/solve.h 
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -c -o bin/solve.o src/solve.cpp

bin/include/config.h:

clean: 
	@rm bin/*.o bin/Solver

.PHONY: all clean