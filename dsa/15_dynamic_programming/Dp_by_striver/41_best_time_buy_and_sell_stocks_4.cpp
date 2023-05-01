class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> next(2, vector<int>(k+1,0));

        for (int idx = n-1 ; idx >= 0 ; idx--){
            vector<vector<int>> curr(2, vector<int>(k+1,0));

            for (int buy = 1 ; buy >= 0 ; buy--){
                for (int cap = 1 ; cap <= k ; cap++){
                    if (buy) 
                        curr[buy][cap] = max(-prices[idx] + next[0][cap], next[1][cap]);
                    else 
                        curr[buy][cap] = max(prices[idx] + next[1][cap-1], next[0][cap]);
                }
            }

            next = curr;
        }

        return next[1][k];
    }
};