#include <bits/stdc++.h>
using namespace std;

// recursion
int maximumNonAdjacentSum(vector<int> &nums, int idx = 0, int sum = 0){

    if (idx >= nums.size()) return sum;

    int ans1 = maximumNonAdjacentSum(nums, idx+2, sum + nums[idx]);
    int ans2 = maximumNonAdjacentSum(nums, idx+1, sum);

    return max(ans1, ans2);
}

// recursion (top - down) with memoization
#include <bits/stdc++.h> 
int solve(vector<int>& nums, int idx, vector<int> &dp){
    if (idx < 0){
        return 0;
    }

    if (idx == 0){
        return nums[idx];
    }

    if (dp[idx] != -1) return dp[idx];

    int pick = nums[idx] + solve(nums, idx-2, dp);
    int unpick = solve(nums, idx-1, dp);

    return dp[idx] = max(pick, unpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size(), -1);
    return solve(nums, nums.size()-1, dp);
}

// tabulation
#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){

    vector<int> dp(nums.size());
    dp[0] = nums[0]; 

    for (int idx = 1 ; idx < nums.size() ; idx++){
        int maxi = 0;

        // pick
        int pick = nums[idx];
        if (idx-2 >= 0){
            pick += dp[idx-2];
        }

        // unpick
        int unpick = dp[idx-1];
        dp[idx] = max(pick, unpick);
    }

    return dp[nums.size()-1];
}

// space optimization
#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    
    int prev1 = nums[0], prev2 = 0;

    for (int idx = 1 ; idx < nums.size() ; idx++){

        // pick
        int pick = nums[idx];
        pick += prev2;

        // unpick
        int unpick = prev1;

        prev2 = prev1;
        prev1 = max(pick, unpick);
    }

    return prev1;
}








