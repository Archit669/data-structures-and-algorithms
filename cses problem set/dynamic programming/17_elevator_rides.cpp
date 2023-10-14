#include<bits/stdc++.h>
using namespace std;
#define int long long

// approach -1 (naive approach)
// (recursion + memoization)
/**
 * dp[mask][remainWeight]
 * mask represent people that needs to get to the top
 * remainWeight represent , how much weight elevator can bear
 * 
 * we need to find out , dp[(1 << n) - 1][0]
 * -(1 << n) - 1 represent the mask , in which all people need to get on top , 1111.. (mask)
 * - 0 repsent remainWeight lift can bear is 0 , so need next ride
 * 
*/

// int solve (vector<int> &w, int &n , int &x, int mask, int remainWt, vector<vector<int>> dp){
    
//     // no people need to get on top, so 0 elevator ride is needed
//     if (mask == 0){
//         return 0;
//     }

//     if (dp[mask][remainWt] != -1) return dp[mask][remainWt];

//     // calulate the minimum no of rides
//     int ans = n;
//     // i represent the index of every person
//     for (int i = 0 ; i < n ; i++){
//         // check if ith bit is set or not
//         if ((1 << i) & mask){
//             // off the ith bit
//             int newMask = ~(1 << i) & (mask);

//             // check if the person weight is less than or equal to remaining weight
//             if (w[i] <= remainWt){
//                 // person can go to the lift
//                 ans = min(ans, solve(w, n, x, newMask, remainWt - w[i], dp));
//             }else{
//                 // need another ride
//                 ans = min(ans, 1 + solve(w, n, x, newMask , x - w[i], dp));
//             }
//         }
//     }  

//     return dp[mask][remainWt] = ans; 
// }

// void Archit(){
//     int n,x;
//     cin >> n >> x;

//     vector<int> w(n);
//     for (auto &x : w){
//         cin >> x;
//     }

//     vector<vector<int>> dp((1 << n), vector<int>(x+1, -1));

//     cout << solve(w, n, x, (1 << n)-1 , 0, dp) << endl;
// }
 

// approach -2 (approach-1 tabulation)
/**
 * dp[mask][remainWeight]
 * mask represent people that needs to get to the top
 * remainWeight represent , how much weight elevator can bear
 * 
 * we need to find out , dp[(1 << n) - 1][0]
 * -(1 << n) - 1 represent the mask , in which all people need to get on top , 1111.. (mask)
 * - 0 repsent remainWeight lift can bear is 0 , so need next ride
 * 
*/

// time complexity - n*x*2^n
// space complexity - x*2^n
// void Archit(){
//     int n,x;
//     cin >> n >> x;

//     vector<int> w(n);
//     for (auto &x : w){
//         cin >> x;
//     }

//     vector<vector<int>> dp((1 << n), vector<int>(x+1, 0));

//     for (int mask = 1 ; mask < (1 << n) ; mask++){
//         for (int remainWt = x ; remainWt >= 0 ; remainWt--){
//             // calulate the minimum no of rides
//             int ans = n;
//             // i represent the index of every person
//             for (int i = 0 ; i < n ; i++){
//                 // check if ith bit is set or not
//                 if ((1 << i) & mask){
//                     // off the ith bit
//                     int newMask = ~(1 << i) & (mask);

//                     // check if the person weight is less than or equal to remaining weight
//                     if (w[i] <= remainWt){
//                         // person can go to the lift
//                         ans = min(ans, dp[newMask][remainWt - w[i]]);
//                     }else{
//                         // need another ride
//                         ans = min(ans, 1 + dp[newMask][x - w[i]]);
//                     }
//                 }
//             }  

//             dp[mask][remainWt] = ans; 
//         }
//     }

//     cout << dp[(1 << n)-1][0] << endl;
// }

// approach -3 (optimization)
// independence from maxWt

/**
 * 
 * In previous approach , the tle or runtime error was coming due to second changing state remainWeight
 * dp[mask][remainWeight]
 * -mask represent people that needs to get to the top
 * -remainWeight represent , how much weight elevator can bear
 * 
 * we need to find out , dp[(1 << n) - 1][0]
 * -(1 << n) - 1 represent the mask , in which all people need to get on top , 1111.. (mask)
 * - 0 repsent remainWeight lift can bear is 0 , so need next ride
 * 
 * so we have to eliminate the second changing state
 * dp[mask] 
 * it will return  a pair
 *  1) the minimum no of rides for a given mask.
 *  2) remainWeight
 * 
*/

