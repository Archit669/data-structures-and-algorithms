#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V);
	    
	    for (int vertex = 0 ; vertex < V ; vertex++){
	        for (auto &nei : adj[vertex]){
	            indegree[nei]++;
	        }
	    }
	    
	    queue<int> que;
	    for (int vertex = 0 ; vertex < V ; vertex++){
	        if (indegree[vertex] == 0){
	            que.push(vertex);
	        }
	    }
	    
	    vector<int> ans;
	    
	    while (!que.empty()){
	        int front = que.front();
	        ans.push_back(front);
	        que.pop();
	        
	        for (auto &nei : adj[front]){
	            indegree[nei]--;
	            if (indegree[nei] == 0){
	                que.push(nei);
	            }
	        }
	    }
	    
	    return ans;
	}
};