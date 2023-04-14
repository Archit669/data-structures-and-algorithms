#include <bits/stdc++.h>
using namespace std;

// memoization
class Solution {
    bool solve(vector<int> &nums, int idx, vector<int>  &dp){
        if (idx >= nums.size()) return false;
        if (idx == nums.size()-1) return true;

        if (dp[idx] != -1){
            return dp[idx];
        }

        bool ans = false;

        for (int i = 1; i <= nums[idx] ; i++){
             ans |= solve(nums, idx+i, dp);
             if (ans == true) break;
        }

        return dp[idx] = ans;
    }
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size() ,-1);
        return solve(nums, 0, dp);
    }
};

// tabulation
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size() ,-1);
        dp[nums.size()-1] = 1;

        for (int idx = nums.size()-2 ; idx >= 0 ; idx--){
            bool ans = false;
            for (int i = 1 ; i <= nums[idx] ; i++){
                if (idx+i >= nums.size()) continue;
                ans |= dp[idx+i];
                if (ans == true){
                    break;
                }
            }
            dp[idx] = ans;
        }

        return dp[0];
    }
};

// greedy solution
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        for (int idx  = 0 ; idx< nums.size() ; idx++){
            if (idx > mx){
                return false;
            }
            mx = max(mx, idx + nums[idx]);
        }

        return true;
    }
};