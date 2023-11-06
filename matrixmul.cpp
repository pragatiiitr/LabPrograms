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
int memoiz(int start, int end)
{
	if(dp.getEdge(start,end,1000000) != 1000000)
		return dp.getEdge(start,end,1000000);
	if(start == end)
	{	dp.addEdge(start,end,0);
		return 0;
	}
	for(int i=start;i<end;i++)
	{
		int temp = min(dp.getEdge(start,end,1000000), memoiz(start,i)+memoiz(i+1,end)+a.getElement(start-1)*a.getElement(i)*a.getElement(end));
		dp.addEdge(start,end,temp);
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
	cout<<memoiz(1,sz-1);
	//dp.display();
	
}
