#ifndef HEADER_H
#define HEADER_H

#include<iostream>
template <class dataType> class Array{
	public:

		dataType *arr;
		int length;
		Array();
		void CreateArray(int size);
		void Insert(dataType element , int index);
		void removeFront();
		void remove(int index);
		void search(dataType element);
		dataType getElement(int index);
		void Display();
};
template <class dataType> class GraphMatrix {
	public:
	    Array<dataType> adj;
	    int size;
	    GraphMatrix(int sz, dataType element);
	    void addEdge(int row, int col, dataType weight);
	    int getEdge(int row, int col,int defaultVal);
	    void display();
};
#endif
