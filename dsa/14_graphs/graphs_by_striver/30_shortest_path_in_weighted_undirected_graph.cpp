#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<pair<int,int>> adj[n+1];
        for (int edge = 0 ; edge < edges.size() ;edge++){
            int u = edges[edge][0];
            int v = edges[edge][1];
            int wt = edges[edge][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, INT_MAX);
        dist[1] = 0;
        pq.push({0,1});
        
        vector<int> parent(n+1);
        for (int vertex =  0; vertex <= n ; vertex++){
            parent[vertex] = vertex;
        }
        
        while (!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            int vertex = top.second;
            int distVertex = top.first;
            
            
            for (auto &nei : adj[vertex]){
                int neiVertex = nei.first;
                int neiDist = nei.second;
                
                if (distVertex + neiDist < dist[neiVertex]){
                    dist[neiVertex] = distVertex + neiDist;
                    parent[neiVertex] = vertex;
                    pq.push({dist[neiVertex], neiVertex});
                }
            }
        }
        

        if (dist[n] == INT_MAX){
            return {-1};
        }

        vector<int> ans;
        ans.push_back(n);
        
        int vertex = n;
        while (parent[vertex] != vertex){
            ans.push_back(parent[vertex]);
            vertex = parent[vertex];
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};