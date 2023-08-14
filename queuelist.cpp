#include "linkedlist.cpp"
#include<iostream>
using namespace std;
template <class dataType>class Queue{
	public:
		Node<dataType>* q;
		Queue()
		{
			this->q = NULL;
		}
    void Enqueue(dataType element)
    {
      Node<dataType> val = new Node(element);
      val->next = q;
      q = val;
      cout<<"Element has been inserted at the front"<<endl;
    }
    void Dequeue()
    {
      Node<dataType> curr = q;
      Node<dataType> prev = q;
      if(!q)
      {
        cout<<"There is no element in the queue"<<endl;
        return;
      }
      if(!q->next)
      {
        q = NULL;
        cout<<"The element at the end of the queue has been deleted"<<endl;
        return;
      }
      while(curr->next and curr->next->next != NULL)
      { 
          curr = curr->next;
      }
      prev = curr;
      curr = curr->next;
      prev->next = NULL;
      free(curr);
      cout<<"The element at the end of the queue has been deleted"<<endl;
    }
    void display()
    {
      if(!q)
        cout<<"The queue is empty"<<endl;
      Node<dataType> curr = q;
      while(curr)
      {
        cout<<curr->data<<"->";
      }
      cout<<"NULL";
    }
};
int main()
{
  Queue<int> queue;

    while (true) {
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4.Exit\n";
        int option;
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter value to enqueue: ";
                int value;
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                  queue.display()
                  break;
              case 4:
                  exit(1);
              default:
                  cout << "Invalid choice. Try again." <<endl;
        }
    }
  return 0;
}
