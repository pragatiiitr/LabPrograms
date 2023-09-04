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
				//cout<<"Node is Inserted at the head of the list"<<endl;
			}
			else if(option == 1)//for insertion at the back
			{
				if(head == NULL)
				{
					head = node;
				        //cout<<"Head of the list inserted"<<endl;
					return;
				}
				Node<dataType>* curr = head;
				while(curr->next)
				{
					curr = curr->next;
				}
				curr->next = node;
				//cout<<"New Node Inserted"<<endl;

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
		void remove(int option , dataType after = NULL , dataType before = NULL , dataType element = NULL)
		{
			if(!head)
				return;
			else if(option == 0) //delete from the front
			{
				Node<dataType>* nxtHead = head->next;
				head->next = NULL;
				free(head);
				head = nxtHead;
				//cout<<"Head of the list deleted"<<endl;
			}
			else if(option == 1) //delete from the back
			{
				Node<dataType>* curr = head;
				if(head == NULL)
				{
					free(head);
					//cout<<"Head Node Deleted"<<endl;
				}
				else
				{
					while(curr->next and curr->next->next != NULL)
						curr = curr->next;
					Node<dataType>* del = curr->next;
					curr->next = NULL;
					free(del);
					//cout<<"Node At The Back Deleted"<<endl;
				}
			}
			else if(option == 2) //deletion after an element
			{
				Node<dataType>* curr = head;
				while(curr->next->data != after)
				{
					curr = curr->next;
				}
				if(curr->next->data == after)
				{
					Node<dataType>* temp = curr->next;
					curr->next = curr->next->next;
					temp->next = NULL;
					free(temp);
					cout<<"Node After "<<after<<" Is Deleted"<<endl;
				}
				else
				{
					cout<<"Node with data "<<after<<" is not present in the list"<<endl;
				}
			}
			else if(option == 3)  //deletion before an element
			{
				Node<dataType>* curr = head;
				Node<dataType>* prev = NULL;
				if(head->next->data == before)
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
						if(curr->next->data == before)
						{
							prev->next = curr->next;
							curr->next = NULL;
							free(curr);
							cout<<"Node Before "<<before<<" Is Deleted"<<endl;
							break;
						}
						else
						{
							prev = curr;
							curr = curr->next;
						}
					}
					if(prev and prev->next->data != before)
						cout<<"Node with key "<<before<<" Is not present in the list"<<endl;
				}
			}
			else //deletion of an exact element
			{
				Node<dataType>* curr = head;
				Node<dataType>* prev = NULL;
				if(head->data == element)
				{
					curr = head->next;
					head->next = NULL;
					free(head);
					head = curr;
					cout<<"Node With Key "<<element<<" Is Deleted"<<endl;
				}		
				else
				{
					while(curr)
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
					if(curr == NULL)
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
				//cout<<"List Items ---- "<<endl;
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
		void search(int element)
		{
			if(head == NULL)
				cout<<"List Is Empty"<<endl;
			else
			{
				Node<dataType>* curr = head;
				while(curr)
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
// int main()
// {
// 	LinkedList<int> list;
// 	while(1)
// 	{
// 		cout<<"Press 0 for insert, 1 for deleting an element , 2 for searching an element in doubly linked list, 3 for displaying the list and 4 to exit"<<endl;
// 		int option;
// 		cin>>option;
// 		switch(option)
// 		{
// 			case 0:
// 				{
// 					int choice , element , after = NULL , before = NULL;
// 					cout<<"Press 0 to insert at the front, 1 to insert at the back and 2 to insert after an element, 3 to insert before an element"<<endl;
// 					cin>>choice;
// 					cout<<"Enter the element you want to insert"<<endl;
// 					cin>>element;
// 					if(choice == 2)
// 					{
// 						cout<<"Enter the element after which you want to insert the current element"<<endl;
// 						cin>>after;
// 					}
// 					else if(choice == 3)
// 					{
// 						cout<<"Enter the element before which you want to insert the current element"<<endl;
// 						cin>>before;
// 					}
// 					list.insert(element,choice,after,before);
// 					break;
// 				}
// 			case 1:
// 				{
// 					int choice, after = NULL, before = NULL, element = NULL;
// 					cout<<"Press 0 to delete from front , 1 to delete from back,2 to delete after an element, 3 to delete before an element and 4 to delete an exact element"<<endl;
// 					cin>>choice;
// 					if(choice == 2)
// 					{
// 						cout<<"Enter the element after which you want to delete"<<endl;
// 						cin>>after;
// 					}
// 					else if(choice == 3)
// 					{
// 						cout<<"Enter the element before which you want to delete"<<endl;
// 						cin>>before;
// 					}
// 					else if(choice == 4)
// 					{
// 						cout<<"Enter the element which you want to delete"<<endl;
// 						cin>>element;
// 					}
// 					list.remove(choice , after, before , element);
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

