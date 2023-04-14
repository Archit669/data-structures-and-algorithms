#include <bits/stdc++.h>
using namespace std;

// memoization
int maxPoints(vector<vector<int>> &points, int day , int last, vector<vector<int>> &dp){

    // base case
    if (day < 0) return 0;

    if (dp[day][last] != -1){
        return dp[day][last];
    }

    int ans = 0;
    for (int i = 0 ; i < 3 ; i++){
        if (i != last) {
             ans = max(points[day][i] + maxPoints(points, day-1, i, dp), ans);
        }
    }

    return dp[day][last] = ans;
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return maxPoints(points, n-1, 3, dp);
}



// tabulation
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][1], max(points[0][2], points[0][1]));

    for (int day = 1; day < n ; day++){
       for (int last = 0 ; last < 4 ; last++){
           dp[day][last] = 0;
           for (int i = 0 ; i < 3 ; i++){
                if (i != last) {
                   dp[day][last] = max(points[day][i] + dp[day-1][i], dp[day][last]);
                }
            }
       }
    }

    return dp[n-1][3];
}


// space optimization
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, -1);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][1], max(points[0][2], points[0][1]));

    for (int day = 1; day < n ; day++){
       vector<int> temp(4, -1);
       for (int last = 0 ; last < 4 ; last++){
           temp[last] = 0;
           for (int i = 0 ; i < 3 ; i++){
                if (i != last) {
                   temp[last] = max(points[day][i] + prev[i], temp[last]);
                }
            }
       }
       
       prev = temp;
    }

    return prev[3];
}