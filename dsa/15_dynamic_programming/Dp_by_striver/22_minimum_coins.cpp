#include <bits/stdc++.h>
using namespace std;

// memoization
int helper(vector<int> &num, int target, vector<int>& dp){

    if (target == 0){
        return dp[target] = 0;
    }

    int mini = INT_MAX;

    if (dp[target] != INT_MAX){
        return dp[target];
    }

    for (auto &ele : num){
        
        if (target - ele >= 0){
            int ans = helper(num, target - ele, dp);
            if (ans == -1) continue;
            mini = min(ans, mini);
        }
        
    }

    return dp[target] = mini == INT_MAX ? -1 : mini + 1;
}


int minimumElements(vector<int> &num, int x)
{
    vector<int> dp(x+1, INT_MAX);
    return helper(num, x, dp);
}

// tabulation
int minimumElements(vector<int> &num, int x)
{
    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;
    
    for (int target = 1; target <= x; target++) {
    int mini = INT_MAX;
      for (auto &ele : num){
          if (target - ele >= 0){
              int ans = dp[target-ele];
              if (ans == -1) continue;
              mini = min(ans, mini);
          }
      }

      dp[target] = mini == INT_MAX ? -1 : mini + 1;
    }

    return dp[x];
}
