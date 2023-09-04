XX = g++
CXXFLAGS = -Wall -g

all: t1 t2

t1: darray.o test1.o
	$(CC) array.o test1.o -o t1

t2: darray.o test2.o
	$(CC) array.o test2.o -o t2

darray.o: dynamicarray.cpp
	
clean: 
	rm -f $(PROGRAMS)
