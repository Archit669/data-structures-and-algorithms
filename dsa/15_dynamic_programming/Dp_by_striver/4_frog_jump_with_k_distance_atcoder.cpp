#include <bits/stdc++.h>
using namespace std;

// recursion
class Solution1{
        int helper(int n, int k, vector<int>& heights, int idx){
            if (idx == 0) return 0;
            int mini = INT_MAX;

            for (int jump = 1; jump <= k ; jump++){
                if ((idx-jump) >= 0){
                    mini = min(helper(n, k , heights, idx-jump) + abs(heights[idx]- heights[idx-jump]), mini);
                }
            }

            return mini;
        }

    public:
        int frogJump(int n, int k, vector<int>& heights){
            return helper(n, k , heights, n-1);
        }
};

// memoization
class Solution2{
        int helper(int n, int k, vector<int>& heights, int idx, vector<int> &dp){
            if (idx == 0) return 0;
            int mini = INT_MAX;

            if (dp[idx] != -1){
                return dp[idx];
            }

            for (int jump = 1; jump <= k ; jump++){
                if ((idx-jump) >= 0){
                    mini = min(helper(n, k , heights, idx-jump, dp) + abs(heights[idx]- heights[idx-jump]), mini);
                }
            }

            return dp[idx] = mini;
        }

    public:
        int frogJump(int n, int k, vector<int>& heights){
            vector<int> dp(n, -1);
            return helper(n, k , heights, n-1, dp);
        }
};

// tabulation
class Solution3{
    public:
        int frogJump(int n, int k, vector<int>& heights){
            vector<int> dp(n, -1);
            dp[0] = 0;

            for (int idx = 1 ; idx < n ; idx++){
                int mini = INT_MAX;
                for (int jump = 1 ; jump <= k ; jump++){
                    if ((idx-jump) >= 0){
                        mini = min(dp[idx-jump] + abs(heights[idx]- heights[idx-jump]), mini);
                    }
                }

                dp[idx] = mini;
            }
            
            return dp[n-1];
        }
};

int main(){
    int n , k;
    cin >> n >> k;

    vector<int> heights(n);
    for (int i = 0 ; i < n ; i++){
        cin >> heights[i];
    }

    Solution3* ob = new Solution3();
    int ans = ob->frogJump(n, k , heights);

    cout << ans << endl;

    return 0;
}