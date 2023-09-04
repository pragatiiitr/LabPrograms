#include<iostream>
using namespace std;
template <class dataType> class Array
{
	public:

		dataType *arr;
		int length = 0;
		int length_s = 0;
		int length_b = 0;
		int size = 0;
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
		void InsertFront(dataType element)
		{
			if(size == 0)
			{
				dataType* arr_new = new dataType[1];
				arr_new[0] = element;
				arr = arr_new;
				length_b++;
				size++;
				return;
			}
			if(length_s == 0)
			{
				dataType* arr_new = new dataType[2*size];
				for(int i=size;i<2*size;i++)
				{
					arr_new[i] = arr[i - size];
				}
				arr_new[size - 1] = element;
				length_b = length_b + size;
				length_s = size -1;
				size = 2*size;
				arr = arr_new;
			}
			else 
			{
				arr[--length_s] = element;
			}
		}
		void InsertBack(dataType element)
		{
			if(size == 0)
			{
				dataType* arr_new = new dataType[1];
				arr_new[0] = element;
				arr = arr_new;
				length_b++;
				length_s++;
				size++;
				return;
			}
			if(length_b == size)
			{
				dataType* arr_new = new dataType[2*size];
				for(int i=0;i<size;i++)
				{
					arr_new[i] = arr[i];
				}
				arr_new[length_b] = element;
				length_b++;
				size = 2*size;
				arr = arr_new;
			}
			else
				arr[length_b++] = element;
		}
		void removeBack()
		{
			if(length_b == 0)
				return;
			if(length_b == size/4 + 1)
			{
				dataType* arr_new = new dataType[size/4];
				for(int i=0;i<length_b-1;i++)
					arr_new[i] = arr[i];
				arr = arr_new;
				size = size/4;
				length_b--;
				return;
			}
			length_b--;
		}
		void removeFront()
		{
			if(size == 0)
			{
				//cout<<"Array is empty"<<endl;
				return;
			}
			if(size/4 == (size - length_s - 1))
			{
				dataType* arr_new = new dataType[size/4];
				for(int i=0;i<size/4;i++)
				{
					arr_new[i] = arr[length_s + i + 1];
				}
				length_b = length_b -length_s - 1;
				length_s = 0;
				size = size/4;
				arr = arr_new;
				return;
			}
			length_s++;
		}
		void remove(int index)
		{
			dataType* arr_new = new dataType[length - 1];
			int element = arr[index];
			if(index >= length)
			{
				//cout<<"Index Out Of Bound"<<endl;
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
			for(int it = 0;it<length_s;it++)
				cout<<"g ";
			for(int it =length_s ; it < length_b ; it++)
			{
				cout<<arr[it]<<" ";
			}
			for(int it = length_b;it<size;it++)
				cout<<"g ";
			cout<<endl;
		}
		
};
/*int main()
{
	Array<int> a;
	a.InsertFront(7);
	a.InsertFront(6);
	a.InsertFront(5);
	a.Display();
	a.InsertFront(4);
	a.InsertFront(3);
	a.InsertFront(2);
	a.Display();
	a.InsertFront(1);
	a.InsertFront(0);
	a.Display();
	a.removeFront();
	a.removeBack();
	a.Display();
	a.removeBack();
	a.removeFront();
	a.removeFront();
	a.removeFront();
	a.removeFront();
	a.Display();
	a.removeFront();
	a.Display();
}*/
