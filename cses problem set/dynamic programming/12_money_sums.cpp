/*

// approach-1 (tle in 1 testcase)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define mod 1000000007


map<int,set<int>> dp;

set<int> solve(int idx, vector<int> &arr){
    if (idx == (int)arr.size()){
        return {0};
    }

    if (dp.find(idx) != dp.end()) return dp[idx];

    set<int> ans = solve(idx+1, arr);

    set<int> finalAns;
    for (auto x : ans){
        finalAns.insert(x + arr[idx]);
        finalAns.insert(x);
    }

    return dp[idx] = finalAns;
}

void Archit(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int idx = 0 ; idx < n ; idx++){
        cin >> arr[idx];
    }

    auto ans = solve(0, arr);
    ans.erase(0);

    cout << ans.size() << endl;

    for (auto &x : ans){
        cout << x << " ";
    }cout << endl;

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


// approach-3 (recursion + memoization optimized)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define mod 1000000007


vector<set<int>> dp;

set<int> &solve(int idx, vector<int> &arr){
    if (idx == (int)arr.size()){
        set<int> s;
        s.insert(0);
        return dp[idx] = s;
    }

    if (dp[idx].size() > 0) return dp[idx];

    set<int> &ans = solve(idx+1, arr);

    set<int> finalAns;
    for (auto x : ans){
        finalAns.insert(x + arr[idx]);
        finalAns.insert(x);
    }

    return dp[idx] = finalAns;
}

void Archit(){
    int n;
    cin >> n;

    dp = vector<set<int>>(n+1);

    vector<int> arr(n);
    for (int idx = 0 ; idx < n ; idx++){
        cin >> arr[idx];
    }

    auto &ans = solve(0, arr);
    ans.erase(0);

    cout << ans.size() << endl;

    for (auto &x : ans){
        cout << x << " ";
    }cout << endl;

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

*/

// approach-2 (tabulation)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define mod 1000000007

map<int,set<int>> dp;

void Archit(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int idx = 0 ; idx < n ; idx++){
        cin >> arr[idx];
    }

    vector<set<int>> dp(n+1);
    dp[n] = {0};

    for (int idx = n-1 ; idx >= 0 ; idx--){
        set<int> &ans = dp[idx+1];
        set<int> finalAns;
        for (auto x : ans){
            finalAns.insert(x + arr[idx]);
            finalAns.insert(x);
        }

        dp[idx] = finalAns;
    }

    auto &ans = dp[0];
    ans.erase(0);

    cout << ans.size() << endl;

    for (auto &x : ans){
        cout << x << " ";
    }cout << endl;

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

 

