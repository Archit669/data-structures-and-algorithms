#include <bits/stdc++.h>
using namespace std;
 
int canYouMake(string &word1, string &word2)
{
    int m = word1.size();
    int n = word2.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for (int idx1 = 1 ; idx1 <= m ; idx1++){
        for (int idx2 = 1; idx2 <= n ; idx2++){
            if (word1[idx1-1] == word2[idx2-1]){
                dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
            } else {
                dp[idx1][idx2] = max(dp[idx1][idx2 - 1], dp[idx1 - 1][idx2]);
            }
        }
    }

    int lcs = dp[m][n];
    return (m + n) - 2 * lcs;
}