#include <bits/stdc++.h>
using namespace std;

// tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size() , n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        // filling first row with the col index
        for (int i = 0 ; i <= n ; i++) dp[0][i] = i;
        // filling first col with the row index
        for (int j = 0; j <= m ; j++) dp[j][0] = j;
        
        for (int idx1 = 1 ; idx1 <= m ; idx1++){
            for (int idx2 = 1 ; idx2 <= n ; idx2++){
                if (word1[idx1-1] == word2[idx2-1]){
                    dp[idx1][idx2] = dp[idx1-1][idx2-1];
                }else{
                    dp[idx1][idx2] = 1 + min({dp[idx1][idx2-1], dp[idx1-1][idx2-1], dp[idx1-1][idx2]});
                }
            }
        }

        return dp[m][n];
    }
};

// space optimization
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size() , n = word2.size();
        vector<int> prev(n+1,-1); vector<int> curr(n+1,-1);
        
        // filling first row with idx of curr col
        for (int i = 0 ; i <= n ; i++) prev[i] = i;
        
        for (int idx1 = 1 ; idx1 <= m ; idx1++){
            curr[0] = idx1;
            for (int idx2 = 1 ; idx2 <= n ; idx2++){
                if (word1[idx1-1] == word2[idx2-1]){
                    curr[idx2] = prev[idx2-1];
                }else{
                    curr[idx2] = 1 + min({curr[idx2-1], prev[idx2-1], prev[idx2]});
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};