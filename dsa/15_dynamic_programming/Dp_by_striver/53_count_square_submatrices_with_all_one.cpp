#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        
        // fill first row same as matrix
        for (int col = 0 ; col < n ; col++){
            dp[0][col] = matrix[0][col];
        }

        // fill first col same as matrix
        for (int row = 0 ; row < m ; row++){
            dp[row][0] = matrix[row][0];
        }

        // fill the dp table
        for (int row = 1 ; row < m ; row++){
            for (int col = 1 ; col < n ; col++){
                if (matrix[row][col] == 1)
                    dp[row][col] = 1 + min({dp[row-1][col-1], dp[row][col-1], dp[row-1][col]});
            }
        }

        int ans = 0;
        for (int row = 0 ; row < m ; row++){
            for (int col = 0 ; col < n ; col++){
                ans += dp[row][col];
            }
        }

        return ans;
    }
};