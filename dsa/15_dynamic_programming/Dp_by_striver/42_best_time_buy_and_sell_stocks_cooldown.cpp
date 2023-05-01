// memoization
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int dp[n+2][2];
        memset(dp, -1 , sizeof(dp));
        
        function<int(int,int)> f = [&](int idx, int buy){
            if (idx >= n)  return 0;

            if (dp[idx][buy] != -1) return dp[idx][buy];

            if (buy){
                return dp[idx][buy] = max(-prices[idx] + f(idx+1, 0), f(idx+1, 1));
            }else{
                return dp[idx][buy] = max(prices[idx] + f(idx+2, 1), f(idx+1, 0));
            }
        };

        return f(0,1);
    }
};




// tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int dp[n+2][2];
        memset(dp, 0, sizeof(dp));

        for (int idx = n-1 ; idx>= 0 ; idx--){
            for (int buy = 0 ; buy < 2; buy++){
                if (buy){
                    dp[idx][buy] = max(-prices[idx] + dp[idx+1][0], dp[idx+1][1]);
                }else{
                    dp[idx][buy] = max(prices[idx] + dp[idx+2][1], dp[idx+1][0]);
                }
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
        vector<int> first(2), second(2) ,curr(2);

        for (int idx = n-1 ; idx>= 0 ; idx--){
            for (int buy = 0 ; buy < 2; buy++){
                if (buy){
                    curr[buy] = max(-prices[idx] + first[0], first[1]);
                }else{
                    curr[buy] = max(prices[idx] + second[1], first[0]);
                }
            }
            second = first;
            first = curr;
        }

        return curr[1];
    }
};