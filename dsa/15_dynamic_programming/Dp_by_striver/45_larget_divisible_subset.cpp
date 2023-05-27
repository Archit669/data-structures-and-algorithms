#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> dp(n, 0);
        vector<int> hash(n,0);
        dp[0] = 1; 

        int ans = 1, ans_idx = 0;

        for (int idx = 1;  idx < n ; idx++){
            int maxi = 0 ; hash[idx] = idx;
            for (int jdx = 0 ; jdx < idx ; jdx++){
                if (nums[idx] % nums[jdx] == 0 && dp[jdx] > maxi){
                    maxi = dp[jdx];
                    hash[idx] = jdx;
                }
            }

            dp[idx] = 1 + maxi;
            if (dp[idx] > ans){
                ans = dp[idx];
                ans_idx = idx;
            }
        }

        vector<int> res;
        while (hash[ans_idx] != ans_idx){
            res.push_back(nums[ans_idx]);
            ans_idx = hash[ans_idx];
        }

        res.push_back(nums[ans_idx]);
        reverse(res.begin(), res.end());

        return res;
    }
};