#include "array.cpp"
#include<iostream>
using namespace std;
template < typename datatype>
class queue{
	public:
		int size;
		Array<datatype> array;
		void create(dataType capacity)
	    {
	     	 size = capacity;
		     array.CreateArray(size);
	    }
	    void enqueue(dataType element);
	    {
	     	 array.Insert(element);
	    }
      void dequeue()
	    {
	      	array.remove(size-1);
	    }
	     void display()
	    {
  		   array.Display();
	    }

};
int main(){
	queue<int> q;
  int size;
  cout<<"Enter the size of the queue"<<endl;
  cin>>size;
  q.create(size);
  while (true) {
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4.Exit\n";
        int option;
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter value to enqueue: ";
                int value;
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                  q.display()
                  break;
              case 4:
                  exit(1);
              default:
                  cout << "Invalid choice. Try again." <<endl;
        }
    }
  return 0;
}
