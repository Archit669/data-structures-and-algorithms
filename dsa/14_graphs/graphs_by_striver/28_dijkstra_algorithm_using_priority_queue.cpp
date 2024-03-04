#include <bits/stdc++.h>
using namespace std;

// approach -1
class Dijkstra
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        vector<int> distance(V, INT_MAX);
        
        distance[S] = 0;
        pq.push({0,S});
        
        while (!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            int distNode = top.first;
            int vertex = top.second;
            
            for (auto &nei : adj[vertex]){
                int neiNode = nei[0];
                int neiWt = nei[1];
                
                if (distNode + neiWt < distance[neiNode]){
                    distance[neiNode] = distNode + neiWt;
                    pq.push({distance[neiNode], neiNode});
                }
            }
        }
        
        return distance;
    }
};


// approach -2 (using queue(inefficient))
// as we are pushing only node, so there is no significance of priority queue
class Dijkstra
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<int,vector<int>,greater<int> > pq;
        vector<int> distance(V, INT_MAX);
        
        distance[S] = 0;
        pq.push(S);
        
        while (!pq.empty()){
            auto vertex = pq.top();
            pq.pop();
            
            for (auto &nei : adj[vertex]){
                int neiNode = nei[0];
                int neiWt = nei[1];
                
                if (distance[vertex] + neiWt < distance[neiNode]){
                    distance[neiNode] = distance[vertex] + neiWt;
                    pq.push(neiNode);
                }
            }
        }
        
        return distance;
    }
};