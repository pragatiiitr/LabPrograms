#include "header.h"
#include "array.cpp"
#include "adjacencymatrix.cpp"
using namespace std;

GraphMatrix<int> dp;
int tabulation(int start1,int start2, string &s1, string &s2)
{
	for(int i=0;i<=start1;i++)
	{
		dp.addEdge(i,0,0);
		dp.addEdge(0,i,0);
	}
	for(int i=1;i<=start1;i++)
	{
		for(int j=1;j<=start1;j++)
		{
			if(s1[i-1] == s2[j-1])
			{
				int ans = dp.getEdge(i-1,j-1,0) + 1;
				dp.addEdge(i,j,ans);
			}
			else
			{
				int ans1 = dp.getEdge(i-1,j,0);
				int ans2 = dp.getEdge(i,j-1,0);
				dp.addEdge(i,j,max(ans1,ans2));
			}
		}
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
	cout<<tabulation(n,n,s1,s2);
}
