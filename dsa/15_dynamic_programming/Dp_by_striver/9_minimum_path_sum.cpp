#include <bits/stdc++.h>
using namespace std;


// recursion + memoization

class Solution {
    int helper(vector<vector<int>>& grid, int sr , int sc, int dr, int dc, vector<vector<int>> &dp){
        if (sr == dr && sc == dc){
            return grid[sr][sc];
        }

        if (sr > dr || sc > dc) return INT_MAX/2;

        if (dp[sr][sc] != -1) {
            return dp[sr][sc];
        }

        int path1 = grid[sr][sc] + helper(grid, sr+1, sc, dr, dc, dp);
        int path2 = grid[sr][sc] + helper(grid, sr, sc+1, dr, dc, dp);

        return dp[sr][sc] = min(path1, path2);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(grid, 0 , 0 , m-1, n-1, dp);
    }
};

// tabulation

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int sr = m-1 ; sr >= 0 ; sr--){
            for (int sc = n-1 ; sc >= 0 ; sc--){
                if (sr == m-1 && sc == n-1){
                    dp[sr][sc] = grid[sr][sc];
                }else{
                    int path1 = INT_MAX;
                    int path2 = INT_MAX;

                    if (sr+1 < m){
                        path1 = grid[sr][sc] + dp[sr+1][sc];
                    }

                    if (sc+1 < n){
                        path2 = grid[sr][sc] + dp[sr][sc+1];
                    }

                     dp[sr][sc] = min(path1, path2);
                }
            }
        }

        return dp[0][0];
    }
};

// space optimization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> next(n, 0);
        for (int sr = m-1 ; sr >= 0 ; sr--){
            vector<int> curr(n, 0);
            for (int sc = n-1 ; sc >= 0 ; sc--){
                if (sr == m-1 && sc == n-1){
                    curr[sc] = grid[sr][sc];
                }else{
                    int path1 = INT_MAX;
                    int path2 = INT_MAX;

                    if (sr+1 < m){
                        path1 = grid[sr][sc] + next[sc];
                    }

                    if (sc+1 < n){
                        path2 = grid[sr][sc] + curr[sc+1];
                    }

                    curr[sc] = min(path1, path2);
                }
            }

            next = move(curr);
        }

        return next[0];
    }
};