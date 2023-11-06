#include "header.h"
#include "array.cpp"
#include "adjacencymatrix.cpp"
using namespace std;

int tabulation(int start1,int start2, string &s1, string &s2)
{
	Array<int> prev;
	Array<int> curr;
	prev.CreateArray(start1+1);
	prev.CreateArray(start1+1);
	for(int i=1;i<=start1;i++)
	{
		for(int j=1;j<=start1;j++)
		{
			if(s1[i-1] == s2[j-1])
			{
				int ans = prev.getElement(j-1) + 1;
				curr.arr[j] = ans;
			}
			else
			{
				int ans1 = prev.getElement(j);
				int ans2 = curr.getElement(j-1);
				curr.arr[j] = max(ans1,ans2);
			}
		}
		prev.arr = curr.arr;
	}
	return curr.getElement(start1);
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
	cout<<tabulation(n,n,s1,s2);
}