// // time complexity - n*2^n
// // space complexity - 2^n
// pair<int,int> solve (vector<int> &w, int &n , int &x, int mask,vector<pair<int,int>> &dp){
    
//     // no people need to get on top, so 0 elevator ride is needed
//     if (mask == 0){
//         return {0,0};
//     }

//     if (dp[mask].first != -1) return dp[mask];

//     // calulate the minimum no of rides
//     int ansRides = n; int ansRemainWt = 0;
//     // i represent the index of every person
//     for (int i = 0 ; i < n ; i++){
//         // check if ith bit is set or not
//         if ((1 << i) & mask){
//             // off the ith bit
//             int newMask = ~(1 << i) & (mask);

//             auto [rides, remainWt] = solve(w, n, x, newMask , dp);

//             // check if the person weight is less than or equal to remaining weight
//             if (w[i] <= remainWt){
//                 // person can go to the lift
//                remainWt = remainWt - w[i];
//             }else{
//                 // need another ride
//                 rides++;
//                 remainWt = x - w[i];
//             }

//             // update the minimum no of rides and max remaining weight of the lift
//             if (ansRides > rides || (ansRides == rides && ansRemainWt < remainWt)){
//                 ansRides = rides;
//                 ansRemainWt = remainWt;
//             }
//         }
//     }  

//     // return the {minimum rides, maxRemainWt}
//     return dp[mask] = {ansRides, ansRemainWt}; 
// }


// void Archit(){
//     int n,x;
//     cin >> n >> x;

//     vector<int> w(n);
//     for (auto &x : w){
//         cin >> x;
//     }

//     vector<pair<int,int>> dp(1 << n, pair<int,int>(-1,-1));

//     cout << solve(w, n, x, (1 << n)-1 ,dp).first << endl;
// }


// approach -4 (approach-3 tabulation)
// independence from maxWt

/**
 * 
 * In previous approach , the tle or runtime error was coming due to second changing state remainWeight
 * dp[mask][remainWeight]
 * -mask represent people that needs to get to the top
 * -remainWeight represent , how much weight elevator can bear
 * 
 * we need to find out , dp[(1 << n) - 1][0]
 * -(1 << n) - 1 represent the mask , in which all people need to get on top , 1111.. (mask)
 * - 0 repsent remainWeight lift can bear is 0 , so need next ride
 * 
 * so we have to eliminate the second changing state
 * dp[mask] 
 * it will return  a pair
 *  1) the minimum no of rides for a given mask.
 *  2) remainWeight
 * 
*/

void Archit(){
    int n,x;
    cin >> n >> x;

    vector<int> w(n);
    for (auto &x : w){
        cin >> x;
    }

    vector<pair<int,int>> dp(1 << n, pair<int,int>(0,0));
    for (int mask = 1 ; mask < (1 << n) ; mask++){

        // calulate the minimum no of rides for each mask
        int ansRides = n; int ansRemainWt = 0;
        // i represent the index of every person
        for (int i = 0 ; i < n ; i++){
            // check if ith bit is set or not
            if ((1 << i) & mask){
                // off the ith bit
                int newMask = ~(1 << i) & (mask);

                auto [rides, remainWt] = dp[newMask];

                // check if the person weight is less than or equal to remaining weight
                if (w[i] <= remainWt){
                    // person can go to the lift
                remainWt = remainWt - w[i];
                }else{
                    // need another ride
                    rides++;
                    remainWt = x - w[i];
                }

                // update the minimum no of rides and max remaining weight of the lift
                if (ansRides > rides || (ansRides == rides && ansRemainWt < remainWt)){
                    ansRides = rides;
                    ansRemainWt = remainWt;
                }
            }
        }

        // return the {minimum rides, maxRemainWt}
       dp[mask] = {ansRides, ansRemainWt}; 
    }

    cout << dp[(1<<n)-1].first << endl;
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