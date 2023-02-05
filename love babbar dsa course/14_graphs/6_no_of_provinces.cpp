#include <bits/stdc++.h>
using namespace std;

// bfs solution

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res = 0;
        vector<int> visited(isConnected.size());
        
        auto bfs = [&](int curr_vertex){
            queue<int> q;
            q.push(curr_vertex);
            visited[curr_vertex] = true;
            while (!q.empty()){
                int front_vertex = q.front();
                q.pop();

                for (int i = 0 ; i < isConnected[front_vertex].size() ; i++){
                    if (isConnected[front_vertex][i] && !visited[i]){
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
        };

        for (int i = 0 ; i < isConnected.size() ; i++){
            if (!visited[i]){
                bfs(i);
                res++;
            }
        }

        return res;

    }
};

// dfs solution
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res = 0;
        vector<int> visited(isConnected.size());

        function<void(int)> dfs = [&](int curr_vertex){
            visited[curr_vertex] = true;
            for (int i = 0 ; i < isConnected[curr_vertex].size() ; i++){
                if (isConnected[curr_vertex][i] && !visited[i]){
                    dfs(i);
                }
            }
        };
        
        for (int i = 0 ; i < isConnected.size() ; i++){
            if (!visited[i]){
                dfs(i);
                res++;
            }
        }

        return res;
    }
};