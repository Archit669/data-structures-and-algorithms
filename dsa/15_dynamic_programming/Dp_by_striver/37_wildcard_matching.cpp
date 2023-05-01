#include <bits/stdc++.h>
using namespace std;

// tabulation
class Solution {
public:
    bool isMatch(string p, string s) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[m][n] = true;

        for (int idx1 = m-1 ; idx1 >= 0 ; idx1--){

            if (s[idx1] == '*') dp[idx1][n] = dp[idx1+1][n];

            for (int idx2 = n-1 ; idx2 >= 0 ; idx2--){
                if ((s[idx1] == p[idx2]) || (s[idx1] == '?')){
                    dp[idx1][idx2] = dp[idx1+1][idx2+1];
                }else if (s[idx1] == '*'){
                    dp[idx1][idx2] = dp[idx1+1][idx2] || dp[idx1][idx2+1];
                }else if (s[idx1] != p[idx2]){
                    dp[idx1][idx2] = false;
                }
            }
        }

        return dp[0][0];
    }
};