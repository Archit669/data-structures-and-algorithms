#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define mod 1000000007

 
void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);

    for (int idx = 0 ; idx <  n ; idx++){
        cin >> arr[idx];
    }

    vector<int> dp(x+1);

    dp[0] = 1;
    for (int target = 1 ; target <= x ; target++){
        int finalAns = 0;
        for (int idx = 0 ; idx < n ; idx++){

            if (target - arr[idx] >= 0){
                int ans = dp[target - arr[idx]];
                finalAns =  (finalAns%mod + ans%mod)%mod;
            }
        }

        dp[target] = finalAns%mod;
    }

    cout << dp[x] << endl;
}
 
signed main(){
    
    // input output 
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    // main
    int t = 1;
    // cin >> t;
 
    while (t--){
        solve();
    }
    
    // calculate time of execution
    #ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
}