#include <bits/stdc++.h>
using namespace std;

// leetcode dfs solution
class Solution {
    void dfs(pair<int, int> v, vector<vector<int>> &grid, int color, int src_num){
        int i = v.first, j = v.second;
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() 
                           || grid[i][j] != src_num || grid[i][j] == color)
            return;

        grid[i][j] = color;

        dfs({i, j + 1}, grid, color, src_num);
        dfs({i, j - 1}, grid, color, src_num);
        dfs({i + 1, j}, grid, color, src_num);
        dfs({i - 1, j}, grid, color, src_num);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int src_num = image[sr][sc];
        dfs({sr,sc}, image, color, src_num);
        return image;
    }
};

