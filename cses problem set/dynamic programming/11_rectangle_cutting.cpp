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
    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(501, vector<int>(501,-1));

    function<int(int,int)> f = [&](int a, int b){
       // if rectangle is already a square
       if (a == b) return 0LL;
       // rotate rectange if length > bredth
       if (a > b) swap(a,b);

       if (dp[a][b] != -1) return dp[a][b];
       
       // calculate the minimum no of moves
       int finalAns = 1e9;

       // cut rectangle vertically into two rectangles
       for (int num = 1; num < b ; num++){
            int ans = 1 + f(a, num) + f(a, b-num);
            finalAns = min(ans, finalAns);
       }

       // cut rectangle horizontally into two rectangles
       for (int num = 1; num < a ; num++){
            int ans = 1 + f(num, b) + f(a-num, b);
            finalAns = min(ans, finalAns);
       }
       
       // return the minimum no of moves
       return dp[a][b] = finalAns;
    };

    int ans = f(a,b);
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

 

