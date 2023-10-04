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
    int n;
    cin >> n;
 
    vector<int> dp(1e6 + 1 , -1);
    function<int(int)> solve = [&](int num){
        if (num == 0) return 0LL;
        if (dp[num] != -1) return dp[num];
        string currNum = to_string(num);
        int ways = 1e9;
        for (auto digit : currNum){
            int numDigit = digit - '0';
            if (numDigit != 0 && num - numDigit >= 0)
                ways = min(ways, 1 + solve(num - numDigit));
        }
 
        return dp[num] = ways;
    };
 
    int ways = solve(n);
    int ans = ways == 1e9 ? 0 : ways;
    cout << ans << endl;
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
