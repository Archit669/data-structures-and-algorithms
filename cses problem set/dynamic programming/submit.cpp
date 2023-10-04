#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define int unsigned long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define mod 1000000007

void solve(){

    int n , m;
    cin >> n >> m;

    vector<int> arr(n);
    
    for (auto &x : arr){
        cin >> x;
    }

    vector<int> prev(m+1);
    if (arr[0] != 0){
        prev[arr[0]] = 1; 
    }else{
        for (int idx = 1; idx <= m ; idx++){
            prev[idx] = 1; 
        }
    }


    for (int idx = 1 ; idx < n ; idx++){
        vector<int> curr(m+1);
        for (int jdx = 1 ; jdx <= m ; jdx++){
            if (arr[idx] != 0 && jdx != arr[idx]){
                continue;
            }else{
                curr[jdx] = (prev[jdx]%mod + prev[jdx-1]%mod)%mod;
                if (jdx+1 <= m){
                    curr[jdx] = (curr[jdx]%mod + prev[jdx+1]%mod)%mod;
                }
            }
        }

        prev = curr;
    }

   
    int ans = 0;
    for (int idx = 0 ; idx <= m; idx++){
        ans = (ans%mod + prev[idx]%mod)%mod;
    }

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