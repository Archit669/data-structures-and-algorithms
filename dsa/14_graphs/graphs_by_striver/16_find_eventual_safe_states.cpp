#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();

        vector<int> vis(V);
        vector<int> pathVis(V);
        vector<int> check(V);

        function<bool(int)> checkDfs = [&](int vertex){

            vis[vertex] = 1;
            pathVis[vertex] = 1;
            check[vertex] = 0;

            for (auto &nei : graph[vertex]){
                
                if (vis[nei] == 0){
                    if (checkDfs(nei) == true){
                        check[vertex] = 0;
                        return true;
                    }
                }else{
                    if (pathVis[nei] == 1){
                        check[vertex] = 0;
                        return true;
                    }
                }
            }

            pathVis[vertex] = 0;
            check[vertex] = 1;
            
            return false;
        };

        for (int vertex = 0 ; vertex < V ; vertex++){
            if (!vis[vertex]){
                checkDfs(vertex);
            }
        }

        vector<int> safeNodes;

        for (int vertex =  0; vertex < V ; vertex++){
            if (check[vertex]){
                safeNodes.push_back(vertex);
            }
        }

        return safeNodes;
    }
};