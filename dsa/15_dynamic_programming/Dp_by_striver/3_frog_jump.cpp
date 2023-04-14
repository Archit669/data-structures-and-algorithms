#include <bits/stdc++.h> 
using namespace std;


// recursion
int solve(int idx , vector<int>& heights){
    if (idx == 0){
        return 0;
    }

    int left = solve(idx-1, heights) + abs(heights[idx] - heights[idx-1]);
    int right = INT_MAX;
    
    if (idx > 1){
        right = solve(idx-2, heights) + abs(heights[idx] - heights[idx-2]);
    }

    return min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    return solve(n-1 , heights);
}


// memoization
vector<int> dp;
int solve(int idx , vector<int>& heights){
    if (idx == 0){
        return 0;
    }

    if (dp[idx] != -1){
        return dp[idx];
    }

    int left = solve(idx-1, heights) + abs(heights[idx] - heights[idx-1]);
    int right = INT_MAX;
    if (idx > 1){
        right = solve(idx-2, heights) + abs(heights[idx] - heights[idx-2]);
    }

    return dp[idx] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> v(n,-1);
    dp = v;
    return solve(n-1 , heights);
}

// tabulation
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,-1);
    dp[0] = 0;
    for (int idx = 1 ; idx < n ; idx++){
        int left = dp[idx-1] + abs(heights[idx] - heights[idx-1]);
        int right = INT_MAX;
        if (idx > 1){
            right = dp[idx-2] + abs(heights[idx] - heights[idx-2]);
        }

        dp[idx] = min(left, right);
    }

    return dp[n-1];
}

// space optimization
int frogJump(int n, vector<int> &heights)
{
    int prev1 = 0, prev2 = 0;
    for (int idx = 1 ; idx < n ; idx++){
        int left = prev1 + abs(heights[idx] - heights[idx-1]);
        int right = INT_MAX;
        if (idx > 1){
            right = prev2 + abs(heights[idx] - heights[idx-2]);
        }
        prev2 = prev1;
        prev1 = min(left, right);
    }

    return prev1;
}
