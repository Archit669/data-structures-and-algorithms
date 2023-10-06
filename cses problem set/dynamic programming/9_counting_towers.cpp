/*

// approach-1 recursively (giving tle)
void solve(){
    int n;
    cin >> n;

    vector<vector<int>> dp(1e6+1, vector<int>(2,-1));

    function<int(int,int)> f = [&](int pos, int linkStatus){
        if (pos == n){
            return 1LL;
        }

        if (dp[pos][linkStatus] != -1) return dp[pos][linkStatus];

        // option for if current pos, has unlink(double) tiles
        if (linkStatus == 0){
            // do not extend
            int op1 = f(pos+1, 1) + f(pos+1, 0);
            // extend both
            int op2 = f(pos+1, 0);
            // extend one of these
            int op3 = 2*f(pos+1, 0);

            return dp[pos][linkStatus] = (op1%mod + op2%mod + op3%mod)%mod;
        }else{
            // do not extend
            int op1 = f(pos+1, 1) + f(pos+1 , 0);
            // extend
            int op2 = f(pos+1, 1);

            return dp[pos][linkStatus] = (op1%mod + op2%mod)%mod;
        }
    };

    cout << f(1, 0) + f(1, 1) << endl;
}

signed main(){
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
}


// approach -2 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define mod 1000000007

// dp[i] represent the no of ways to fill a tower from i till n (height of tower)
// dp[i][0] represent that the tile place at ith position are two single(1*1) tiles
// dp[i][1] represent that the tile place at ith position is one double (2*1) tile
vector<vector<int>> dp(1e6+1, vector<int>(2,-1));


// precomputation of the highest tower possible
// no of ways to fill a tower of height 10^6
void solve(){
    int n = 1e6;
    // base case
    // no of ways to fill a tower from nth position to n 
    // there will be 1(unlink tiles) + 1(linked tile) = 2 ways
    dp[n][0] = dp[n][1] = 1;

    // compute no of ways  to fill tower for each pos from pos to n
    for (int pos = n-1; pos >= 1 ; pos--){

        // cases for unlink tiles

        // do not extend
        int op1 = dp[pos+1][1] + dp[pos+1][0];
        // both extend
        int op2 = dp[pos+1][0];
        // extend one of these
        int op3 = 2*dp[pos+1][0];

        // calc no of ways (if we place two single tiles at curr pos)
        dp[pos][0] = (op1%mod + op2%mod + op3%mod)%mod;


        // cases for double tile(linked tile)
        op2 = dp[pos+1][1];

        // calc no of ways (if we place one double tile at curr pos)
        dp[pos][1] = (op1%mod + op2%mod)%mod;
    }

}
 
signed main(){
    
    // input output 
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();
 
    // main
    int t = 1;
    cin >> t;

    while (t--){

        // take the height of tower
        int n;
        cin >> n;

        // calculate the no of ways to fill tower of given height
        // use dp table wisely to calculate it
        cout << (dp[(int)1e6 - n + 1][0]%mod + 
                dp[(int)1e6 - n + 1][1]%mod)%mod << endl;
    }
    
    // calculate time of execution
    #ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
}

*/

// approach -3 (change above solution little bit to make sense of dp table)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define mod 1000000007

// dp[i] represent the no of ways to fill a tower of length i
// dp[i][0] represent the no of ways to fill a tower of length i ending with two single unliked tiles
// dp[i][1] represent the no of ways to fll a tower of length i ending with one single (linked) tile
vector<vector<int>> dp(1e6+1, vector<int>(2,-1));

void solve(){

    // base case 
    // no of ways to fill a tower of length 1 end with two unlink tile is 1
    // no of ways to fill a tower of length 1 end with one (link - 2*1) tile is 1
    dp[1][0] = dp[1][1] = 1;

    // compute no of ways for tower of length pos
    for (int pos = 2; pos <= (int)(1e6) ; pos++){

        // compuation for no of ways to end with two single tiles
        
        // do not extend previous tiles
        int op1 = dp[pos-1][1] + dp[pos-1][0];
        // extend both
        int op2 = dp[pos-1][0];
        // extend either of them
        int op3 = 2*dp[pos-1][0];

        dp[pos][0] = (op1%mod + op2%mod + op3%mod)%mod;


        // computations for no of ways to end with double tile
        // op1 is same (do not extend previous tile)
        // op2 is extend the double tile
        op2 = dp[pos-1][1];

        dp[pos][1] = (op1%mod + op2%mod)%mod;
    }

}
 
signed main(){
    
    // input output 
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();
 
    // main
    int t = 1;
    cin >> t;

    while (t--){

        // take the height of tower
        int n;
        cin >> n;

        // calculate the no of ways to fill tower of given height
        // use dp table wisely to calculate it
        cout << (dp[n][0]%mod + 
                dp[n][1]%mod)%mod << endl;
    }
    
    // calculate time of execution
    #ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
}

 

