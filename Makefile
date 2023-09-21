CC = g++
CFLAGS = -Wall -O2 -ansi -pedantic -Werror

output: bfs.o adjacencymatrix.o queueArray.o array.o header.h
	$(CC) $(CFLAGS) bfs.o adjacencymatrix.o queueArray.o array.o -o output

bfs.o: bfs.cpp adjacencymatrix.o queueArray.o array.o header.h
	$(CC) $(CFLAGS) -c bfs.cpp
 	
adjacencymatrix.o: adjacencymatrix.cpp header.h
			$(CC) $(CFLAGS) -c adjacencymatrix.cpp	
		
queueArray.o: queueArray.cpp header.h
		$(CC) $(CFLAGS) -c queueArray.cpp
		
array.o: array.cpp header.h
	$(CC) $(CFLAGS) -c array.cpp

clean: 
	rm *o output

