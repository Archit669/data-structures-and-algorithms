#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();

        vector<int> dp(n,-1);
        function<int(int)> f = [&](int idx){

            if (idx == n) return 0;

            if (dp[idx] != -1) return dp[idx];

            int len = 0;
            int maxi = arr[idx];

            int ans = 0;

            for (int jdx = idx ; jdx < min(n, idx + k); jdx++){

                len++;

                maxi = max(maxi, arr[jdx]);

                int sum = len*maxi + f(jdx+1);

                ans = max(ans, sum);
            }

            return dp[idx] = ans;
        };

        return f(0);
    }
};