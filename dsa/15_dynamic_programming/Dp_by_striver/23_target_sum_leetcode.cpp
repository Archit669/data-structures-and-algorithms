#include <bits/stdc++.h>
using namespace std;

class Solution {
    int findWays(vector<int> &num, int tar)
    {
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

                curr[target] = pick + unpick;
            }
            
            next = move(curr);
        }

        return next[tar];
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum + target < 0 ) return 0;
        return (sum+target)%2 == 0 ? findWays(nums, (sum + target)/2) : 0;
    }
};