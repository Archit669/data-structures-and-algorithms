#include <bits/stdc++.h>
using namespace std;

// tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size() , n = t.size();
        vector<vector<unsigned long>> dp(m+1 , vector<unsigned long>(n+1 , 0));

        for (int idx1 = 0 ; idx1 <= m ; idx1++){
            dp[idx1][0] = 1;
        }

        for (int idx1 = 1 ; idx1 <= m ; idx1++){
            for (int idx2 = 1 ; idx2 <= n ; idx2++){
                if (s[idx1-1] == t[idx2-1]){
                    dp[idx1][idx2] = dp[idx1-1][idx2-1] + dp[idx1-1][idx2];
                }else{
                    dp[idx1][idx2] = dp[idx1-1][idx2];
                }
            }
        }

        return dp[m][n];
    }
};


// space optimization
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size() , n = t.size();
        vector<unsigned long> dp(n+1, 0);
        dp[0] = 1;

        for (int idx1 = 1 ; idx1 <= m ; idx1++){
            for (int idx2 = n ; idx2 > 0 ; idx2--){
                if (s[idx1-1] == t[idx2-1]){
                    dp[idx2] = dp[idx2-1] + dp[idx2];
                }
            }
        }

        return dp[n];
    }
};