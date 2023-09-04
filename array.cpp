#include<iostream>
#include "header.h"
using namespace std;
template <class dataType> class Array
{
	public:

		dataType *arr;
		int length;
		Array()
		{
			dataType* arr = new dataType[1];
		}
		void CreateArray(int size)
		{
			length = size;
			arr = new dataType[size];
			for(int i=0;i<size;i++)
			{
				arr[i] = 0;
			}
		}
		void Insert(dataType element , int index)
		{
			dataType* arr_new = new dataType[length + 1];
			int it = 0;
			if(index > length)
			{
				cout<<"Index Out Of Bounds"<<endl;
				return;
			}
			for(it ; it < index ; it++)
			{
				arr_new[it] = arr[it];
			}
			for(it = length-1 ; it >= index ; it--)
			{
				arr_new[it+1] = arr[it];
			}
			arr_new[index] = element;
			arr = arr_new;
			length++;
			cout<<"Element Inserted"<<endl;
		}
		void removeFront()
		{
			if(length == 0)
			{
				cout<<"Array is empty"<<endl;
				return;
			}
			dataType* arr_new = new dataType[length - 1];
			for(int it=1 ; it < length ; it++)
			{
				arr_new[it-1]  = arr[it];
			}
			length--;
			arr = arr_new;
			cout<<"Top element has been deleted"<<endl;
		}
		void remove(int index)
		{
			dataType* arr_new = new dataType[length - 1];
			int element = arr[index];
			if(index >= length)
			{
				cout<<"Index Out Of Bound"<<endl;
				return;
			}
			for(int it=0 ; it < index ; it++)
			{
				arr_new[it]  = arr[it];
			}
			for(int it = index + 1 ; it < length ; it++)
			{
				arr_new[it - 1] = arr[it];
			}
			length--;
			arr = arr_new;
			cout<<"Element "<<element<<" Deleted from the entered index"<<endl;
		}
		void search(dataType element)
		{
			for(int it = 0; it < length ; it++)
			{
				if(arr[it] == element)
				{
					cout<<"Element "<<element<<" Found at Index "<<it<<endl;
					return;
				}
			}
			cout<<"Element NOt Found in the Array"<<endl;
		}
		dataType getElement(int index)
		{
			return arr[index];
		}
		void Display()
		{
			cout<<"Elements of Array are -- "<<endl;
			for(int it = 0 ; it < length ; it++)
			{
				cout<<arr[it]<<" ";
			}
			cout<<endl;
		}
		
};
// int main()
// {
// 	Array<int> array;
// 	while(1)
// 	{
// 		cout<<"Press 0 for insert, 1 for deleting an element , 2 for searching an element in cthe array, 3 for displaying the array and 4 to exit"<<endl;
// 		int option;
// 		cin>>option;
// 		switch(option)
// 		{
// 			case 0:
// 				{
// 					int element , index;
// 					cout<<"Enter the element you want to insert and its index"<<endl;
// 					cin>>element>>index;
// 					array.Insert(element,index);
// 					break;					break;
// 				}
// 			case 2:
// 				{
// 					cout<<"Enter the element you want to search in the array"<<endl;
// 					int element;
// 					cin>>element;
// 					array.search(element);
// 					break;
// 				}
// 			case 3:
// 				{
// 					array.Display();
// 					break;
// 				}
// 			case 4:
// 				exit(1);
// 		}
// 	}
// }

// 					int index;
// 					cout<<"Enter the index from where you want to delete the element"<<endl;
// 					cin>>index;
// 					array.remove(index);
// 					break;
// 				}
// 			case 2:
// 				{
// 					cout<<"Enter the element you want to search in the array"<<endl;
// 					int element;
// 					cin>>element;
// 					array.search(element);
// 					break;
// 				}
// 			case 3:
// 				{
// 					array.Display();
// 					break;
// 				}
// 			case 4:
// 				exit(1);
// 		}
// 	}
// }
