CC = g++
CFLAGS = -Wall -O2 -ansi -pedantic -Werror

output: bfs.o adjacencymatrix.o queueArray.o array.o
	$(CC) $(CFLAGS) bfs.o adjacencymatrix.o queueArray.o array.o -o output

bfs.o: bfs.cpp
	$(CC) $(CFLAGS) -c bfs.cpp
 	
adjacencymatrix.o: adjacencymatrix.cpp 
			$(CC) $(CFLAGS) -c adjacencymatrix.cpp	
		
queueArray.o: queueArray.cpp
		$(CC) $(CFLAGS) -c queueArray.cpp
		
array.o: array.cpp header.h
	$(CC) $(CFLAGS) -c array.cpp

clean: 
	rm *o output

