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
		void insert(dataType value , int option , dataType after = NULL)
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
				if(head->data == after and head->next)
				{
					node->next = curr->next;
					curr->next = node;
					cout<<"New Node Inserted After "<<after<<endl;
					return;

				}
				else if(head->data == after and head->next == NULL)
				{
					head->next = node;
					node->next = head;
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
		void remove(int option , dataType element = NULL)
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
				if(curr == head)
					cout<<"Element with Given Key Is Not Present in the List"<<endl;
			}
		}
};
// int main()
// {
// 	LinkedList<int> list;
// 	while(1)
// 	{
// 		cout<<"Press 0 for insert, 1 for deleting an element , 2 for searching an element in circular linked list, 3 for displaying the list and 4 to exit"<<endl;
// 		int option;
// 		cin>>option;
// 		switch(option)
// 		{
// 			case 0:
// 				{
// 					int choice , element , after = NULL;
// 					cout<<"Press 0 to insert at the front, 1 to insert at the back and 2 to insert after an element"<<endl;
// 					cin>>choice;
// 					cout<<"Enter the element you want to insert"<<endl;
// 					cin>>element;
// 					if(choice == 2)
// 					{
// 						cout<<"Enter the element after which you want to insert the current element"<<endl;
// 						cin>>after;
// 					}
// 					list.insert(element,choice,after);
// 					break;
// 				}
// 			case 1:
// 				{
// 					int choice, element = NULL;
// 					cout<<"Press 0 to delete from front , 1 to delete from back and 2 to delete the exact element"<<endl;
// 					cin>>choice;
// 					if(choice == 2)
// 					{
// 						cout<<"Enter the element you want to delete"<<endl;
// 						cin>>element;
// 					}
// 					list.remove(choice,element);
// 					break;
// 				}
// 			case 2:
// 				{
// 					cout<<"Enter the element you want to search in the list"<<endl;
// 					int element;
// 					cin>>element;
// 					list.search(element);
// 					break;
// 				}
// 			case 3:
// 				{
// 					list.displayList();
// 					break;
// 				}
// 			case 4:
// 				exit(1);
// 		}
// 	}
// 	return 0;
// }

