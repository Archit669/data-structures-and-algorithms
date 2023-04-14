#include <bits/stdc++.h>
using namespace std;

// recursion
class Solution {
    int helper(vector<vector<int>>& triangle, int row, int col){
        
        if (col >= triangle[row].size()) return INT_MAX/2;

        if (row == triangle.size()-1){
            return triangle[row][col];
        }

        int path1 = 0 , path2 = 0;

        path1 = triangle[row][col] + helper(triangle , row+1, col);
        path2 = triangle[row][col] + helper(triangle, row+1, col + 1);

        return min(path1 , path2);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return helper(triangle , 0 , 0);
    }
};

// memoization
class Solution {
    int helper(vector<vector<int>>& triangle, int row, int col, vector<vector<int>> &dp){

        if (col >= triangle[row].size()) return INT_MAX/2;

        if (row == triangle.size()-1){
            return triangle[row][col];
        }

        if (dp[row][col] != -1){
            return dp[row][col];
        }

        int path1 = 0 , path2 = 0;

        path1 = triangle[row][col] + helper(triangle , row+1, col, dp);
        path2 = triangle[row][col] + helper(triangle, row+1, col + 1, dp);

        return dp[row][col] = min(path1 , path2);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;

        for (int row = 0 ; row < triangle.size() ; row++){
            vector<int> temp(triangle[row].size() , -1);
            dp.push_back(temp);
        }

        return helper(triangle , 0 , 0, dp);
    }
};

// tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;

        for (int row = 0 ; row < triangle.size() ; row++){
            vector<int> temp(triangle[row].size() , 0);
            dp.push_back(temp);
        }


        for (int row = triangle.size()-1 ; row >= 0 ; row--){
            for (int col = triangle[row].size()-1 ; col >= 0 ; col--){
                if (row == triangle.size()-1){
                    dp[row][col] = triangle[row][col];
                }else{
                    int path1 = INT_MAX/2 , path2 = INT_MAX/2;
                    path1 = triangle[row][col] + dp[row+1][col];
                    path2 = triangle[row][col] + dp[row+1][col+1];

                    dp[row][col] = min(path1, path2);
                }
            }
        }

        return dp[0][0];
    }
};

// space optimization
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    
        int m = triangle.size();

        vector<int> next(triangle[m-1].size());
        for (int col = 0 ; col < triangle[m-1].size() ; col++){
            next[col] = triangle[m-1][col];
        }

        for (int row = triangle.size()-2 ; row >= 0 ; row--){
            vector<int> curr(triangle[row].size());
            
            for (int col = triangle[row].size()-1 ; col >= 0 ; col--){
    
                int path1 = INT_MAX/2 , path2 = INT_MAX/2;
                path1 = triangle[row][col] + next[col];
                path2 = triangle[row][col] + next[col+1];

                curr[col] = min(path1, path2);
            }

            next = move(curr);
        }


        return next[0];
    }
};