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
		void remove(int option , dataType after = NULL , dataType before = NULL)
		{
			if(!head)
				cout<<"There is no Node in the list"<<endl;
			else if(option == 0) //delete from the front
			{
				Node<dataType>* nxtHead = head->next;
				head->next = NULL;
				free(head);
				head = nxtHead;
				cout<<"Head of the list deleted"<<endl;
			}
			else if(option == 1) //delete from the back
			{
				Node<dataType>* curr = head;
				if(head->next == NULL)
				{
					free(head);
					cout<<"Head Node Deleted"<<endl;
				}
				else
				{
					while(curr->next and curr->next->next != NULL)
						curr = curr->next;
					Node<dataType>* del = curr->next->next;
					curr->next->next = NULL;
					free(del);
					cout<<"Node At The Back Deleted"<<endl;
				}
			}
			else if(option == 2) //deletion after an element
			{
				Node<dataType>* curr = head;
				Node<dataType>* prev = NULL;
				while(curr->data != after)
				{
					prev = curr;
					curr = curr->next;
				}
				if(curr->data == after)
				{
					prev->next = curr->next;
					curr->next = NULL;
					free(curr);
					cout<<"Node After "<<after<<" Is Deleted"<<endl;
				}
				else
				{
					cout<<"Node with data "<<after<<" is not present in the list"<<endl;
				}
			}
			else //deletion before an element
			{
				Node<dataType>* curr = head;
				Node<dataType>* prev = NULL;
				if(head->next == before)
				{
					curr = head->next;
					head->next = NULL;
					free(head);
					head = curr;
					cout<<"Node Before "<<before<<" Is Deleted"<<endl;
				}		
				else
				{
					while(curr->next)
					{
						if(curr->next == before)
						{
							prev->next = curr->next;
							curr->next = NULL;
							free(curr);
							cout<<"Node Before "<<before<<" Is Deleted"<<endl;
						}
						else
						{
							prev = curr;
							curr = curr->next;
						}
					}
					if(prev and prev->next!=before)
						cout<<"Node with key "<<before<<" Is not present in the list"<<endl;
				}
			}
		}
		void displayList()
		{
			if(head == NULL)
			{
				cout<<"List is empty"<<endl;
			}
			else
			{
				cout<<"List Items ---- "<<endl;
				cout<<head->data;
				Node<dataType>* curr = head->next;
				while(curr)
				{
					cout<<"-->"<<curr->data;
					curr = curr->next;
				}
				cout<<endl;
			}
		}
};
int main()
{
	cout<<"Which type of data are you working on?"<<endl;
       //cout<<"Press 0 for int,1 for float and 2 for 
       LinkedList<int> list;
       list.insert(5,0);
       list.insert(6,1);
       list.insert(4,2,5);
       list.insert(3,3,4,4);
       list.displayList();
	return 0;
}

