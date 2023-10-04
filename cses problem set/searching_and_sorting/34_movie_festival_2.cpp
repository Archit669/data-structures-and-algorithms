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

    int n, k;
    cin >> n >> k;

    // take input array
    vector<pair<int,int>> arr(n);
    for (int idx = 0; idx < n; idx++){
        cin >> arr[idx].first;
        cin >> arr[idx].second;
    }

    set<pair<int,int>> s;
    sort(arr.begin(), arr.end(), [&](auto& a, auto& b){
        return a.second < b.second;
    });

    int count = 0;

    for (int idx = 0; idx < n ; idx++){
        if (s.size() == 0){
            s.insert({-1LL * arr[idx].second,idx});
        }else{
            auto it = s.lower_bound({-1LL*arr[idx].first, -1});
            if (it != s.end()){
                s.erase(it);
                s.insert({-1LL*arr[idx].second, idx});
            }else if(it == s.end() && s.size() < k){
                s.insert({-1LL*arr[idx].second, idx});
            }else{
                count++;
            }
        }
    }

    cout << n-count << endl;

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