#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int vertex, vector<int> adj[], int visited[], stack<int> &stk){
        visited[vertex] = 1;
        
        for (auto &nei : adj[vertex]){
            if (!visited[nei]){
                dfs(nei, adj, visited, stk);
            }
        }
        
        stk.push(vertex);
    }   
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int visited[V] = {0};
	    stack<int> stk;
	    
	    for (int vertex = 0 ; vertex < V ; vertex++){
	        if (!visited[vertex]){
	            dfs(vertex, adj, visited, stk);
	        }
	    }
	    
	    vector<int> ans;
	    
	    while (!stk.empty()){
	        ans.push_back(stk.top());
	        stk.pop();
	    }
	    

	    return ans;
	}
};
