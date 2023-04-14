#include <bits/stdc++.h>
using namespace std;

// recursion
class Solution {
    int solve(vector<int> &coins, int amount){

        if (amount == 0){
            return 0;
        }

        int res = INT_MAX;

        for (int i = 0 ; i < coins.size() ; i++){
            if (amount - coins[i] >= 0){
                int ans = solve(coins, amount-coins[i]);
                if (ans == -1) continue;
                res = min(res, 1 + ans);
            }
        }

        return res == INT_MAX ? -1  : res;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        return solve(coins, amount);
    }
};

// memoization
class Solution {
    int solve(vector<int> &coins, int amount, vector<int> &dp){

        if (amount == 0){
            return 0;
        }

        int res = INT_MAX;

        if (dp[amount] != INT_MAX){
            return dp[amount];
        }

        for (int i = 0 ; i < coins.size() ; i++){
            if (amount - coins[i] >= 0){
                int ans = solve(coins, amount-coins[i], dp);
                if (ans == -1) continue;
                res = min(res, 1 + ans);
            }
        }

        return dp[amount] = res == INT_MAX ? -1  : res;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        return solve(coins, amount, dp);
    }
};

// tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for (int amt = 1 ; amt <= amount ; amt++){
            int res = INT_MAX;
            for (int i = 0 ; i < coins.size() ; i++){
                if (amt - coins[i] >= 0){
                    int ans = dp[amt-coins[i]];
                    if (ans == -1) continue;
                    res = min(res, 1 + ans);
                }
            }

            dp[amt] = res == INT_MAX ? -1  : res;
        }

        return dp[amount];
    }
};