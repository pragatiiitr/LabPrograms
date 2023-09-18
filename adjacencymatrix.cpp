#include "header.h"

using namespace std;


template <class dataType>  GraphMatrix<dataType>::GraphMatrix(int sz, dataType element) {   
    size = sz;
    adj.CreateArray(size*size);
}

template <class dataType>  void GraphMatrix<dataType>::addEdge(int row, int col, dataType weight) {
	int index = row * size + col;
	if (row >= 0 && row < size && col >= 0 && col < size) {
    		adj.arr[index] = weight;
	}
}

template <class dataType>  int GraphMatrix<dataType>::getEdge(int row, int col,int defaultVal) {
	int index = row * size + col;
	if (row >= 0 && row < size && col >= 0 && col < size) {
	    return adj.getElement(index);
	}
	return defaultVal;
}

template <class dataType>  void GraphMatrix<dataType>::display() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << getEdge(i, j, NULL) << " ";
            }
            cout << endl;
        }
    }
//int main() {
//    int size, directed;
//    cout << "Enter the size of the matrix: ";
//    cin >> size;
//    int defaultVal;
//    cout<<"Enter default value"<<endl;
//    cin>>defaultVal;
//    GraphMatrix<int> graph(size,defaultVal);
//    cout<<"Enter 1 for directes graph and 0 for undirected graph"<<endl;
//    cin>>directed;
//    while (true) {
//        cout << "1. Add Edge\n2. Display \n3.Exit\n";
//        int option;
//        cin >> option;
//        switch (option) {
//            case 1:
//                cout << "Enter the source and destination of edge: ";
//                int src,dest,weight;
//                cin >>src>>dest>>weight;
//                graph.addEdge(src,dest,weight);
//                if(!directed)
//                graph.addEdge(dest,src,weight);
//                break;
//            case 2:
//                graph.display();
//                break;
//            case 3:
//                  exit(1);
//              default:
//                  cout << "Invalid choice. Try again." <<endl;
//        }
//   }
//    return 0;
//}
