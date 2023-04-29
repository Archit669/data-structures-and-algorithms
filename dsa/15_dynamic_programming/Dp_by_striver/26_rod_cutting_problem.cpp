#include <bits/stdc++.h>
using namespace std;

// memoization
int helper(vector<int> &prices, int rodLength , int idx, vector<vector<int>> &dp){

	// base case
	if (rodLength == 0 || idx == prices.size())
	{
		return dp[rodLength][idx] = 0;
	}

	if (dp[rodLength][idx] != -1) return dp[rodLength][idx];

	// notTake
	int notTake = helper(prices, rodLength, idx+1, dp);

	// Take
	int take = -1e9;
	if (rodLength - (idx + 1) >= 0)
	{
		take = prices[idx] + helper(prices, rodLength-idx-1 , idx, dp);
	}

	return dp[rodLength][idx] = max(take, notTake);
}


int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n+1 , vector<int>(price.size()+1, -1));
	return helper(price , n, 0, dp);
}


// tabulation
int cutRod(vector<int> &prices, int n)
{
	vector<vector<int>> dp(n+1 , vector<int>(prices.size()+1, 0));

	for (int rodLength = 1 ; rodLength <= n ; rodLength++){
		for (int idx = prices.size()-1 ; idx >= 0 ; idx--){

			// notTake
			int notTake = dp[rodLength][idx+1];

			// Take
			int take = -1e9;
			if (rodLength - (idx + 1) >= 0)
			{
				take = prices[idx] + dp[rodLength-idx-1][idx];
			}

			dp[rodLength][idx] = max(take, notTake);
		}
	}

	return dp[n][0];
}





// space optimization

int cutRod(vector<int> &prices, int n)
{
	vector<int> next(n+1,0);

	for (int idx = prices.size()-1 ; idx >= 0 ; idx--){
		vector<int> curr(n+1,0);
		for (int rodLength = 1 ; rodLength <= n ; rodLength++){

			// notTake
			int notTake = next[rodLength];

			// Take
			int take = -1e9;
			if (rodLength - (idx + 1) >= 0)
			{
				take = prices[idx] + curr[rodLength-idx-1];
			}

			curr[rodLength] = max(take, notTake);
		}

		next = move(curr);
	}

	return next[n];
}


