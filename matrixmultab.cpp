#include "header.h"
#include "array.cpp"
#include "adjacencymatrix.cpp"
using namespace std;
Array<int> a;
GraphMatrix<int> dp;
GraphMatrix<int> initialMatrix(int sz)
{
	GraphMatrix<int> g(sz,0);
	for(int i=0;i<sz;i++)
        {
                for(int j=0;j<sz;j++)
                {
                        g.addEdge(i,j,1000000);
                }
        }
	return g;
}
int tab(int start, int end)
{
	for(int i=1;i<=end;i++)
	{
		dp.addEdge(i,i,0);
	}
	for(int l=2;l<=end;l++)
	{
		for(int i=start;i+l-1<=end;i++)
		{
			int j = i+l-1;
			for(int k=i;k<=j-1;k++)
			{
				int temp = dp.getEdge(i,k,1000000) + dp.getEdge(k+1,j,1000000) + a.getElement(i-1)*a.getElement(k)*a.getElement(j);
				if(temp < dp.getEdge(i,j,1000000))
					dp.addEdge(i,j,temp);
			}
		}
	}
	return dp.getEdge(start,end,1000000);
}
int main()
{
	cout<<"Enter the size of matrix"<<endl;
	int sz;
	cin>>sz;
	a.CreateArray(sz);
	for(int i=0;i<sz;i++)
	{
		int temp;
		cin>>temp;
		a.Insert(temp, i);
	}
	dp = initialMatrix(sz);
	cout<<tab(1,sz-1);
	//dp.display();
	
}
