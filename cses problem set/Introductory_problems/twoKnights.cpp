// approch -1 (bruteforce)

// #include <bits/stdc++.h>
// using namespace std;

// int dp[10001];

// int invalidCombinations(int n){
//     int xdir[8] = {-2, -1, 1, 2, 2, 1, -1 ,2};
//     int ydir[8] = {-1,-2,-2, -1, 1, 2, 2, 1};

//     int count = 0;

//     for (int row = 0 ; row < n ; row++){
//         for (int col = 0; col < n ; col++){
//             for (int dir = 0; dir < 8 ; dir++){
//                 int newRow = row + xdir[dir];
//                 int newCol = col + ydir[dir];

//                 if
                
//                  (newRow < 0 || newCol < 0 || newRow >= n || newCol >= n){
//                     continue;
//                 }

//                 count++;
//             }
//         }
//     }

//     return count / 2;
// }

// int solve(int n){
//     if (dp[n] != -1) return dp[n];
//     return dp[n] = ((n*n) * (n*n - 1) / 2) - invalidCombinations(n);
// }

// int main(){
//     int n;
//     cin >> n;

//     memset(dp, -1, sizeof(dp));

//     if (n <= 1){
//         cout << 0 << endl;
//         return 0;
//     }

//     for (int k = 1 ; k <= n ; k++){
//         cout << solve(k) << endl;
//     }

//     return 0;
// }


// optimized 

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;

    for (int i = 1 ; i <= n ; i++){
        int totalWays = i*i * (i*i -1) / 2;
        int attakingWays = 4* (i-1)*(i-2);
        cout << totalWays - attakingWays << endl;
    }
    return 0;
}