#include "adjacencymatrix.cpp"
#include "queueArray.cpp"
#include <iostream> 

int main()
{
	cout<<"Hello"<<endl;
	return 0;
}
/*void bfs(dataType start)
{
	queue<int> q;
	Array<int> vis;
	vis.createArray(size);
	q.enqueue(start);
	vis.arr[start] = 1;
	cout<<start;
	while(!q.len)
	{
		int temp = q.top();
		q.dequeue();
		cout<<"->"<<temp;
		int index = temp*size;
		for(int i=index;i<index+size;i++)
		{
			int element = i - index;
			if(!vis.arr[element])
			{
				vis.arr[element] = 1;
				q.enqueue(element);
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
   bfs(start);
   return 0;
}*/
