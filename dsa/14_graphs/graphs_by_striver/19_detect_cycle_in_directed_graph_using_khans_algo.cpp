#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
         vector<int> indegree(V);
         for (int vertex = 0; vertex < V ; vertex++){
             for (auto &nei : adj[vertex]){
                 indegree[nei]++;
             }
         }
         
         queue<int> q;
         for (int vertex = 0 ; vertex < V ; vertex++){
             if (indegree[vertex] == 0){
                 q.push(vertex);
             }
         }
         
         int count = 0;
         
         while (!q.empty()){
             int front = q.front();
             q.pop();
             
             count++;
             
             for (auto &nei : adj[front]){
                 indegree[nei]--;
                 if (indegree[nei] == 0){
                     q.push(nei);
                 }
             }
         }
         
         return (count == V) ? false : true;
    }
};