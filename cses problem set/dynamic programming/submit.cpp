#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define mod 1000000007
 
 
void Archit(){
    int n;
    cin >> n;
 
    vector<int> arr(n);
    int sum = 0;
    for (int idx = 0 ; idx < n ; idx++){
        arr[idx] = idx+1;
        sum += arr[idx];
    }
 
    vector<vector<int>> dp(n+1, vector<int>(sum/2+1,-1));
 
    function<int(int,int)> f = [&](int idx, int target){
        if (idx == (int)(arr.size())){
            if (target == 0){
                return 1LL;
            }else{
                return 0LL;
            }
        }
 
        if (dp[idx][target] != -1) return dp[idx][target];
 
        int pick = 0;
        if (target - arr[idx] >= 0){
            pick = f(idx+1, target - arr[idx]);
        }
        
        int unpick = f(idx+1, target);
 
        return dp[idx][target] = (pick%mod + unpick%mod)%mod;
    };
 
    if (sum % 2 != 0) cout << 0 << endl;
    else cout << f(0, sum/2)/2 << endl;
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
        Archit();
    }
    
    // calculate time of execution
    #ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
}