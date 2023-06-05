#include <bits/stdc++.h>
using namespace std;

/**
 * the logic behind the problem is that use khan's algo
 * to find the topological sort.
 * if the no of vertices in topological sort is less than 
 * the actual no of vertices then cycle is present
 * as if cycle is present it is not possible to push all nodes
 * having indegree 0.
*/

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {

        int ans = 0;
        
        // create an indegree array that will store indegree
        // of each vertex
        vector<int> indegree(V,0);
        
        // create a queue for bfs traversal
        queue<int> que;

        // find indegree of each node
        for (int vertex = 0 ; vertex < V ; vertex++){
            for (auto &nei : adj[vertex]){
                indegree[nei]++;
            }
        }

        // push all the vertex with indegree 0 in queue
        for (int vertex = 0 ; vertex < V ; vertex++){
            if (indegree[vertex] == 0){
                que.push(vertex);
            }
        }

        // bfs traversal
        while (!que.empty()){

            int frontVertex = que.front();
            que.pop();

            ans++;

            for (auto &nei : adj[frontVertex]){

                indegree[nei]--;

                if (indegree[nei] == 0){
                    
                    que.push(nei);
                }
            }
        }

        return ans == V ? true : false;
    }
};