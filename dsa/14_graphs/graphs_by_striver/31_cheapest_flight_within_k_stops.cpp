#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (int edge = 0 ; edge < flights.size(); edge++){
            int u = flights[edge][0];
            int v = flights[edge][1];
            int wt = flights[edge][2];
            adj[u].push_back({v,wt});
        }

        // {steps, vertex ,cost}
        queue< array<int,3>> pq;
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;


        pq.push({0,src,0});

        while (!pq.empty()){
            auto [steps, vertex, cost] = pq.front();  
            pq.pop();

            if (steps > k){
                continue;
            }


            for (auto &nei : adj[vertex]){
        
                int neiNode = nei.first;
                int neiCost = nei.second;

                if (neiCost + cost < dist[neiNode]){
                    dist[neiNode] = neiCost + cost;
                    pq.push({steps+1, neiNode, dist[neiNode]});
                }
            }
        }


        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};