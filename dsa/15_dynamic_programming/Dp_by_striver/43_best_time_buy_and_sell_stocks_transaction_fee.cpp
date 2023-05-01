#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<int> ahead(2,-1) , curr(2,-1);
        ahead[0] = ahead[1] = 0;

        for (int idx = n-1 ; idx >= 0 ; idx--){
            for (int buy = 1 ; buy >= 0 ; buy--){
                if (buy) curr[buy] =max(-prices[idx] + ahead[0], ahead[1]);
                else curr[buy] = max(prices[idx] + ahead[1] - fee, ahead[0]);
            }

            ahead = curr;
        }

        return ahead[1];
    }
};