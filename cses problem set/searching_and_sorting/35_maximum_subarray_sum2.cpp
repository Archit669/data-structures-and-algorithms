#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define MOD 1000000007


void solve(){

    int n, a, b;
    cin >> n >> a >> b;

    // take input array
    vector<int> arr(n+1);
    for (int idx = 1; idx <= n; idx++){
        cin >> arr[idx];
    }

    // calcualte the prefix array
    for (int idx = 1 ; idx <= n ; idx++){
        arr[idx] = arr[idx] + arr[idx-1];
    }

    set<pair<int,int>> s;
    
    // insert first b-a+1 values in set
    for (int idx = a; idx <= b ; idx++){
        s.insert({arr[idx], idx});
    }

    int maxSum = LLONG_MIN;

    // now calculate for each window
    for (int idx = 1 ; idx <= n-a+1; idx++){
        maxSum = max(maxSum, s.rbegin()->first - arr[idx-1]);
        s.erase({arr[idx+a-1], idx+a-1});
        if (idx + b <= n){
            s.insert({arr[idx+b], idx+b});
        }
    }

    cout << maxSum << endl;
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