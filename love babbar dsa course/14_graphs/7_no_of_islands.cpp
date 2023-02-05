#include <bits/stdc++.h>
using namespace std;

// gfg dfs solution
class Solution
{
    void dfs(pair<int, int> v, vector<vector<bool>> &visited, vector<vector<char>> &grid)
    {
        int row = v.first, col = v.second;
        visited[row][col] = true;
        for (int i = row - 1; i <= row + 1; i++)
        {
            for (int j = col - 1; j <= col + 1; j++)
            {
                if (i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size())
                {
                    if (!visited[i][j] && grid[i][j] == '1')
                    {
                        dfs({i, j}, visited, grid);
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    dfs({i, j}, visited, grid);
                    res++;
                }
            }
        }

        return res;
    }
};

// leetcode dfs solution
class Solution
{
    void dfs(pair<int, int> v, vector<vector<char>> &grid)
    {
        int i = v.first, j = v.second;
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0')
            return;

        grid[i][j] = '0';

        dfs({i, j + 1}, grid);
        dfs({i, j - 1}, grid);
        dfs({i + 1, j}, grid);
        dfs({i - 1, j}, grid);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs({i, j}, grid);
                    res++;
                }
            }
        }

        return res;
    }
};