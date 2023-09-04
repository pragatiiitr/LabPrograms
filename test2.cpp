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
auto testDynamicArray(int insertionProbability,int startProb,  Array<int> &dynamicarray,int n) {
    int numInsertions = insertionProbability*n;
    int numDeletions = n - numInsertions;
    int numStart = startProb*n;
    int numEnd = n - numStart;
    srand(time(nullptr)); // Seed for random number generator

    auto start = chrono::high_resolution_clock::now();
    int j=0;
    for (int i = 0; i < numInsertions; ++i) {
        int element = rand() % 100;
        if(j < numStart)
        {
        	dynamicarray.InsertFront(element);
        	j++;
        }
        else
        dynamicarray.InsertBack(element);
    }
    //dynamicarray.show();
	for (int i = 0; i < numDeletions; ++i) {
        if(j < numStart)
        {
        	dynamicarray.removeFront();
        	j++;
        }
        else
        dynamicarray.removeBack();
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> timeTaken = end - start;

    return timeTaken.count();
}

// Function to test linked list
auto testLinkedList(int insertionProbability,int startProb ,LinkedList<int>& linkedList,int n) {
    int numInsertions = insertionProbability*n;
    int numDeletions = n - numInsertions;
    int numStart = startProb*n;
    int numEnd = n - numStart;
    srand(time(nullptr)); // Seed for random number generator
	int j=0;
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < numInsertions; ++i) {
        int element = rand() % 100;
        if(j < numStart)
        {
        	linkedList.insert(element,0);
        	j++;
        }
        else
        	linkedList.insert(element, 1);
    }
	for (int i = 0; i < numDeletions; ++i) {
	if(j < numStart)
        {
        	linkedList.remove(0);
        	j++;
        }
        else
        	linkedList.remove(1);
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
        cout<<"Dynamic Array Time Analysis"<<endl;
        cout<<"Prob of Insert/Del -"<<endl;
        cout<<"Prob of Start/End |"<<endl;
        cout<<"   ";
        for(double j=1.0;j>=0;j-=0.1)
        {
        	cout<<(int)(j*100)<<" ";
        }
        cout<<endl;
        for(double i = 1.0;i>=0;i-=0.1)
        {
        	cout<<i*100<<" ";
        	for(double j=1.0;j>=0;j-=0.1)
        	{
        		double temp = (double)testDynamicArray(i, j,dynamicarray,20);
        		array += temp;
        		cout<<temp<<" ";
        	}
        	cout<<endl;
        	
        }
        cout<<"Linked List Time Analysis"<<endl;
        cout<<"Prob of Insert/Del -"<<endl;
        cout<<"Prob of Start/End |"<<endl;
        cout<<"   ";
        for(double j=1.0;j>=0;j-=0.1)
        {
        	cout<<(int)(j*100)<<" ";
        }
        cout<<endl;
        for(double i = 1.0;i>=0;i-=0.1)
        {
        	cout<<i*100<<" ";
        	for(double j=1.0;j>=0;j-=0.1)
        	{
        		double temp = (double)testLinkedList(i, j,linkedList,20);
        		list += temp;
        		cout<<temp<<" ";
        	}
        	cout<<endl;
        }
        cout<<"Average performance of array "<<array/(double)11<<endl;
        cout<<"Average performane of list "<<list/(double)11<<endl;
    return 0;
}
