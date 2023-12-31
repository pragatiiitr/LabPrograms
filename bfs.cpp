#include "adjacencymatrix.cpp"
#include "queueArray.cpp"
#include "array.cpp"
#include "header.h"


using namespace std;
void bfs(int start,int size, GraphMatrix<int> &graph)
{
	queue<int> q;
	Array<int> vis;
	vis.CreateArray(size);
	q.create(size);
	q.enqueue(start);
	vis.arr[start] = 1;
	while(!q.IsEmpty())
	{
		int temp = q.rear();
		q.dequeue();
		cout<<temp<<"-->";
		for(int index=0;index<size;index++)
		{
			int element = index;
			if(!vis.arr[index] and graph.getEdge(temp, element, 0) == 1)
			{
				vis.arr[index] = 1;
				q.enqueue(element);
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
   bfs(start,size,graph);
   return 0;
}
