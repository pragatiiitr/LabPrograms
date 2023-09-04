output: bfs.o
	g++ -o bfs.o -o output

bfs.o: adjacencymatrix.o queueArray.o bfs.cpp
	g++ -c bfs.cpp

adjacencymatrix.o: array.o adjacencymatrix.cpp
	g++ -c adjacencymatrix.cpp

queueArray.o: array.o queueArray.cpp
	g++ -c queueArray.cpp

array.o: array.cpp
	g++ -c array.cpp

clean: 
	rm *o 

