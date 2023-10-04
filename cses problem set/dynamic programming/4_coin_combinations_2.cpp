#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

/*
// approach -1 (recursion + memoization) -> cannot done tabulation under constraints
void solve(){
    int n, x;
    cin >> n >> x;
 
    vector<int> arr(n);
 
    for (int idx = 0 ; idx <  n ; idx++){
        cin >> arr[idx];
    }
 
    sort(arr.begin(), arr.end());
 
     vector<vector<int>> dp(n+1, vector<int>(x+1, -1));
 
    function<int(int, int)> solve = [&](int curr, int target){
        if (target == 0) return 1LL;
 
        if (dp[curr][target] != -1) return dp[curr][target];
 
        int finalAns = 0;
        for (int idx = curr ; idx < n ; idx++){
            if (target - arr[idx] >= 0){
                int ans = solve(idx, target - arr[idx]);
                finalAns += ans;
            }
        }
 
        return dp[curr][target] = finalAns;
    };
 
    cout << solve(0, x) << endl;
}

// approach -2 (memoization)
void solve(){
    int n, x;
    cin >> n >> x;
 
    vector<int> arr(n);
 
    for (int idx = 0 ; idx <  n ; idx++){
        cin >> arr[idx];
    }
 
    sort(arr.begin(), arr.end());
 
    vector<vector<int>> dp(n+1, vector<int>(x+1, -1));
 
    function<int(int, int)> solve = [&](int idx, int target){
        if (target == 0) return 1LL;
        if (idx == n) return 0LL;
 
        if (dp[idx][target] != -1) return dp[idx][target];
 
        int notTake = solve(idx+1, target);
        int take = 0;
        if (target - arr[idx] >= 0){
            take = solve(idx, target - arr[idx]);
        }
 
        return dp[idx][target] = take + notTake;
    };
 
    cout << solve(0, x) << endl;
}


// approach-3 (tabulation)
void solve(){
    int n, x;
    cin >> n >> x;
 
    vector<int> arr(n);
 
    for (int idx = 0 ; idx <  n ; idx++){
        cin >> arr[idx];
    }
 
    sort(arr.begin(), arr.end());
 
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
 
    for (int idx = 0 ; idx <= n ; idx++){
        dp[idx][0] = 1;
    }
 
    for (int idx = n-1 ; idx >= 0 ; idx--){
        for (int target = 1; target <= x ; target++){
            int notTake = dp[idx+1][target];
            int take = 0;
            if (target - arr[idx] >= 0){
                take = dp[idx][target - arr[idx]];
            }
 
            dp[idx][target] = (take%mod + notTake%mod)%mod;
        }
    }
 
    cout << dp[0][x] << endl;
}

*/



// approach - 4 (space optimization)
void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);

    for (int idx = 0 ; idx <  n ; idx++){
        cin >> arr[idx];
    }

    sort(arr.begin(), arr.end());

    vector<int> next(x+1);
    next[0] = 1;

    for (int idx = n-1 ; idx >= 0 ; idx--){
        vector<int> curr(x+1);
        curr[0] = 1;
        for (int target = 1; target <= x ; target++){
            int notTake = next[target];
            int take = 0;
            if (target - arr[idx] >= 0){
                take = curr[target - arr[idx]];
            }

            curr[target] = (take%mod + notTake%mod)%mod;
        }

        next = curr;
    }

    cout << next[x] << endl;
}
 
signed main(){
    int t = 1;
    while (t--){
        solve();
    }
}