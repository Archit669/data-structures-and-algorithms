#include <bits/stdc++.h> 
using namespace std;

int minInsertion(string &str)
{
    string s1 = str;
    string s2 = str;
    reverse(s2.begin(), s2.end());

    int m = s1.size(); 
    int n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));

    for (int idx1 = 1 ; idx1 <= m ; idx1++){
        for (int idx2 = 1 ; idx2 <= n ; idx2++){
            if (s1[idx1-1] == s2[idx2-1]){
                dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
            }else{
                dp[idx1][idx2] = max(dp[idx1][idx2-1], dp[idx1-1][idx2]);
            }
        }
    }

    int lps = dp[m][n];

    return n - lps;
}