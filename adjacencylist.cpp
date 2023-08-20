#include "linkedlist.cpp"
#include<bits/stdc++.h>
const int sizeList = 100;
template < typename dataType> class Graph{
	public:
		int numVertices;
		LinkedList<dataType> adj[sizeList];
		Graph()
		{
			numVertices = 0;
		}
		void vertex(int V)
		{
			numVertices = V;
		}
		void addEdge(dataType src,dataType dest,int direction)
		{
			adj[src].insert(dest,1);
			if(!direction)
			adj[dest].insert(src,1);
		}
		void Display()
		{
			for(int i=0;i<numVertices;i++)
			{
				cout<<i<<"->";
				adj[i].displayList();
			}
		}
};
int main()
{
	Graph<int> graph;
	int vertices = 0;
	bool directed = false;
	cout<<"Enter the number of vertices"<<endl;
	cin>>vertices;
	graph.vertex(vertices);
	cout<<"Enter 1 for directes graph and 0 for undirected graph"<<endl;
	cin>>directed;
	while (true) {
        cout << "1. Add Edge\n2. Display \n3.Exit\n";
        int option;
        cin >> option;
        switch (option) {
            case 1:
                cout << "Enter the source and destination of edge: ";
                int src,dest;
                cin >>src>>dest;
                graph.addEdge(src,dest,directed);
                break;
            case 2:
                graph.Display();
                break;
            case 3:
                  exit(1);
              default:
                  cout << "Invalid choice. Try again." <<endl;
        }
    }
}
