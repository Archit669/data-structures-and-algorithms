#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define mod 1000000007

/*

// memoizaton
void solve(){
 
    int n , x;
    cin >> n >> x;
 
    vector<int> price(n+1);
    vector<int> pages(n+1);
 
    for (int idx = 0 ; idx < n  ;idx++){
        cin >> price[idx];
    }
 
    for (int idx = 0 ; idx < n  ;idx++){
        cin >> pages[idx];
    }
 
    vector<vector<int>> dp(n+1, vector<int>(x+1,-1));
 
    function<int(int, int)> f = [&](int idx, int cost){
        if (cost == 0) return 0LL;
        if (idx == n) return 0LL;
        if (dp[idx][cost] != -1) return dp[idx][cost];
        int notTake = f(idx+1, cost);
        int take = 0;
        if (cost - price[idx] >= 0){
            take = pages[idx] + f(idx+1, cost - price[idx]);
        }
 
        return dp[idx][cost] = max(take, notTake);
    };
 
    cout << f(0, x) << endl;
}


// tabulation
void solve(){
 
    int n , x;
    cin >> n >> x;
 
    vector<int> price(n+1);
    vector<int> pages(n+1);
 
    for (int idx = 0 ; idx < n  ;idx++){
        cin >> price[idx];
    }
 
    for (int idx = 0 ; idx < n  ;idx++){
        cin >> pages[idx];
    }
 
    vector<vector<int>> dp(n+1, vector<int>(x+1,0));
 
    for (int idx = n-1 ; idx >= 0 ; idx--){
        for (int cost = 1 ; cost <= x ; cost++){
            int notTake = dp[idx+1][cost];
            int take = 0;
            if (cost - price[idx] >= 0){
                take = pages[idx] + dp[idx+1][cost - price[idx]];
            }
 
            dp[idx][cost] = max(take, notTake);
        }
    }
 
    cout << dp[0][x] << endl;
}

*/


// space optimization
void solve(){

    int n , x;
    cin >> n >> x;

    vector<int> price(n+1);
    vector<int> pages(n+1);

    for (int idx = 0 ; idx < n  ;idx++){
        cin >> price[idx];
    }

    for (int idx = 0 ; idx < n  ;idx++){
        cin >> pages[idx];
    }

    vector<int> next(x+1);
    for (int idx = n-1 ; idx >= 0 ; idx--){
        vector<int> curr(x+1);
        for (int cost = 1 ; cost <= x ; cost++){
            int notTake = next[cost];
            int take = 0;
            if (cost - price[idx] >= 0){
                take = pages[idx] + next[cost - price[idx]];
            }

            curr[cost] = max(take, notTake);
        }

        next = curr;
    }

    cout << next[x] << endl;
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