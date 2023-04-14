#include <bits/stdc++.h> 
using namespace std;


// recursion
int findMaximum(int row, int col, vector<vector<int>> &matrix){

    // if curr row is the last row 
    if (row == matrix.size()-1){
        return matrix[row][col];
    }

    vector<vector<int>> dir = {{1,0}, {1, -1}, {1, 1}};

    int ans = INT_MIN;

    for (int idx = 0 ; idx < dir.size() ; idx++){
        int newRow = row + dir[idx][0];
        int newCol = col + dir[idx][1];
        
        if (newCol < 0 || newCol >= matrix[0].size()) continue;
        
        ans = max(findMaximum(newRow, newCol, matrix),ans);
    }

    return ans + matrix[row][col];
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int ans = INT_MIN;

    for (int col = 0 ; col < n ; col++){
        ans = max(findMaximum(0, col, matrix),ans);
    }

    return ans;
}

// memoization
#include <bits/stdc++.h> 

int findMaximum(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp){

    // if curr row is the last row 
    if (row == matrix.size()-1){
        return matrix[row][col];
    }

    if (dp[row][col] != -1){
        return dp[row][col];
    }

    vector<vector<int>> dir = {{1,0}, {1, -1}, {1, 1}};

    int ans = INT_MIN;

    for (int idx = 0 ; idx < dir.size() ; idx++){
        int newRow = row + dir[idx][0];
        int newCol = col + dir[idx][1];
        
        if (newCol < 0 || newCol >= matrix[0].size()) continue;
        
        ans = max(findMaximum(newRow, newCol, matrix, dp),ans);
    }

    return dp[row][col] = ans + matrix[row][col];
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n,-1));

    int ans = INT_MIN;

    for (int col = 0 ; col < n ; col++){
        ans = max(findMaximum(0, col, matrix,dp),ans);
    }

    return ans;
}

// tabulation
#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int res = INT_MIN;
    
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dir = {{1,0}, {1, -1}, {1, 1}};

    vector<vector<int>> dp(m, vector<int>(n,-1));

    for (int row = m-1 ; row >= 0 ; row--){
        res = INT_MIN;
        for (int col = n-1 ; col >= 0 ; col--){
            if (row == m-1){
                
                dp[row][col] = matrix[m-1][col];

            }else{
                int ans = INT_MIN;
                for (int idx = 0 ; idx < dir.size() ; idx++){
                    int newRow = row + dir[idx][0];
                    int newCol = col + dir[idx][1];
                    
                    if (newCol < 0 || newCol >= matrix[0].size()) continue;
                    
                    ans = max(dp[newRow][newCol],ans);
                }

                dp[row][col] = ans + matrix[row][col];
            }

            res = max(res, dp[row][col]);
        }
    }

    return res;
}

// space optimization
#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int res = INT_MIN;
    
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dir = {{1,0}, {1, -1}, {1, 1}};


    vector<int> prev(n, -1);

    for (int row = m-1 ; row >= 0 ; row--){
        vector<int> curr(n, -1);
        res = INT_MIN;
        for (int col = n-1 ; col >= 0 ; col--){
            if (row == m-1){
                
                curr[col] = matrix[m-1][col];

            }else{
                int ans = INT_MIN;
                for (int idx = 0 ; idx < dir.size() ; idx++){
                    int newRow = row + dir[idx][0];
                    int newCol = col + dir[idx][1];
                    
                    if (newCol < 0 || newCol >= matrix[0].size()) continue;
                    
                    ans = max(prev[newCol],ans);
                }

                curr[col] = ans + matrix[row][col];
            }

            res = max(res, curr[col]);
        }

        prev = move(curr);
    }

    return res;
}