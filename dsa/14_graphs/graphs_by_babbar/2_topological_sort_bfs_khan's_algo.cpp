#include <bits/stdc++.h> 
using namespace std;

void bfs(queue<int> &que, vector<vector<int>> &adjList, vector<int> &indegree, vector<int> &topoSort)
{
    while (!que.empty()){

        // step1 -> take the vertex from queue
        int front = que.front();

        // step2 -> remove the vertex from queue
        que.pop();

        // step3 -> push the node in 
        topoSort.push_back(front);

        // step4 -> decrease the indegree of all neighbours by 1
        for (auto &nei : adjList[front]){

            indegree[nei]--;

            if (indegree[nei] == 0){

                que.push(nei);
            }
        }
    }
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    // create an array to store indegree of each node
    vector<int> indegree(v);
    
    // create an adjacency list
    vector<vector<int>> adjList(v);
    
    for (auto &edge : edges){
        
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);

        // u is directed towards v so we can increment the indegree of vertex v
        indegree[v]++;
    }

    // create an queue for bfs 
    queue<int> que;

    // push all the vetex in queue having indegree 0
    for (int vertex = 0 ; vertex < v ; vertex++){
        
        if (indegree[vertex] == 0){

            que.push(vertex);
        }
    }

    // create array to store topological sort
    vector<int> topoSort;

    // bfs traversal
    bfs(que, adjList, indegree, topoSort);

    return topoSort;
}