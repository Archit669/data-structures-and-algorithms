#include <bits/stdc++.h>

// memoization
long helper(int *denominations , int index, int value, vector<vector<long>> &dp){
    if (index < 0){
        return (value == 0);
    }

    if (dp[index][value] != -1){
        return dp[index][value];
    }

    long notTake = helper(denominations, index-1, value, dp);    
    long take = 0;
    if (value - denominations[index] >= 0){
        take = helper(denominations, index, value - denominations[index],dp);
    }

    return dp[index][value] = notTake + take;
}


long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value+1,-1));
    return helper(denominations, n-1 , value, dp);
}


// tabulation and space optimization
#include <bits/stdc++.h>

long countWaysToMakeChange(int *denominations, int n, int val)
{
    vector<vector<long>> dp(n+1, vector<long>(val+1, 0));
    dp[0][0] = 1;

    for (int index = 1 ; index <= n ; index++){
        for (int value = 0; value <= val ; value++){
            long notTake = dp[index-1][value];
            long take = 0;
            if (value - denominations[index-1] >= 0){
                take = dp[index][value-denominations[index-1]];
            }

            dp[index][value] = notTake + take;
        }
    }

    return dp[n][val];
}