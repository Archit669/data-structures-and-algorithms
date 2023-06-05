#include <bits/stdc++.h> 
using namespace std;

void dfs(int vertex, vector<bool> &visited, stack<int> &stk, vector<vector<int>> &adjList){
    visited[vertex] = true;

    for (auto &nei : adjList[vertex]){

        if (!visited[nei])
            dfs(nei, visited, stk, adjList);
    }

    stk.push(vertex);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    // create an adjacency list
    vector<vector<int>>  adjList(v);
    for (auto &edge : edges){

        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);
    }

    // create visited array
    vector<bool> visited(v,false);

    // create a stack
    stack<int> stk;

    // traverse each vertex
    for(int vertex = 0; vertex < v ; vertex++){

        if (visited[vertex] == false){
            dfs(vertex, visited, stk, adjList);
        }
    }

    // create a vector to store the topological sort
    vector<int> topoSort;

    while (stk.empty() == false){

        topoSort.push_back(stk.top());

        stk.pop();
    }

    return topoSort;
}