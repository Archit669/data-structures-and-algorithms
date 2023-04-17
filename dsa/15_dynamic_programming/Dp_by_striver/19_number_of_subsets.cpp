#include <bits/stdc++.h> 
using namespace std;

// memmoization
int helper(vector<int> &num, int index, int target, vector<vector<int>> &dp){
    if (index == num.size()){
        if (target == 0){
            return 1;
        }else{
            return 0;
        }
    }

    if (dp[index][target] != -1){
        return dp[index][target];
    }

    int pick = 0;
    if (target - num[index] >= 0){
        pick = helper(num, index+1, target - num[index], dp);
    }

    int unpick = helper(num, index+1, target, dp);

    return dp[index][target] = pick + unpick;
}

int findWays(vector<int> &num, int tar)
{
    vector<vector<int>> dp(num.size(), vector<int>(tar+1, -1));
    return helper(num , 0 , tar, dp);
}

// tabulation
#include <bits/stdc++.h> 

int findWays(vector<int> &num, int tar)
{
    vector<vector<int>> dp(num.size() + 1, vector<int>(tar+1, 0));
    dp[num.size()][0] = 1;
    
    for (int index = num.size()-1 ; index >= 0 ; index--){
        for (int target = 0 ; target <= tar ; target++){
            int pick = 0;
            if (target - num[index] >= 0){
                pick = dp[index+1][target - num[index]];
            }

            int unpick = dp[index+1][target];

            dp[index][target] = pick + unpick;
        }
    }

    return dp[0][tar];
}

// space optimization
#include <bits/stdc++.h> 

int findWays(vector<int> &num, int tar)
{
    vector<int> next(tar+1, 0);
    next[0] = 1;
    
    for (int index = num.size()-1 ; index >= 0 ; index--){
        vector<int> curr(tar+1, 0);
        for (int target = 0 ; target <= tar ; target++){
            int pick = 0;
            if (target - num[index] >= 0){
                pick = next[target - num[index]];
            }

            int unpick = next[target];

            curr[target] = pick + unpick;
        }
        
        next = move(curr);
    }

    return next[tar];
}