#include <bits/stdc++.h> 
#define M 1000000007
using namespace std;

int countPartitions(int n, int d, vector<int> &num) {

    int sum = accumulate(num.begin(), num.end() , 0);
    int tar = sum;

    vector<int> next(tar+1, 0);
    next[0] = 1;
    
    for (int index = num.size()-1 ; index >= 0 ; index--){
        vector<int> curr(tar+1, 0);
        for (int target = 0 ; target <= tar ; target++){
            int pick = 0;
            if (target - num[index] >= 0){
                pick = next[target - num[index]];
            }

            int unpick = next[target];

            curr[target] = (pick + unpick)%M;
        }
        
        next = move(curr);
    }

    
    int ans = 0;

    for (int idx = 0 ; idx < next.size() ; idx++){
        if (sum - 2*idx == d){
            ans+= (next[idx]) % M;
        }
    }

    return ans;
}


