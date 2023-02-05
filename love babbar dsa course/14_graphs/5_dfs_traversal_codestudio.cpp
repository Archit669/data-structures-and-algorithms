#include <bits/stdc++.h>
using namespace std;


vector <set<int> > getAdjacency(int n, int m, vector<vector<int>> & edges) {
    vector<set<int>> adj(n);

    for (int edge = 0 ; edge < m ; edge++){
        int u = edges[edge][0];
        int v = edges[edge][1];
        adj[u].insert(v);
        adj[v].insert(u);
    }

    return adj;
}

void dfs(vector<set<int>> &adj , vector<int> &visited, int currVertex, vector<int> &ans){
   
    visited[currVertex] = true;

    for (auto &x : adj[currVertex]){
        if (!visited[x])
            dfs(adj, visited, x,  ans);
    }

    ans.push_back(currVertex);

}

vector<vector<int>> depthFirstSearch(int vertex, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> res;
    vector<int> visited(vertex);

    vector<set<int>> adj = getAdjacency(vertex, edges.size() , edges);

    for (int i = 0 ; i < vertex ; i++){
        if (!visited[i]){
            vector<int> ans;
            dfs(adj, visited,i, ans);
            res.push_back(ans);
        }

    }
    
    return res;
}