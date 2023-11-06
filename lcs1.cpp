#include "header.h"
#include "array.cpp"
#include "adjacencymatrix.cpp"
using namespace std;

GraphMatrix<int> dp;
int memoization(int start1,int start2, string &s1, string &s2)
{
	if(start1 == 0 or start2 == 0)
	{	dp.addEdge(start1,start2,0);
		return 0;
	}
	else if(s1[start1 -1] == s2[start2 - 1])
	{
		int ans = memoization(start1-1,start2-1,s1,s2) + 1;
		if(dp.getEdge(start1,start2,-1) < ans)
			dp.addEdge(start1,start2,ans);
	}
	else
	{
		int ans1 = memoization(start1-1,start2,s1,s2);
		int ans2 = memoization(start1,start2-1,s1,s2);
		if(dp.getEdge(start1,start2,-1) < max(ans1,ans2))
		{dp.addEdge(start1,start2,max(ans1,ans2));}
	}
	
	return dp.getEdge(start1,start2,-1);
}
int main()
{
	cout<<"Enter 1st strings"<<endl;
	string s1,s2;
	cin>>s1;
	cout<<"Enter 2nd string"<<endl;
	cin>>s2;
	cout<<"Enter the size of string"<<endl;
	int n;
	cin>>n;
	dp = GraphMatrix<int> (n+1,-1);
	cout<<memoization(n,n,s1,s2);
}
