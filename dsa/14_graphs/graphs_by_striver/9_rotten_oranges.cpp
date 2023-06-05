#include <bits/stdc++.h>
using namespace std;

// rotten oranges leetcode

// bfs solution

// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int fresh_count = 0;
//         queue<array<int, 3>> q;

//         // count all the fresh oranges and push all rotten oranges in queue with their time
//         for (int i = 0; i < grid.size() ; i++){
//             for (int j = 0 ; j < grid[0].size() ; j++){
//                 if (grid[i][j] == 2){
//                     q.push({i,j,0});
//                 }
//                 if (grid[i][j] == 1){
//                     fresh_count++;
//                 }

//             }
//         }

//         // fresh_count == 0 then time is 0
//         if (fresh_count == 0) return 0;

//         // create initial triplet
//         array<int,3> front_vertex = {-1,-1,-1};

//         // bfs traversal
//         while (!q.empty()){
//             front_vertex = q.front();
//             q.pop();

//             int i = front_vertex[0];
//             int j = front_vertex[1];
//             int time = front_vertex[2];

//             vector<pair<int,int>> v = {{1, 0} , {-1, 0}, {0, 1}, {0 , -1}};

//             for (int it = 0 ; it < 4 ; it++){
//                 int m = i+v[it].first;
//                 int n = j + v[it].second;

//                 if (m >= 0 && m < grid.size() && n >=0 && n < grid[0].size()
//                                                         && grid[m][n] == 1){
//                     q.push({m,n,time+1});
//                     grid[m][n] = 2;
//                     fresh_count--;
//                 }
//             }
//         }

//         return fresh_count == 0 ? front_vertex[2] : -1 ;
//     }
// };

// dfs solution

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        // update the time of fresh oranges using dfs in grid itself
        function<void(int, int, int)> dfs = [&](int i, int j, int time)
        {
            grid[i][j] = time;
            vector<vector<int>> dir = {{i + 1, j}, {i - 1, j}, {i, j - 1}, {i, j + 1}};

            for (int direction = 0; direction < 4; direction++)
            {
                int x = dir[direction][0];
                int y = dir[direction][1];

                if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] != 2)
                {
                    // dfs call for fresh mango or mango having time greater than current time
                    if (grid[x][y] == 1 ||  grid[x][y] > time )
                    {
                        dfs(x, y, time + 1);
                    }
                }
            }
        };

        // dfs for all rotten oranges
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    dfs(i, j, 2);
                }
            }
        }

        // find the maximum time
        int min_max_time = 2;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }

                min_max_time = max(min_max_time, grid[i][j]);
            }
        }

        return min_max_time - 2;
    }
};