#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        int mod = (int)(1e9 + 7);

        vector<pair<long long,long long>> adj[n];
        for (int road  = 0; road < roads.size() ; road++){
            int u = roads[road][0];
            int v = roads[road][1];
            int wt = roads[road][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        priority_queue< pair<long long, long long> , vector<pair<long long,long long>> , greater<pair<long long,long long>> > pq;
        pq.push({0,0});

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        vector<long long> ways(n ,0);
        ways[0] = 1;


        while (!pq.empty()){
            auto top = pq.top();
            pq.pop();

            long distNode = top.first;
            long node = top.second;

            for (auto &nei : adj[node]){
                long long neiNode = nei.first;
                long long neiDist = nei.second;

                if (distNode + neiDist < dist[neiNode]){
                    dist[neiNode] = distNode + neiDist;
                    pq.push({dist[neiNode], neiNode});
                    ways[neiNode] = ways[node]%mod;
                }
                
                else if (distNode + neiDist == dist[neiNode]){
                    ways[neiNode] = (ways[neiNode]%mod + ways[node]%mod)%mod;
                }
            }
        }

        return (int)ways[n-1]%mod;
    }
};