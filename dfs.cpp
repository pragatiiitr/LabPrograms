#include "header.h"
#include "adjacencymatrix.cpp"
#include "stackArray.cpp"
#include <iostream> 

void dfs(int start,int size, GraphMatrix<int> &graph)
{
	Stack<int> s;
	Array<int> vis;
	vis.CreateArray(size);
	s.create(size);
	s.push(start);
	while(s.len)
	{
		int temp = s.peek();
		s.pop();
		cout<<temp<<"-->";
		vis.arr[temp] = 1;
		for(int index=0;index<size;index++)
		{
			int element = index;
			if(!vis.arr[index] and graph.getEdge(temp, element, NULL) == 1)
			{
				s.push(element);
				//cout<<"top "<<q.top()<<endl;
			}
		}
	}
}
int main() {
    int size, directed;
    cout << "Enter the size of the matrix: ";
    cin >> size;
    int defaultVal;
    cout<<"Enter default value"<<endl;
    cin>>defaultVal;
    GraphMatrix<int> graph(size,defaultVal);
    cout<<"Enter 1 for directed graph and 0 for undirected graph"<<endl;
    cin>>directed;
    bool flag = true;
    while (flag) {
        cout << "1. Add Edge\n2. Display \n3.Exit\n";
        int option;
        cin >> option;
        switch (option) {
            case 1:
                cout << "Enter the source and destination of edge: ";
                int src,dest,weight;
                cin >>src>>dest>>weight;
                graph.addEdge(src,dest,weight);
                if(!directed)
                graph.addEdge(dest,src,weight);
                break;
            case 2:
                graph.display();
                break;
            case 3:
            	  flag = false;
                  break;
              default:
                  cout << "Invalid choice. Try again." <<endl;
        }
   }
   int start;
   cout<<"Enter the starting element"<<endl;
   cin>>start;
   dfs(start,size,graph);
   return 0;
}
