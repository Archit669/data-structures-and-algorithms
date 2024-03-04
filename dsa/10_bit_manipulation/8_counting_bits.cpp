#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // the main intuition is 
    // 0000 -> 0 -> dp[0] = dp[0]
    // 0001 -> 1 -> dp[1] = 1 + dp[0] = 1 + dp[1 - offset] , offset is val of msb
    // 0010 -> 1 -> dp[2] = 1 + dp[2-2]
    // 0011 -> 2 - >dp[3] = 1 + dp[3-2]
    // 0100 -> 1 -> dp[4] =  1 + dp[4 -4] 
    // 0101 -> 2 -> dp[5] = 1 + dp[5-4]
    // 0110 -> 2 -> dp[6] = 1 + dp[6-4] 
    // 0111 -> 3 -> dp[7] = 1 + dp[7-4] 
    // 1000 -> 1 -> dp[8] = 1 + dp[8-8] 
    // 1001 -> 2 -> dp[9] = 1 + dp[9-8] 
   
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        int offset = 1;

        for (int num = 1 ; num <= n ; num++){
            if (2* offset == num) offset = num;
            ans[num] = 1 + ans[num - offset];
        }

        return ans;
    }
};

// the main intuition if there is even number then its half is just right shift of itself
// ans in even no last bit is zero so no bit will be lose and no of bit is same
// even
// dp[i] = dp[i/2]
// for odd the left shift will lose lsb so we add it 
// odd
// dp[i] = dp[i/2] + 1

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for (int i = 1 ;i <= n ; i++){
            if (i&1) ans[i] = ans[i/2] + 1;
            else ans[i] = ans[i/2];
        }
        return ans;
    }
};