#include <bits/stdc++.h>
using namespace std;

// recursion
class Solution {
    int solve(vector<vector<int>>& grid, int row, int col1, int col2){

        if (col1 < 0 || col2 < 0 || col1 >= grid[0].size() || col2 >= grid[0].size()){
            return 0;
        }

        if (row == grid.size()-1){
            if (col1 == col2) return grid[row][col1];
            else return grid[row][col1] + grid[row][col2];
        }

        vector<int> dir = {-1, 0 , 1};

        int ans = INT_MIN;

        for (int i = 0 ; i < dir.size(); i++){
            for (int j = 0 ; j < dir.size() ; j++){
                int new_col1 = col1 + dir[i];
                int new_col2 = col2 + dir[j];
                if (col1 == col2) ans = max(ans, grid[row][col1] + solve(grid, row+1, new_col1, new_col2));
                else ans = max(ans, grid[row][col1] + grid[row][col2] + solve(grid, row+1, new_col1, new_col2));
            }
        }

        return ans;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        return solve(grid, 0 , 0, grid[0].size()-1);
    }
};

// memoization
class Solution {
    int dp[100][100][100];
    int solve(vector<vector<int>>& grid, int row, int col1, int col2){

        if (col1 < 0 || col2 < 0 || col1 >= grid[0].size() || col2 >= grid[0].size()){
            return 0;
        }

        if (row == grid.size()-1){
            if (col1 == col2) return grid[row][col1];
            else return grid[row][col1] + grid[row][col2];
        }

        if (dp[row][col1][col2] != -1){
            return dp[row][col1][col2];
        }

        vector<int> dir = {-1, 0 , 1};

        int ans = INT_MIN;

        for (int i = 0 ; i < dir.size(); i++){
            for (int j = 0 ; j < dir.size() ; j++){
                int new_col1 = col1 + dir[i];
                int new_col2 = col2 + dir[j];
                if (col1 == col2) ans = max(ans, grid[row][col1] + solve(grid, row+1, new_col1, new_col2));
                else ans = max(ans, grid[row][col1] + grid[row][col2] + solve(grid, row+1, new_col1, new_col2));
            }
        }

        return dp[row][col1][col2] = ans;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1 , sizeof(dp));
        return solve(grid, 0 , 0, grid[0].size()-1);
    }
};

// tabulation
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dp[m][n][n];
        memset(dp, -1 , sizeof(dp));

        vector<int> dir = {-1, 0 , 1};

        for (int col1 = 0 ; col1 < n ; col1++){
            for (int col2 = 0 ; col2 < n ; col2++){
                if (col1 == col2){
                    dp[m-1][col1][col2] = grid[m-1][col1];
                }else{
                    dp[m-1][col1][col2] = grid[m-1][col1] + grid[m-1][col2];
                }
            }
        }

        for (int row = m-2 ; row >= 0 ; row--){
            for (int col1 = 0 ; col1 < n ; col1++){
                for (int col2 = 0 ; col2 < n ; col2++){
                    int ans = INT_MIN;

                    for (int i = 0 ; i < dir.size(); i++){
                        for (int j = 0 ; j < dir.size() ; j++){
                            int new_col1 = col1 + dir[i];
                            int new_col2 = col2 + dir[j];

                            if (new_col1 < 0 || new_col2 < 0 
                                        || new_col1 >= grid[0].size() || new_col2 >= grid[0].size()){
                                continue;
                            }

                            if (col1 == col2) 
                                ans = max(ans, grid[row][col1] + dp[row+1][new_col1][new_col2]);
                            else 
                                ans = max(ans, grid[row][col1] + grid[row][col2] + dp[row+1][new_col1][new_col2]);
                        }
                    }

                    dp[row][col1][col2] = ans;

                }
            }
        }

        return dp[0][0][n-1];   
    }
};

// space optimization
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> next(n, vector<int>(n));

        vector<int> dir = {-1, 0 , 1};

        for (int col1 = 0 ; col1 < n ; col1++){
            for (int col2 = 0 ; col2 < n ; col2++){
                if (col1 == col2){
                    next[col1][col2] = grid[m-1][col1];
                }else{
                    next[col1][col2] = grid[m-1][col1] + grid[m-1][col2];
                }
            }
        }

        for (int row = m-2 ; row >= 0 ; row--){
            vector<vector<int>> curr(n, vector<int>(n));
            for (int col1 = 0 ; col1 < n ; col1++){
                for (int col2 = 0 ; col2 < n ; col2++){

                    int ans = INT_MIN;

                    for (int i = 0 ; i < dir.size(); i++){
                        for (int j = 0 ; j < dir.size() ; j++){
                            int new_col1 = col1 + dir[i];
                            int new_col2 = col2 + dir[j];

                            if (new_col1 < 0 || new_col2 < 0 
                                        || new_col1 >= grid[0].size() || new_col2 >= grid[0].size()){
                                continue;
                            }

                            if (col1 == col2) 
                                ans = max(ans, grid[row][col1] + next[new_col1][new_col2]);
                            else 
                                ans = max(ans, grid[row][col1] + grid[row][col2] + next[new_col1][new_col2]);
                        }
                    }

                    curr[col1][col2] = ans;

                }
            }

            next = move(curr);
        }

        return next[0][n-1];   
    }
};