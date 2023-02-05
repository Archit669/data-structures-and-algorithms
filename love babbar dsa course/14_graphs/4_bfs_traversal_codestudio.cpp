#include <bits/stdc++.h> 
using namespace std;

vector <set<int> > getAdjacency(int n, int m, vector < pair < int, int >> & edges) {
    vector<set<int>> adj(n);

    for (int edge = 0 ; edge < m ; edge++){
        int u = edges[edge].first;
        int v = edges[edge].second;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    return adj;
}

void bfs(vector<set<int>> &adj , vector<int> &visited, queue<int> &que, int currVertex, vector<int> &ans){
    que.push(currVertex);
    visited[currVertex] = true;
    while (!que.empty()){
        int v = que.front();
        ans.push_back(v);
        que.pop();

        for (auto &x : adj[v]){
            if (!visited[x]){
                que.push(x);
                visited[x] = true;
            }
        }
    }

}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> ans;
    vector<int> visited(vertex);
    queue<int> que;

    vector<set<int>> adj = getAdjacency(vertex, edges.size() , edges);

    for (int i = 0 ; i < vertex ; i++){
        if (!visited[i])
            bfs(adj, visited, que, i, ans);
    }
    
    return ans;
}