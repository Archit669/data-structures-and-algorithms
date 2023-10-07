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
// approach-1 (recursive + memoization) [TLE]
int editDistance(string& s1, string& s2){

    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
    
    function<int(int,int)> f = [&](int ptr1, int ptr2){

        if (ptr1 == 0 && ptr2 == 0) 
            return 0LL;

        if (ptr1 == 0 || ptr2 == 0) 
            return abs(ptr1 - ptr2);

        if (dp[ptr1][ptr2] != -1) return dp[ptr1][ptr2];

        if (s1[ptr1-1] == s2[ptr2-1]) 
            return dp[ptr1][ptr2] = f(ptr1-1 , ptr2-1);

        // add
        int op1 = 1 + f(ptr1, ptr2-1);
        // remove
        int op2 = 1 + f(ptr1-1, ptr2);
        // replace
        int op3 = 1 + f(ptr1-1, ptr2-1);

        return dp[ptr1][ptr2] = min({op1, op2, op3});
    };

    int ans = f(n1, n2);
    
    return ans;
}

*/


// approach-2 (tabulation)
int editDistance(string& s1, string& s2){

    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    for (int ptr1 = 0 ; ptr1 <= n1 ; ptr1++){
        dp[ptr1][0] = ptr1;
    }

    for (int ptr2 = 0 ; ptr2 <= n2 ; ptr2++){
        dp[0][ptr2] = ptr2;
    }

    for (int ptr1 = 1 ; ptr1 <= n1 ; ptr1++){
        for (int ptr2 = 1; ptr2 <= n2; ptr2++){
            if (s1[ptr1-1] == s2[ptr2-1]) 
                dp[ptr1][ptr2] = dp[ptr1-1][ptr2-1];
            else{
                // add
                int op1 = 1 + dp[ptr1][ptr2-1];
                // remove
                int op2 = 1 + dp[ptr1-1][ptr2];
                // replace
                int op3 = 1 + dp[ptr1-1][ptr2-1];

                dp[ptr1][ptr2] = min({op1, op2, op3});
            }
        }
    }

    int ans = dp[n1][n2];
    return ans;
}

void solve(){
    string s1,s2;
    cin >> s1 >> s2;

    cout << editDistance(s1,s2) << endl;
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

 

