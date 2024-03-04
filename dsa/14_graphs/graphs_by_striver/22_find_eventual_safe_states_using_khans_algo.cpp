//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> outdegree(V);
        for (int vertex = 0 ; vertex < V ; vertex++){
            for (auto &nei : adj[vertex]){
                outdegree[vertex]++;
            }
        }
        
        vector<int> adjList[V];
        for (int vertex = 0 ; vertex < V ; vertex++){
            for (auto &nei : adj[vertex]){
                adjList[nei].push_back(vertex);
            }
        }
        
        queue<int> q;
        for (int vertex = 0 ; vertex < V ; vertex++){
            if (outdegree[vertex] == 0){
                q.push(vertex);
            }
        }
        
        vector<int> safeNodes;
        while (!q.empty()){
            int front = q.front();
            q.pop();
            
            safeNodes.push_back(front);
            
            for (auto &nei : adjList[front]){
                outdegree[nei]--;
                if (outdegree[nei] == 0)
                    q.push(nei);
            }
        }
        
        sort(safeNodes.begin(), safeNodes.end());
        
        return safeNodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends