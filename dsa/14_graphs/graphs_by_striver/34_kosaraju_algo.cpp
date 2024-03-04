#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int vertex , vector<int>&vis, vector<vector<int>>& adj, stack<int>&stk){
        vis[vertex] = 1;
        for (auto &nei : adj[vertex]){
            if (!vis[nei])
                dfs(nei, vis, adj, stk);
        }
        stk.push(vertex);
    }
    
    void dfs(int vertex , vector<int>&vis, vector<vector<int>>& adj){
        vis[vertex] = 1;
        for (auto &nei : adj[vertex]){
            if (!vis[nei])
                dfs(nei, vis, adj);
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // step1 : do the dfs and sort the edges acc to the finishing time
        vector<int> vis(V, 0);
        stack<int> stk;
        for (int vertex = 0 ; vertex < V ; vertex++){
            if (!vis[vertex])
                dfs(vertex, vis, adj, stk);
        }
        
        // step2 : reverse the graph
        vector<vector<int>> adjT(V);
        for (int vertex = 0 ; vertex < V; vertex++){
            vis[vertex] = 0;
            for (auto &nei : adj[vertex]){
                adjT[nei].push_back(vertex);
            }
        }
        
        // step3 : do the dfs according to finishing time
        int scc = 0;
        while (!stk.empty()){
            int vertex = stk.top();
            stk.pop();
            
            if (!vis[vertex]){
                dfs(vertex, vis, adjT);
                scc++;
            }
        }
        
        return scc;
    }
};