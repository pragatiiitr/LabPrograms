#include "array.cpp"
#include<iostream>
using namespace std;
template <typename dataType>
class Stack{
	public:
	    int size = 0;
		int len = 0;
	    Array<dataType> array;
	    void create(dataType capacity)
	    {
	     	 size = capacity;
		     array.CreateArray(size);
	    }
	    void push(dataType element)
	    {
	     	 array.Insert(element,0);
			 len++;
	    }
        void pop()
	    {
			if(len == 0)
			{
				cout<<"Stack is empty"<<endl;
				return;
			}
	      	array.removeFront();
			len--;
	    }
	    void peek()
	    {
		 if(len == 0)
		{	
			cout<<"Stack is Empty"<<endl;
			return;
		}
		cout<<"Top element is "<<array.arr[0]<<endl;
	    }
    
};

int main(){
            Stack<int> st;
	    int size;
	    cout<<"Enter the size of the stack"<<endl;
	    cin>>size;
	    st.create(size);
	    while (true) {
	        cout << "1. Push\n2. Pop\n3. Peek\n4.Exit\n";
	        int option;
	        cin >> option;
	
	        switch (option) {
	            case 1:
	                cout << "Enter value to push: ";
	                int value;
	                cin >> value;
	                st.push(value);
	                break;
	            case 2:
	                st.pop();
	                break;
	            case 3:
	                  st.peek();
	                  break;
	              case 4:
	                  exit(1);
	              default:
	                  cout << "Invalid choice. Try again." <<endl;
	        }
	    }
  return 0;
}
