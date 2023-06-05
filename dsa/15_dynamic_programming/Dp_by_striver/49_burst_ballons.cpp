#include <bits/stdc++.h>
using namespace std;

// memoization
class Solution {
public:
    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        nums.push_back(1);
        nums.insert(nums.begin(),1);

        vector<vector<int>> dp(n+2, vector<int>(n+2,-1));
        
        function<int(int,int)> f = [&](int i, int j){

            // no range left
            if (i > j) return 0;

            if (dp[i][j] != -1) return dp[i][j];

            int ans = INT_MIN;

            // assume every balloon in range one by one that will be last one to busted
            for (int idx = i ; idx <= j ; idx++){

                int cost = nums[i-1]* nums[idx]* nums[j+1] + f(i, idx-1) + f(idx+1, j);

                ans = max(cost, ans);
            }


            return dp[i][j] = ans;
        };

        return f(1, n);
    }
};

// tabulation
class Solution {
public:
    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        nums.push_back(1);
        nums.insert(nums.begin(),1);

        vector<vector<int>> dp(n+2, vector<int>(n+2));

        for (int i = n ; i >= 1 ; i--){
            for (int j = 1 ; j <= n ; j++){

                if (i > j) continue;

                int ans = INT_MIN;

                // assume every balloon in range one by one that will be last one to busted
                for (int idx = i ; idx <= j ; idx++){

                    int cost = nums[i-1]* nums[idx]* nums[j+1] + dp[i][idx-1] + dp[idx+1][j];

                    ans = max(cost, ans);
                }
                
                dp[i][j] = ans;
            }
        }

        return dp[1][n];
    }
};