#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        // create an adjacenecy list
        vector<int> adj[N];
        for (int edge = 0 ; edge < M ; edge++){
            int u = edges[edge][0];
            int v = edges[edge][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> dist(N, INT_MAX);
        dist[src] = 0;
        
        queue<int> q;
        q.push(src);
        
        while (!q.empty()){
            
            int front = q.front();
            q.pop();
            
            for (auto &nei : adj[front]){
                if (dist[front] + 1 < dist[nei]){
                    dist[nei] = dist[front] + 1;
                    q.push(nei);
                }
            }
        }
        
        for (int vertex = 0 ; vertex < N; vertex++){
            if (dist[vertex] == INT_MAX) dist[vertex] = -1;
        }
        
        return dist;
    }
};