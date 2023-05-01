// memoization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int dp[n+1][2][3];
        memset(dp, -1 , sizeof(dp));

        function<int(int,int, int)> f = [&](int idx, bool buy, int cap){
            if (idx == n || cap == 0) return dp[idx][buy][cap] = 0;
            if (dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
            if (buy) return dp[idx][buy][cap] = max(-prices[idx] + f(idx+1, 0, cap), f(idx+1, 1, cap));
            return dp[idx][buy][cap] = max(prices[idx] + f(idx+1, 1, cap-1), f(idx+1, 0, cap));
        };

        return f(0 , 1, 2);
    }
};

// tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int dp[n+1][2][3];
        memset(dp, 0 , sizeof(dp));

        for (int idx = n-1 ; idx >= 0 ; idx--){
            for (int buy = 1 ; buy >= 0 ; buy--){
                for (int cap = 1 ; cap <= 2 ; cap++){
                    if (buy) dp[idx][buy][cap] = max(-prices[idx] + dp[idx+1][0][cap], dp[idx+1][1][cap]);
                    else dp[idx][buy][cap] = max(prices[idx] + dp[idx+1][1][cap-1], dp[idx+1][0][cap]);
                }
            }
        }

        return dp[0][1][2];
    }
};

// space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> next(2, vector<int>(3,0));

        for (int idx = n-1 ; idx >= 0 ; idx--){
            vector<vector<int>> curr(2, vector<int>(3,0));

            for (int buy = 1 ; buy >= 0 ; buy--){
                for (int cap = 1 ; cap <= 2 ; cap++){
                    if (buy) 
                        curr[buy][cap] = max(-prices[idx] + next[0][cap], next[1][cap]);
                    else 
                        curr[buy][cap] = max(prices[idx] + next[1][cap-1], next[0][cap]);
                }
            }

            next = curr;
        }

        return next[1][2];
    }
};