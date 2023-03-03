#include <bits/stdc++.h>
using namespace std;

class triplet{
    public:
        int row;
        int col;
        int distance;
};


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size() , n = mat[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        queue<triplet> q;

        // insert all the zeros in queue along with their distance from themselves 
        for (int i = 0 ; i < mat.size() ; i++){
            for (int j = 0 ; j < mat[0].size() ; j++){
                if (mat[i][j] == 0){
                    visited[i][j] = 1;
                    q.push({i,j,0});
                }
            }
        }

        // function for bfs traversal
        auto bfs = [&](){
            while (!q.empty()){
                triplet front = q.front();
                q.pop();
                mat[front.row][front.col] = front.distance;
                vector<vector<int>> dir = {{1,0}, {-1,0}, {0,-1}, {0,1}};
                for (int direction = 0 ; direction < 4 ; direction++){
                    int new_x = front.row + dir[direction][0];
                    int new_y = front.col + dir[direction][1];
                    if (new_x < 0 || new_y < 0 || new_x >= m || new_y >=n || visited[new_x][new_y] == 1) {
                        continue;
                    }
                    q.push({new_x, new_y, front.distance+1});
                    visited[new_x][new_y] = 1;
                }
            }
        };

        // bfs function call
        bfs();

        // return distance
        return mat;
    }
};