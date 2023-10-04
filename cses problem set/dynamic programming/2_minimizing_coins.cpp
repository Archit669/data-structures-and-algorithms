#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define MOD 1000000007
 
/*
// approach -1 tle + runtime
void solve(){
    int n, x;
    cin >> n >> x;
 
    vector<int> arr(n);
    for (int idx = 0 ; idx < n ; idx++){
        cin >> arr[idx];
    }
 
    vector<vector<int>> dp(n, vector<int>(x+1,-1));
 
    function<int(int,int)> f = [&](int idx , int x){
        if (x == 0) return 0LL;
        if (idx == n) return (int)1e9;
        if (dp[idx][x] != -1) return dp[idx][x];
        int notTake = f(idx+1, x);
        int take = 1e9;
        if (x - arr[idx] >= 0){
            int val = f(idx ,x-arr[idx]);
            if (val != 1e9){
                take = 1 + val;
            }
        }
 
        return dp[idx][x] = min(take, notTake);
    };
 
    int ans = f(0, x);
    if (ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;
}


// approach-2 tle in two cases
void solve(){
    int n, x;
    cin >> n >> x;
 
    vector<int> arr(n);
 
    for (int idx = 0 ; idx <  n ; idx++){
        cin >> arr[idx];
    }
 
    vector<int> dp(x+1, -1);
 
    function<int(int)> solve = [&](int target){
 
        if (target == 0) return 0LL;
 
        if (dp[target] != -1) return dp[target];
 
        int finalAns = 1e9;
 
        for (int idx = 0 ; idx < n ; idx++){
 
            if (target - arr[idx] >= 0){
                int ans = solve(target - arr[idx]);
                if (ans == -1) continue;
                finalAns = min(finalAns, 1 + ans);
            }
        }
 
        return dp[target] = (finalAns == (long long)1e9) ? -1 : finalAns;
    };
 
    cout << solve(x) << endl;
}

*/


// approach-3 finally submit (accepted)
void solve(){
    int n, x;
    cin >> n >> x;
 
    vector<int> arr(n);
 
    for (int idx = 0 ; idx <  n ; idx++){
        cin >> arr[idx];
    }
 
    vector<int> dp(x+1);
 
    dp[0] = 0;
    for (int target = 1 ; target <= x ; target++){
        int finalAns = 1e9;
        for (int idx = 0 ; idx < n ; idx++){
 
            if (target - arr[idx] >= 0){
                int ans = dp[target - arr[idx]];
                if (ans == -1) continue;
                finalAns = min(finalAns, 1 + ans);
            }
        }
 
        dp[target] = (finalAns == (long long)1e9) ? -1 : finalAns;
    }
 
    cout << dp[x] << endl;
}


signed main(){
    int t = 1; 
    while (t--){
        solve();
    }
}