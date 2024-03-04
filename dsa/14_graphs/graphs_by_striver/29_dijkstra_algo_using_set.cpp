#include <bits/stdc++.h>
using namespace std;

class Dijkstra
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>> st;
        st.insert({0,S});
    
        vector<int> dist(V,INT_MAX);
        dist[S] = 0;
        
        while (st.size() > 0){
            
            auto it = *st.begin();
            st.erase(it);
            int distNode = it.first;
            int vertex = it.second;
            
            for (auto &nei : adj[vertex]){
                int neiNode = nei[0];
                int neiDist = nei[1];
                
                if (distNode + neiDist < dist[neiNode]){
                    if (dist[neiNode] == INT_MAX){
                        st.erase({dist[neiNode], neiNode});
                    }
                    
                    dist[neiNode] = distNode + neiDist;
                    st.insert({dist[neiNode], neiNode});
                }
            }
        }
        
        return dist;
    }
};