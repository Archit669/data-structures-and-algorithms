#include <bits/stdc++.h>
using namespace std;


// memoization
class Solution {
    vector<int> dp;
    int solve(vector<int> &nums, int idx){
        if (idx == nums.size()-1) return dp[idx] = 0;
        int ans = INT_MAX/2;
        if (dp[idx] != -1) return dp[idx];
        for (int i = 1 ; i <= nums[idx] ; i++){
            if (idx + i < nums.size()){
                ans = min(solve(nums, idx+i), ans);
            }
        }

        return dp[idx] = ans + 1;
    }
public:
    int jump(vector<int>& nums) {
        dp = vector<int>(nums.size() , -1);
        return solve(nums , 0);
    }
};


// tabulation
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size() , -1);
        dp[nums.size()-1] = 0;
        for (int idx = nums.size()-2 ; idx >= 0 ; idx--){
            int ans = INT_MAX/2;
            for (int i = 1 ; i <= nums[idx] ; i++){
                if (idx + i < nums.size()){
                    ans = min(dp[idx+i], ans);
                }
            }

            dp[idx] = ans + 1;
        }

        return dp[0];
    }
};




// greedy solution
class Solution {
public:
    int jump(vector<int>& nums) {
        int max_reachable = 0;
        int ans = 0;
        int curr_max_reachable = 0;

        for (int idx = 0 ; idx < nums.size()-1 ; idx++){
            curr_max_reachable = max(curr_max_reachable, idx + nums[idx]);
            if (idx == max_reachable){
                max_reachable = curr_max_reachable;
                ans++;
            }
        }

        return ans;
    }
};