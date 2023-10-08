
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

    for (auto &x : arr){
        cin >> x;
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1,-1));

    function<int(int,int)> f = [&](int idx, int jdx){
        if (idx > jdx) return 0LL;
        if (idx == jdx) return arr[idx];
        if (dp[idx][jdx] != -1) return dp[idx][jdx];
        int op1 = arr[idx] + min(f(idx+2, jdx), f(idx+1, jdx-1));
        int op2 = arr[jdx] + min(f(idx, jdx-2), f(idx+1, jdx-1));

        return dp[idx][jdx] = max(op1, op2);
    };


    cout << f(0, n-1) << endl;
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