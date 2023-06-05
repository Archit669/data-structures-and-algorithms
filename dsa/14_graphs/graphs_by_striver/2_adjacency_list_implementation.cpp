#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph{
    int vertices, edges;
    unordered_map<T, list<T> > adj;

    public:
        graph(int vertices, int edges){
            this->vertices = vertices;
            this->edges = edges;
        }

        void addEdge(T u , T v , bool direction = 0) {
            adj[u].push_back(v);
            if (direction == 0){
                adj[v].push_back(u);
            }
        }

        void printAdjList(){
            for (auto &i : adj){
                cout << i.first << "->";
                for (auto &j : i.second){
                    cout << j << ", ";
                }cout << endl;
            }
        }

        void createGraph(){
            cout << "enter edges of graph below: " << endl;
            for (int i = 0 ; i < edges ; i++){ 
                T u, v;
                int direction = 0;
                cin >> u >> v; 

                addEdge(u,v, direction);
            }
        }

};

int main(){
    graph<int> g(5,6);
    g.createGraph();
    g.printAdjList();
    return 0;
}