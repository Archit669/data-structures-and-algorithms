#include <bits/stdc++.h>
using namespace std;

// recursion
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1){
            return 0;
        }

        if (m == 1 && n == 1){
            return 1;
        }

        return  uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }
};

// memoization
class Solution {
    int solve(int m , int n, vector<vector<int>> &dp){
        if (m == 0 && n == 0){
            return 1;
        }

        if (m < 0 || n < 0){
            return 0;
        }

        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        return dp[m][n] = solve(m-1, n, dp) + solve(m, n-1, dp);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n, -1));
        return solve(m-1 , n-1, dp);
    }
};

// tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                if (i == 0 && j == 0){
                    dp[i][j] = 1;
                }else{
                    if (i-1 >= 0)
                        dp[i][j] += dp[i-1][j];
                    if (j-1 >= 0)
                        dp[i][j] += dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};

// space optimization 1
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> pre(n,0);
        for (int i = 0 ; i < m ; i++){
            vector<int> curr(n,0);
            for (int j = 0 ; j < n ; j++){
                if (i == 0 && j == 0){
                    curr[j] = 1;
                }else{
                    if (i-1 >= 0)
                        curr[j] += pre[j];
                    if (j-1 >= 0)
                        curr[j] += curr[j-1];
                }
            }

            pre = move(curr);
        }

        return pre[n-1];
    }
};

// space optimization 2
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> pre(n,1);
        for (int i = 1 ; i < m ; i++){
            for (int j = 1; j < n ; j++){
                pre[j] += pre[j-1];
            }
        }

        return pre[n-1];
    }
};

// combinatorics solution
// in python for better understand of formula
// class Solution:
//     def uniquePaths(self, m: int, n: int) -> int:
//         return int(factorial(n+m-2) / (factorial(m-1) * factorial(n-1)));


// combinatorics solution in cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n -2;
        int r = m-1;

        double res = 1;

        for (int i = 1 ; i <= r ; i++){
            res = res* (N-r+i)/i;
        }

        return (int) res;
    }
};