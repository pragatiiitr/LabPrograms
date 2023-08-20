CXX = g++
CXXFLAGS = -Wall -g

PROGRAMS = adjmatrix

all: $(PROGRAMS)

adjmatrix: array.cpp adjacencymatrix.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^
clean: 
	rm -f $(PROGRAMS)
