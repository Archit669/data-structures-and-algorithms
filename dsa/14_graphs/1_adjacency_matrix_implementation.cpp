#include <bits/stdc++.h>
using namespace std;

// adjacenty matrix implementation
class graph{
    int nodesCount, edgesCount;
    vector<vector<int>> adjMatrix;
    
    public: 
    // constructor that will takes no of nodes and no of edges of a graph
    graph(int nodesCount, int edgesCount){
        this->nodesCount = nodesCount;
        this->edgesCount = edgesCount;
        adjMatrix = vector<vector<int>> (nodesCount, vector<int>(edgesCount));
    }

    // function to add edge
    void addEdge(int firstVertex, int secondVertex, int weight = 1 ){
        // directed graph
        adjMatrix[firstVertex][secondVertex] = weight;
    }

    // print Adjacency lis
    void printAdjMatrix(){
        for (auto &vertexNeighbours : adjMatrix){
            for (auto &vertex : vertexNeighbours){
                cout << vertex << " ";
            }cout << endl;
        }
    }
};

int main(){
    // take number of vertices from user   
    int vertices;
    cout << "enter no of vertices: ";
    cin >> vertices;

    // create a graph g
    graph g(vertices, vertices);

    cout << "enter adjaceny Matrix below" << endl;
    for (int i = 0 ; i < vertices ; i++){
        for (int j = 0 ; j < vertices ; j++){
            int weight; cin >> weight;
            g.addEdge(i,j, weight);
        }

    }   

    cout << "adjacency matrix is " << endl;
    // printing graph
    g.printAdjMatrix();


    return 0;
}