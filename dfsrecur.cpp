#include "header.h"
#include "adjacencymatrix.cpp"
#include <iostream> 

Array<int> vis;
void dfs(int start,int size, GraphMatrix<int> &graph)
{

	
	vis.arr[start] = 1;
	for(int index=0;index<size;index++)
	{
		int element = index;
		if(!vis.arr[index] and graph.getEdge(start, element, NULL) == 1)
		{
			cout<<element<<"-->";
			dfs(element, size, graph);
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
