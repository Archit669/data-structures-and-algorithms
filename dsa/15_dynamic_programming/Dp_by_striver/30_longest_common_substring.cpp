#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        int ans = 0;
        for (int idx1 = 1 ; idx1 <= n ; idx1++){
            for (int idx2 = 1 ; idx2 <= m ; idx2++){
                if (S1[idx1-1] == S2[idx2-1]){
                    dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
                    ans = max(dp[idx1][idx2], ans);
                }else{
                    dp[idx1][idx2] = 0;
                }
            }
        }
        
        return ans;
    }
};