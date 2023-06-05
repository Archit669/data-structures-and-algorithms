#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// create an adjacency list
	unordered_map<int,vector<int>> adjList;

	for (int edge = 0 ; edge < edges.size() ; edge++){
		int u = edges[edge].first;
		int v = edges[edge].second;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	// queue for bfs
	queue<int> que;
	
	// visited array
	unordered_map<int,bool> visited;

	// parent array
	unordered_map<int,int> parent;

	que.push(s);
	visited[s] = true;
	parent[s] = -1;

	while (!que.empty()){

		int front = que.front();
		que.pop();

		for (auto &nei : adjList[front]){

			if (visited[nei] == true) continue;

			que.push(nei);
			visited[nei] = true;
			parent[nei] = front;

		}
	}

	vector<int> path;
	path.push_back(t);

	int vertex = t;

	while (parent[vertex] != -1){
		path.push_back(parent[vertex]);
		vertex = parent[vertex];
	}

	reverse(path.begin(), path.end());

	return path;
}
