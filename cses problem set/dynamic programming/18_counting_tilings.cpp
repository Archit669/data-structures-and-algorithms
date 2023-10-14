#include<bits/stdc++.h>
using namespace std;
#define int long long
int M=1e9+7;

// the main dp optimal substructure of the problem is 
// dp(i, mask)
//      it denotes the no of ways to fill the entire grid from ith col to last col

// and we have to find out dp(1,0)
// 1 based indexing


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
    int t = 1; 
    while (t--) Archit();
}