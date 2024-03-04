#include <bits/stdc++.h>
using namespace std;


class Solution {
    bool checkDfs(int vertex, vector<int> adj[], int vis[], int pathVis[]){
        vis[vertex] = 1;
        pathVis[vertex] = 1;
        
        for (int &nei : adj[vertex]){
            if (!vis[nei]){
                if (checkDfs(nei, adj, vis, pathVis) == true){
                    return true;
                }
            }else{
                if (pathVis[nei]){
                    return true;
                }
            }
        }
        
        pathVis[vertex] = 0;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};
        
        for (int vertex = 0 ; vertex < V ; vertex++){
            if (!vis[vertex]){
                if (checkDfs(vertex, adj, vis, pathVis)){
                    return true;
                }
            }
        }
        
        return false;
    }
};


// using only visited array
class Solution {
    bool checkDfs(int vertex, vector<int> adj[], int vis[], int pathVis[]){
        vis[vertex] = 1;
        pathVis[vertex] = 1;
        
        for (int &nei : adj[vertex]){
            if (!vis[nei]){
                if (checkDfs(nei, adj, vis, pathVis) == true){
                    return true;
                }
            }else{
                if (pathVis[nei]){
                    return true;
                }
            }
        }
        
        pathVis[vertex] = 0;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};
        
        for (int vertex = 0 ; vertex < V ; vertex++){
            if (!vis[vertex]){
                if (checkDfs(vertex, adj, vis, pathVis)){
                    return true;
                }
            }
        }
        
        return false;
    }
};