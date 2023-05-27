#include <bits/stdc++.h>
using namespace std;

// memoization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));

        function<int(int,int)> f = [&](int idx, bool buy){
            if (idx == n) return dp[idx][buy] = 0;
            if (dp[idx][buy] != -1) return dp[idx][buy];
            if (buy) return dp[idx][buy] = max(-prices[idx] + f(idx+1, 0), f(idx+1, 1));
            return dp[idx][buy] = max(prices[idx] + f(idx+1, 1), f(idx+1, 0));
        };

        return f(0 , 1);
    }
};

// tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        dp[n][0] = dp[n][1] = 0;

        for (int idx = n-1 ; idx >= 0 ; idx--){
            for (int buy = 1 ; buy >= 0 ; buy--){
                if (buy) dp[idx][buy] =max(-prices[idx] + dp[idx+1][0], dp[idx+1][1]);
                else dp[idx][buy] = max(prices[idx] + dp[idx+1][1], dp[idx+1][0]);
            }
        }

        return dp[0][1];
    }
};


// space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        vector<int> ahead(2,-1) , curr(2,-1);
        ahead[0] = ahead[1] = 0;

        for (int idx = n-1 ; idx >= 0 ; idx--){
            for (int buy = 1 ; buy >= 0 ; buy--){
                if (buy) curr[buy] =max(-prices[idx] + ahead[0], ahead[1]);
                else curr[buy] = max(prices[idx] + ahead[1], ahead[0]);
            }

            ahead = curr;
        }

        return ahead[1];
    }
};