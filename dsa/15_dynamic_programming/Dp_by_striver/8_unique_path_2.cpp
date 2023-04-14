#include <bits/stdc++.h>
using namespace std;

// recursion + memoization
class Solution {
    int helper(int sr, int sc, int dr, int dc, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){

        if (sr > dr || sc > dc || sc < 0 || sr < 0 || obstacleGrid[sr][sc] == 1){
            return 0;
        }

        if (sr == dr && sc == dc){
            return 1;
        }

        if (dp[sr][sc] != -1){
            return dp[sr][sc];
        }

        int path1 = helper(sr+1, sc, dr ,dc , obstacleGrid, dp);
        int path2 = helper(sr, sc+1, dr, dc, obstacleGrid, dp);

        return dp[sr][sc] = path1 + path2;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(0, 0 , m-1 , n-1, obstacleGrid, dp);
    }
};

// tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<long>> dp(m, vector<long>(n));

        for (int sr = m-1 ; sr >= 0 ; sr--){
            for (int sc = n-1 ; sc >= 0 ; sc--){
                if (sr == m-1 && sc == n-1 && obstacleGrid[sr][sc] != 1){
                    dp[sr][sc] = 1;
                }else{
                    int path1 = 0 , path2 = 0;

                    if (sr+1 <=  m-1 && obstacleGrid[sr][sc] != 1) path1 += dp[sr+1][sc];
                    if (sc+1 <= n-1 && obstacleGrid[sr][sc] != 1)   path2 += dp[sr][sc+1];
 
                    dp[sr][sc] = long(path1) + path2;
                }
            }
        }

        return dp[0][0];
    }
};


// space optimization
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<long> next(n);

        for (int sr = m-1 ; sr >= 0 ; sr--){
            
            vector<long> curr(n);
            for (int sc = n-1 ; sc >= 0 ; sc--){
                if (sr == m-1 && sc == n-1 && obstacleGrid[sr][sc] != 1){

                    curr[sc] = 1;
                }else{

                    if (sr+1 <=  m-1 && obstacleGrid[sr][sc] != 1) curr[sc] += next[sc];
                    if (sc+1 <= n-1 && obstacleGrid[sr][sc] != 1) curr[sc] += curr[sc+1];
                }
            }

            next = move(curr);
        }

        return next[0];
    }
};