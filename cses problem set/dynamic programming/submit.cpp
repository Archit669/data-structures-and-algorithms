#include<bits/stdc++.h>
using namespace std;
#define int long long

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