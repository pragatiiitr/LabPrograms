#include "array.cpp"
#include<iostream>
using namespace std;
template <typename dataType>
class stack{
	public:
    int size = 0;
    Array<dataType> array;
		void create(dataType capacity)
    {
      size = capacity;
			array. CreateArray(size);
    }
		void push(dataType element);
    {
      array.Insert(element);
    }
		void pop()
    {
      array.removeFront();
    }
		void display()
    {
      array.Display();
    }
};

int main(){
	
	}
