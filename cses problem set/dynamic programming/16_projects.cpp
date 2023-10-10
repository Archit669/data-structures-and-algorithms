/*
// approach-1 (memoization)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

//-----------------------------------------------------
int M=1e9+7;
int po(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int inv(int x){ return po(x,M-2,M);}
int add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mult(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int div1(int x, int y){ return mult(x,inv(y),M); }
//-----------------------------------------------------

 
void Archit(){
    int n;
    cin >> n;

    vector<array<int,3>> v;
    for (int idx = 0 ; idx < n ; idx++){
        int a, b,c;
        cin >> a >> b >> c;
        v.push_back({a,b,c});
    }

    sort(v.begin(), v.end());

    vector<int> dp(n+1,-1);

    function<int(int)> solve = [&](int curr){
        if (curr == n) return 0LL;

        if (dp[curr] != -1) return dp[curr];
        
        int idx = upper_bound(v.begin()+curr+1, v.end(), v[curr], [&](auto &ac, auto &x){
            return ac[1] < x[0];
        })- v.begin();
        
        int pick = v[curr][2] + solve(idx);
        int notPick = solve(curr+1);
        return dp[curr] = max(pick , notPick);
    };


    cout << solve(0) << endl;
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


// tabulation
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
 
/*-----------------------------------------------------*/
int M=1e9+7;
int po(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int inv(int x){ return po(x,M-2,M);}
int add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mult(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int div1(int x, int y){ return mult(x,inv(y),M); }
/*-----------------------------------------------------*/
 
 
void Archit(){
    int n;
    cin >> n;
 
    vector<array<int,3>> v;
    for (int idx = 0 ; idx < n ; idx++){
        int a, b,c;
        cin >> a >> b >> c;
        v.push_back({a,b,c});
    }
 
    sort(v.begin(), v.end());
 
    vector<int> dp(n+1,0);
 
    for (int curr = n-1 ; curr >= 0 ; curr--){
        int idx = upper_bound(v.begin()+curr+1, v.end(), v[curr], [&](auto &ac, auto &x){
            return ac[1] < x[0];
        })- v.begin();
        int pick = v[curr][2] + dp[idx];
        int notPick = dp[curr+1];
 
        dp[curr] = max(pick , notPick);
    }
 
    cout << dp[0] << endl;
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