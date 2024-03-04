//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    
    void dfs(int vertex, int visited[], stack<int> &stk, vector<pair<int,int>> adj[]){
        visited[vertex] = true;
        for (auto &nei : adj[vertex]){
            int neiNode = nei.first;
            if (!visited[neiNode]){
                dfs(neiNode, visited, stk, adj);
            }
        }
        
        stk.push(vertex);
    }
    
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        // step1: create an adjacency list
        vector<pair<int,int>> adj[N];
        for (int edge = 0 ; edge < edges.size(); edge++){
            int u = edges[edge][0];
            int v = edges[edge][1];
            int wt = edges[edge][2];
            adj[u].push_back({v, wt});
        }
        
        // step2 : do a topological sort
        stack<int> stk;
        int visited[N] = {0};
        for (int vertex = 0 ; vertex < N ; vertex++){
            if (!visited[vertex]){
                dfs(vertex , visited, stk, adj);
            }
        }
        
        // step3 : take out the nodes out of the stack one by one 
        // and relax the edges
        
        while (stk.top() != 0){
            stk.pop();
        }
        
        vector<int> dist(N,INT_MAX);
        dist[0] = 0;
    
        while (!stk.empty()){
            int vertex = stk.top();
            stk.pop();
            
            for (auto &nei : adj[vertex]){
                int neiNode = nei.first;
                int neiNodeWt = nei.second;
                
                if (dist[vertex] + neiNodeWt < dist[neiNode]){
                    dist[neiNode] = dist[vertex] + neiNodeWt;
                }
            }
        }
        
        for (int vertex = 0 ; vertex < N ; vertex++){
            if (dist[vertex] == INT_MAX){
                dist[vertex] = -1;
            }
        }
        
        return dist;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends