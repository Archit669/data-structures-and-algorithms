#include <bits/stdc++.h>
using namespace std;

class Solution{
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, int tin[], int low[],
             vector<int> &mark, vector<int> adj[]) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            }
            else {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1) {
            mark[node] = 1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        int n = V;
        vector<int> vis(n, 0);

        int tin[n];
        int low[n];

        vector<int> mark(n, 0);
        dfs(0,-1,vis,tin, low, mark, adj);
        vector<int> ans;
        for (int node = 0 ; node < n ; node++){
            if (mark[node]){
                ans.push_back(node);
            }
        }
        if (ans.size() == 0) ans.push_back(-1);
        return ans;
    }
};