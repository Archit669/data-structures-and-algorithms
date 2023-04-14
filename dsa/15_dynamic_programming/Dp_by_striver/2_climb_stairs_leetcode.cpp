// memoization
class Solution {
    int helper(int n , vector<int> &dp){
        if (n == 0 || n == 1) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = helper(n-1, dp) + helper(n-2, dp);
    }
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) return 1;
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};

// tabulation
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 1;
        vector<int> dp(n + 1, -1);
        int paths = 0;
        dp[0] = 1; dp[1] = 1;
        for (int i = 2 ; i <= n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// space optimization
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 1;
        int paths = 0;
        int prev2 = 1; int prev1 = 1;
        for (int i = 2 ; i <= n ; i++){
            int curr = prev1+ prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};