#include<iostream>
using namespace std;
template <class dataType>class Node{
	public:
		dataType data;
		Node<dataType>*  next;
	Node()
	{
		this->next = 	NULL;
	}
	

};
template <class dataType>class LinkedList{
	public:
		Node<dataType>* head;
		LinkedList()
		{
			this->head = NULL;
		}
		void display()
		{
			cout<<head->data<<endl;
		}
		void insert(dataType value , int option , dataType after = NULL , dataType before = NULL)
		{
			Node<dataType>* node = new Node<dataType>[1];
			node->data = value;
			if(option == 0)//for insertion at the starting
			{
				Node<dataType>* list = head;
				head = node;
				head->next = list;
			}
			else if(option == 1)//for insertion at the back
			{
				if(head == NULL)
				{
					head = node;
				        cout<<"Head of the list inserted"<<endl;
					return;
				}
				Node<dataType>* curr = head;
				while(curr->next)
				{
					curr = curr->next;
				}
				curr->next = node;
				cout<<"New Node Inserted"<<endl;

			}
			else if(option == 2)//for insertion after an element
			{
				Node<dataType>* curr = head;
				bool flag = false;
				while(curr)
				{
					if(curr->data == after)
					{
						node->next = curr->next;
						curr->next = node;
						flag = true;
						cout<<"New Node Inserted After "<<after<<endl;
						break;
					}
					else
						curr = curr->next;
				}
				if(!flag)
				{
					cout<<"Given Node not found in the list"<<endl;
				}
			}
			else //for insertion before an element
			{
				Node<dataType>* curr = head;
				Node<dataType>* prev = NULL;
				bool flag = false;
				while(curr)
				{
					if(curr->data == before)
					{
						if(curr == head)
						{
							head = node;
							head->next = curr;
						}
						else
						{
							prev->next = node;
							node->next = curr;
						}
						flag = true;
						cout<<"New Node Inserted Before "<<before<<endl;
						break;
					}
					else
					{
						prev = curr;
						curr = curr->next;
					}
				}
				if(!flag)
				{
					cout<<"Given Node not found in the list"<<endl;
				}					
			}
		}

};
int main()
{
	cout<<"Which type of data are you working on?"<<endl;
       //cout<<"Press 0 for int,1 for float and 2 for 
       LinkedList<int> list;
       list.insert(5,0);
       list.display();
	return 0;
}

