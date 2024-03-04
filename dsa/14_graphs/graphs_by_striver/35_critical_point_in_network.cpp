#include <bits/stdc++.h>
using namespace std;

class Solution {
    int timer = 1;
    void dfs(int node , int parent, int n , vector<int> &vis, vector<int> adj[], int tin[], int low[], vector<vector<int>> &ans){
        vis[node]= 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto &nei : adj[node]){
            if (nei == parent){
                continue;
            }else if (!vis[nei]){
                dfs(nei, node, n , vis, adj, tin, low, ans);
                low[node] = min(low[node], low[nei]);
                if (low[nei] > tin[node]){
                    ans.push_back({nei, node});
                }
            }else{
                low[node] = min(low[node], low[nei]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (int edge = 0 ; edge < connections.size() ; edge++){
             int u = connections[edge][0];
             int v = connections[edge][1];
             adj[u].push_back(v);
             adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        int tin[n];
        int low[n];

        vector<vector<int>> ans;
        dfs(0,-1, n,vis,adj, tin, low, ans);
        return ans;
    }
};
