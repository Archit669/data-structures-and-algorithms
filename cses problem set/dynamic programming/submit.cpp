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

void generateAllNextMasks(int currMask, int nextMask, int currRow, vector<int>& nextMasks, int rows){
    
    // traverse all rows
    if (currRow == rows+1){
        nextMasks.push_back(nextMask);
        return;
    }

    // if my current row cell is empty
    if ((currMask & (1 << currRow)) == 0){
        // place one horizontal tile
        generateAllNextMasks(currMask, (nextMask | (1 << currRow)), currRow + 1, nextMasks, rows);
    }

    // if my current row and my next row cell both are empty
    if (currRow != rows){
        if ( (currMask & (1 << currRow)) == 0 && (currMask & (1 << (currRow+1))) == 0){
            // place an vertical tile
            generateAllNextMasks(currMask, nextMask, currRow + 2, nextMasks, rows);
        }
    }

    // if my current row cell is not empty
    if ((currMask & (1 << currRow)) != 0){
        // place one horizontal tile
        generateAllNextMasks(currMask, nextMask, currRow + 1, nextMasks, rows);
    }
}   



void Archit(){

    int n,m;
    cin >> n >> m;

    // vector<vector<int>> dp(m+1, vector<int>(1 << 11, -1));
    vector<map<int,int>> dp(m+1);

    function<int(int,int)> solve;
    solve = [&](int currCol, int currMask){
        if (currCol == m+1){
            if (currMask == 0LL){
                return 1LL;
            }else{
                return 0LL;
            }
        }

        if (dp[currCol].count(currMask)) return dp[currCol][currMask];

        // generate all next masks 
        vector<int> nextMasks;
        /* param {
            currMask
            nextMask
            currRow
            all nextMasks
        }*/

        generateAllNextMasks(currMask,0,1,nextMasks, n);


        // find all possible ways
        int answer = 0;

        for (int &nextMask : nextMasks){
            answer = (answer%M + solve(currCol+1, nextMask)%M)%M;
        }

        return dp[currCol][currMask] = answer%M;
    };

    cout << solve(1, 0) << endl;
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