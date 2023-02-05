#include <bits/stdc++.h>
using namespace std;


vector <vector<int> > printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<vector<int>> adj(n);
    
    for (int vertex = 0 ; vertex < adj.size() ; vertex++){
        adj[vertex].push_back(vertex);
    }

    for (int edge = 0 ; edge < m ; edge++){
        int u = edges[edge][0];
        int v = edges[edge][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return adj;
}