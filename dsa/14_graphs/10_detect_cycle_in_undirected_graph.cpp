// using dfs

// //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// // } Driver Code Ends
// class Solution {
//     bool dfs(int src, int V, vector<int> adj[], vector<int> &visited, unordered_map<int,int> &parent){
//         visited[src] = 1;
        
//         bool ans = false;
        
//         for (auto &adjVertex : adj[src]){
//             if (visited[adjVertex] && adjVertex != parent[src]){
//                 return true;
//             }
            
//             if (!visited[adjVertex] ){
//                 parent[adjVertex] = src;
//                 ans |= dfs(adjVertex, V, adj, visited, parent);
//                 if (ans) return true;
//             }
//         }
        
//         return ans;
//     }
    
//   public:
//     // Function to detect cycle in an undirected graph.
//     bool isCycle(int V, vector<int> adj[]) {
//         unordered_map<int,int>parent;
//         bool ans = false;
//         vector<int> visited(V);
//         for (int vertex = 0 ; vertex < V ; vertex++){
//             if (!visited[vertex]){
//                 parent[vertex] = -1;
//                 ans |= dfs(vertex, V, adj, visited, parent);
//                 if (ans == true) return true;
//             }
//         }
//         return ans;
//     }
// };

// //{ Driver Code Starts.
// int main() {
//     int tc;
//     cin >> tc;
//     while (tc--) {
//         int V, E;
//         cin >> V >> E;
//         vector<int> adj[V];
//         for (int i = 0; i < E; i++) {
//             int u, v;
//             cin >> u >> v;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         Solution obj;
//         bool ans = obj.isCycle(V, adj);
//         if (ans)
//             cout << "1\n";
//         else
//             cout << "0\n";
//     }
//     return 0;
// }
// // } Driver Code Ends



// using bfs

class Solution {
    bool bfs(int src, int V, vector<int> adj[], vector<int> &visited){
        queue<int> q;
        q.push(src);
        visited[src] = 1;
        
        unordered_map<int,int> parent;
        parent[src] = -1;
        
        bool ans = false;
        
        while (!q.empty()){
            int front_vertex = q.front();
            q.pop();
 
            for (auto &adjVertex : adj[front_vertex]){
                
                if (visited[adjVertex] && adjVertex != parent[front_vertex]){
                    return true;
                }
                
                if (!visited[adjVertex] ){
                    visited[adjVertex] = 1;
                    q.push(adjVertex);
                    parent[adjVertex] = front_vertex;
                }
                
            }
        }
        
        return ans;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        bool ans = false;
        vector<int> visited(V);
        for (int vertex = 0 ; vertex < V ; vertex++){
            if (!visited[vertex]){
                ans |= bfs(vertex, V, adj, visited);
                if (ans) return true;
            }
        }
        return ans;
    }
};