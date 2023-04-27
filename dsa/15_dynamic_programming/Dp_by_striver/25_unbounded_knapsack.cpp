// memoziation

#include <bits/stdc++.h> 
using namespace std;

int helper(int idx, int maxWeight, vector<int>& profit, vector<int> &weight, vector<vector<int>> &dp){
    // if idx is reached the size of weight or profit array then we have used all the weights 
    // so there is no weight to select and no profit so return 0
    if (idx == profit.size()){
        return 0;
    }

    // return already processed calls
    if (dp[idx][maxWeight] != -1){
        return dp[idx][maxWeight];
    }

    // don't take the weight and profit at given index 
    int notTake = helper(idx+1, maxWeight, profit, weight, dp);\

    // take the weight at give index if it fessible and call for that index with new weight
    // when we have unlimited supply , don't increase the idx
    // when we have to choose one once, then increase the idx
    int take = 0;
    if (maxWeight - weight[idx] >= 0){
        take = profit[idx] + helper(idx, maxWeight - weight[idx], profit, weight, dp);
    }

    // return max of both possibilites
    return dp[idx][maxWeight] = max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w+1, -1));
    return helper(0 , w, profit, weight, dp);
}

// tabulation
// memoziation

#include <bits/stdc++.h> 
using namespace std;

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
    for (int idx = n-1 ; idx >= 0 ; idx--){
        for (int maxWeight = 0 ; maxWeight <= w ; maxWeight++){
            int notTake = dp[idx+1][maxWeight];
            int take = 0;
            if (maxWeight - weight[idx] >= 0){
                take = profit[idx] + dp[idx][maxWeight - weight[idx]];
            }

            dp[idx][maxWeight] = max(take, notTake);
        }
    }

    return dp[0][w];
}


// space optimization
// memoziation

#include <bits/stdc++.h> 
using namespace std;

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> next(w+1, 0);
    for (int idx = n-1 ; idx >= 0 ; idx--){
        vector<int> curr(w+1, 0);
        for (int maxWeight = 0 ; maxWeight <= w ; maxWeight++){
            int notTake = next[maxWeight];
            int take = 0;
            if (maxWeight - weight[idx] >= 0){
                take = profit[idx] + curr[maxWeight - weight[idx]];
            }

            curr[maxWeight] = max(take, notTake);
        }
        next = move(curr);
    }

    return next[w];
}
