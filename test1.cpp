#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <cstring>
#include "dynamicarray.cpp"
#include "linkedlist.cpp"

using namespace std;

// Function to test dynamic array
auto testDynamicArray(int insertionProbability, Array<int> &dynamicarray,int n) {
    int numInsertions = insertionProbability*n;
    int numDeletions = n - numInsertions;
    srand(time(nullptr)); // Seed for random number generator

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < numInsertions; ++i) {
        int element = rand() % 100;
        dynamicarray.InsertBack(element);
    }
    //dynamicarray.show();
	for (int i = 0; i < numDeletions; ++i) {
        int element = rand() % 100;
        dynamicarray.removeBack();
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> timeTaken = end - start;

    return timeTaken.count();
}

// Function to test linked list
auto testLinkedList(int insertionProbability, LinkedList<int>& linkedList,int n) {
    int numInsertions = insertionProbability*n;
    int numDeletions = n - numInsertions;
    srand(time(nullptr)); // Seed for random number generator

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < numInsertions; ++i) {
        int element = rand() % 100;
        linkedList.insert(element, 1);
    }
	for (int i = 0; i < numDeletions; ++i) {
        int element = rand() % 100;
        linkedList.remove(1);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> timeTaken = end - start;
	return timeTaken.count();
}

int main() {
    
    	Array<int> dynamicarray;
    	LinkedList<int> linkedList;
        double array = 0,list = 0;
        for(double i = 1.0;i>=0;i-=0.1)
        {
        	array += (double)testDynamicArray(i, dynamicarray,20);
        }
        for(double i = 1.0;i>=0;i-=0.1)
        {
        	list += (double)testLinkedList(i, linkedList,20);
        }
        cout<<"Average performance of array "<<array/(double)11<<endl;
        cout<<"Average performane of list "<<list/(double)11<<endl;
    return 0;
}
