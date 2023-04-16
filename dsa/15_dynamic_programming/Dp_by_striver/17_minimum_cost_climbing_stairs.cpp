#include <bits/stdc++.h>
using namespace std;

// memoization
class Solution {
    int helper(int index, vector<int>&cost, vector<int>&dp){
        if (index > cost.size()) return INT_MAX;
        if (index == cost.size()) return 0;
        if (dp[index] != -1) return dp[index];
        int ans1 = helper(index+1, cost, dp);
        int ans2 = helper(index+2, cost, dp);
        return dp[index] = cost[index] + min(ans1, ans2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, -1);
        return min(helper(0, cost, dp) , helper(1, cost,dp));
    }
};

// tabulation
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);

        dp[n] = 0; dp[n-1] = cost[n-1];

        for (int index = n-2; index >= 0 ; index--){
            int ans1 = dp[index+1];
            int ans2 = dp[index+2];
            dp[index] = cost[index] + min(ans1, ans2);
        }

        return min(dp[0], dp[1]);
    }
};

// space optimizatin
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = 0, prev1 = cost[n-1];

        for (int index = n-2; index >= 0 ; index--){
            int ans1 = prev1 , ans2 = prev2;
            int curr = cost[index] + min(ans1, ans2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev2, prev1);
    }
};

