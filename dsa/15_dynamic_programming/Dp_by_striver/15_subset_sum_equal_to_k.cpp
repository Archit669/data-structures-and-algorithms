#include <bits/stdc++.h>
using namespace std;

// memoization
#include <bits/stdc++.h> 
bool solve (vector<int> &arr, int k, int index, vector<vector<int>> &dp){
    if (index == arr.size()){
        return k == 0;
    }

    bool pick = false;

    if (dp[index][k] != -1){
        return dp[index][k];
    }

    if (k - arr[index] >= 0){
        pick = solve(arr, k - arr[index] , index+1, dp);
    }

    bool unpick = solve(arr,k , index+1,dp);

    return dp[index][k] = pick || unpick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1,-1));
    return solve(arr, k, 0, dp);
}

// tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n+1, vector<bool>(k+1,false));
    dp[n][0] = true;

    for (int index = n -1 ; index >= 0 ; index--){
        for (int target  = 0 ; target <= k ; target++){
            bool pick = false;
            if (target - arr[index] >= 0){
                pick = dp[index+1][target - arr[index]];
            }

            bool unpick = dp[index+1][target];

            dp[index][target] = pick || unpick;

        }
    }

    return dp[0][k];
}

// space optimization
#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> next(k+1, false);
    next[0] = true;

    for (int index = n -1 ; index >= 0 ; index--){
        vector<bool> curr(k+1, false);
        for (int target  = 0 ; target <= k ; target++){
            bool pick = false;
            if (target - arr[index] >= 0){
                pick = next[target - arr[index]];
            }

            bool unpick = next[target];

            curr[target] = pick || unpick;

        }

        next = move(curr);
    }

    return next[k];
}