class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;

        for (int idx = 1 ; idx < prices.size() ; idx++){
            profit = max(profit, prices[idx]-mini);
            mini = min(mini, prices[idx]);
        }

        return profit;
    }
};