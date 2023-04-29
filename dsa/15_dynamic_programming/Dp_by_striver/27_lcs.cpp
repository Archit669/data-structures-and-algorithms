#include <bits/stdc++.h>
using namespace std;

// memoization
#include <bits/stdc++.h>

int helper(string s, string t, int idx1, int idx2, vector<vector<int>> &dp ){
	if (idx1 == s.size() || idx2 == t.size()) return 0;

	if (dp[idx1][idx2] != -1) return dp[idx1][idx2];

	if (s[idx1] == t[idx2]){
		return dp[idx1][idx2] = 1 + helper(s, t, idx1+1, idx2+1, dp);
	}

	return dp[idx1][idx2] = max(helper(s, t, idx1+1, idx2, dp) , helper(s,t,idx1 , idx2+1, dp));
}


int lcs(string s, string t)
{
	vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
	return helper(s, t, 0, 0, dp);
}

// tabulation
#include <bits/stdc++.h>

int lcs(string s, string t)
{
	vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
	for (int idx1 = s.size()-1 ; idx1 >= 0 ; idx1--){
		for (int idx2 = t.size()-1 ; idx2 >=0 ; idx2--){
			if (s[idx1] == t[idx2]){
				dp[idx1][idx2] = 1 + dp[idx1+1][idx2+1];
			}else{
				dp[idx1][idx2] = max(dp[idx1+1][idx2] , dp[idx1][idx2+1]);
			}
		}
	}

	return dp[0][0];
}

// space optimization 1
#include <bits/stdc++.h>

int lcs(string s, string t)
{
	vector<int> next(t.size() + 1 , 0);
	for (int idx1 = s.size()-1 ; idx1 >= 0 ; idx1--){
		vector<int> curr(t.size() + 1, 0);
		for (int idx2 = t.size()-1 ; idx2 >=0 ; idx2--){
			if (s[idx1] == t[idx2]){
				curr[idx2] = 1 + next[idx2+1];
			}else{
				curr[idx2] = max(next[idx2] , curr[idx2+1]);
			}
		}
		next = move(curr);
	}

	return next[0];
}




