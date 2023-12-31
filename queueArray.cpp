#include "header.h"

using namespace std;
template < typename dataType>
class queue{
	public:
		int size;
        	int len;
		Array<dataType> array;
		void create(int capacity)
	    {
	     	 size = capacity;
		     array.CreateArray(size);
	    }
	    void enqueue(dataType element)
	    {
	     	 array.Insert(element, 0);
             	len++;
	    }
	    bool IsEmpty()
	    {
	    	if(len == 0)
	    		return true;
	    	return false;
	    }
	    dataType rear()
	    {
	    	return array.arr[len-1];
	    }
            void dequeue()
	    {
            if(len == 0)
		{
			cout<<"Queue is empty"<<endl;
			return;
		}
	      	array.remove(len-1);
            len--;
	    }
	    dataType top()
	    {
	    	return array.arr[0];
	    }
	     void display()
	    {
            if(len ==0 )
            {
                cout<<"Queue is empty"<<endl;
                return;
            }
  		   for(int i=0;i<len;i++)
           {
            cout<<array.arr[i]<<" ";
           }
           cout<<endl;
	    }

};
//int main(){
//	queue<int> q;
//  int size;
//  cout<<"Enter the size of the queue"<<endl;
//  cin>>size;
//  q.create(size);
//  while (true) {
//        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4.Exit\n";
//        int option;
//        cin >> option;
//
//        switch (option) {
//            case 1:
//                cout << "Enter value to enqueue: ";
//                int value;
//                cin >> value;
//                q.enqueue(value);
//                break;
//            case 2:
//                q.dequeue();
//                break;
//            case 3:
//                  q.display();
//                  break;
//            case 4:
//                  exit(1);
//            default:
//                  cout << "Invalid choice. Try again." <<endl;
//        }
//    }
//  return 0;
//}
