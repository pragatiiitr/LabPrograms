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
		void insert(dataType value , int option , dataType after = NULL , dataType before = NULL)
		{
			Node<dataType>* node = new Node<dataType>[1];
			node->data = value;
			if(option == 0) //for insertion at the starting
			{
				if(head == NULL)
				{
					head = node;
					node->next = head;
					cout<<"New Node Added"<<endl;
					return;
				}
				node->next = head;
			       	Node<dataType>* temp = head;
				while(temp->next != head)
				{
					temp = temp->next;
				}	
				temp->next = node;
				head = node;
				cout<<"Node is Inserted at the head of the list"<<endl;
			}
			else if(option == 1) //for insertion at the back
			{
				if(head == NULL)
				{
					head = node;
					node->next = head;
				        cout<<"Head of the list inserted"<<endl;
					return;
				}
				Node<dataType>* curr = head;
				while(curr->next != head)
				{
					curr = curr->next;
				}
				curr->next = node;
				node->next = head;
				cout<<"New Node Inserted"<<endl;

			}
			else if(option == 2)//for insertion after an element
			{
				Node<dataType>* curr = head;
				if(head->data == after)
				{
					node->next = curr->next;
					curr->next = node;
					cout<<"New Node Inserted After "<<after<<endl;
					return;

				}
				curr = curr->next;
				while(curr->next != head)
				{
					if(curr->data == after)
					{
						node->next = curr->next;
						curr->next = node;
						cout<<"New Node Inserted After "<<after<<endl;
						return;
					}
					else
						curr = curr->next;
				}
				
				cout<<"Given Node not found in the list"<<endl;
			}
		}
		void remove(int option , dataType after = NULL , dataType before = NULL , dataType element = NULL)
		{
			if(!head)
				cout<<"There is no Node in the list"<<endl;
			else if(option == 0) //delete from the front
			{
				Node<dataType>* nxtHead = head->next;
				if(head->next)
				{
					Node<dataType>* curr = head->next;
					while(curr->next != head)
					{
						curr = curr->next;
					}
					curr->next = nxtHead;
				}
				head->next = NULL;
				free(head);
				head = nxtHead;
				cout<<"Head of the list deleted"<<endl;
			}
			else if(option == 1) //delete from the back
			{
				Node<dataType>* curr = head;
				if(head->next == head)
				{
					head->next = NULL;
					free(head);
					cout<<"Head Node Deleted"<<endl;
				}
				else
				{
					while(curr->next->next != head)
						curr = curr->next;
					Node<dataType>* del = curr->next;
					curr->next = head;
					del->next = NULL;
					free(del);
					cout<<"Node At The Back Deleted"<<endl;
				}
			}
			else //deletion of an exact element
			{
				Node<dataType>* curr = head;
				Node<dataType>* prev = NULL;
				if(head->data == element and head->next != head)
				{
					curr = curr->next;
					while(curr != head)
					{
						prev = curr;
						curr = curr->next;
					}
					curr = head->next;
					prev->next = curr;
					head->next = NULL;
					free(head);
					head = curr;
					cout<<"Node With Key "<<element<<" Is Deleted"<<endl;
					return;
				}		
				else if(head->data == element and head->next == head)
				{
					head->next = NULL;
					free(head);
					cout<<"Node with key "<<element<<" Is Deleted"<<endl;
				}
				else
				{
					curr = curr->next;
					prev = head;
					while(curr and curr != head) 
					{
						if(curr->data == element)
						{
							prev->next = curr->next;
							curr->next = NULL;
							cout<<"Node With Key "<<element<<" Is Deleted"<<endl;
							break;
						}
						else
						{
							prev = curr;
							curr = curr->next;
						}
					}
					if(curr == head)
						cout<<"Node  Is not present in the list"<<endl;
					else
						free(curr);
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
				while(curr != head)
				{
					cout<<"-->"<<curr->data;
					curr = curr->next;
				}
				cout<<endl;
			}
		}
		void search(int element)
		{
			if(head == NULL)
				cout<<"List Is Empty"<<endl;
			else
			{
				Node<dataType>* curr = head;
				if(head->data == element)
				{
					cout<<"Element Found With Key "<<element<<endl;
					return;
				}
				curr = curr->next;
				while(curr != head)
				{
					if(curr->data == element)
					{
						cout<<"Element Found With Key "<<element<<endl;
						break;
					}
					curr = curr->next;
				}
				if(curr == NULL)
					cout<<"Element with Given Key Is Not Present in the List"<<endl;
			}
		}
};
int main()
{
	cout<<"Which type of data are you working on?"<<endl;
       	cout<<"Press 0 for int,1 for float and 2 for char"<<endl;
       	int dataOption;
	LinkedList<int> list;
      	list.insert(5,0);
       	list.insert(6,1);
       	list.insert(4,2,5);
//     	list.insert(3,3,4,4);
	list.insert(1,0);
	list.insert(7,0);
	list.displayList();
	list.remove(0);
	list.displayList();
	list.remove(1);
       	list.displayList();
	list.remove(2,5,5,5);
	list.displayList();
	list.remove(3,NULL,NULL,4);
	list.displayList();
	list.insert(8,0);
	list.displayList();
	list.remove(4,NULL,NULL,6);
	list.displayList();
	list.search(8);
	list.search(7);
	return 0;
}

