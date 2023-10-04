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
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for (int idx = 0 ; idx < n ; idx++){
        for (int jdx = 0 ; jdx < n ; jdx++){
            cin >> grid[idx][jdx];
        }
    }

    if (grid[0][0] == '*'){
        cout << 0 << endl;
        return ;
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));

    function<int(int,int)> solve = [&](int row, int col){
        if (row == n-1 && col == n-1){
            return 1LL;
        }

        if (dp[row][col] != -1) return dp[row][col];

        int right =0, down = 0;
        if (row + 1 < n && grid[row+1][col] != '*'){
            right = solve(row+1, col);
        }

        if (col + 1 < n && grid[row][col+1] != '*'){
            down = solve(row, col+1);
        }

        return dp[row][col] = (right%mod + down%mod)%mod;
    };

    cout << solve(0 ,0) << endl;
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