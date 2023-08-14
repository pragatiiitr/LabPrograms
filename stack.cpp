#include "linkedlist.cpp"
#include<bits/stdc++.h>
using namespace std;
template < typename dataType>class Stack{	
 public:
		Node<dataType>* stack;
		Stack()
		{
			this->stack = NULL;
		}
    void push(dataType element)
    {
      Node<dataType>* curr = new Node<dataType>[1];
      curr->data = element;
      curr->next = stack;
      stack = curr;
      cout<<"New Node Inserted at the top"<<endl;
    }
    void pop()
    {
      if(!stack)
      {
        cout<<"The stack is Empty"<<endl;
        return;
      }
      cout<<"Element "<<stack->data<<"will be popped"<<endl;
      Node<dataType>* curr = stack;
      stack = stack->next;
      curr->next = NULL;
      free(curr);
    }
    void peek()
    {
      if(!stack)
      {
        cout<<"The stack is Empty"<<endl;
        return;
      }
      cout<<"Element "<<stack->data<<"is at the top"<<endl;
    }
};
int main()
{
  Stack<int> st;

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
