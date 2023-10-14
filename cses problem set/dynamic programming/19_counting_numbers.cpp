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

/**
 * The main intuition behind the question is 
 * dp[num,N,x, leading_zeros, tight]
 * my dp represent that, how many numbers exist from 0 to Num have N digits, that follows
 * 1) property that no adjacent digits are same.
 * 2) leading digit is not equal to x.
 * 3) Is there leading-zeros
 * 4) am i under tigit constaint (currNum exceeds the upperbound which is num)
 * 
 * 
 * final Ans
 * dp[b, digs(b), -1, 1, 1] - dp[a-1, digs(a-1), -1 , 1 ,1]
*/


int dp[20][10][2][2];
int solve(string &num, int N, int x, bool leadingZeros, bool tight){
    if (N == 0){
        return 1;
    }

    if (dp[N][x][leadingZeros][tight] != -1){
        return dp[N][x][leadingZeros][tight];
    }

    int lb = 0;
    int ub = tight ? (num[num.size() - N]) - '0' : 9;

    int answer = 0;
    for (int digit = lb ; digit <= ub ; digit++){
        if (!leadingZeros &&  digit == x){
            continue;
        }

        answer += solve(num , N-1, digit , leadingZeros & (digit == 0) , tight & (digit == ub));
    }

    return dp[N][x][leadingZeros][tight] = answer;
}


void Archit(){
    int a,b;
    cin >> a >> b;

    string A = to_string(a-1);
    string B = to_string(b);

    memset(dp, -1, sizeof(dp));
    int ans1 = solve(A, A.size(), -1, 1, 1);
    memset(dp, -1, sizeof(dp));
    int ans2 = solve(B, B.size(), -1, 1, 1);

    cout << ans2 - ans1 << endl;
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