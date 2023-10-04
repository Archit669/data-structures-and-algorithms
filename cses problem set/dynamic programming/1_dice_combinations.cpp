#include <bits/stdc++.h>
#define M  int(1e9 + 7)
#define ll long long
using namespace std;


// memoization
// ll ways(ll target, vector<ll> &dp){
//     if (target == 0) return 1;
//     if (dp[target] != -1) return dp[target];
//     ll sum = 0;
//     for (ll outcome = 1 ; outcome <= 6 ; outcome++){
//         if (target - outcome >= 0)
//             sum += ways(target - outcome, dp)%M;
//     }

//     return dp[target] = sum%M;
// }

signed main(){
    ll n;
    cin >> n;

    vector<ll> dp(n+1,-1);
    // cout << ways(n, dp) << endl;  
    dp[0] = 1;
    for (ll target = 1 ; target <= n; target++){

        ll sum = 0;
        for (ll outcome = 1 ; outcome <= 6 ; outcome++){
            if (target - outcome >= 0)
                sum += dp[target-outcome] % M;
        }
        
        dp[target] = sum % M;
    }  

    cout << dp[n] << endl;

    return 0;
}