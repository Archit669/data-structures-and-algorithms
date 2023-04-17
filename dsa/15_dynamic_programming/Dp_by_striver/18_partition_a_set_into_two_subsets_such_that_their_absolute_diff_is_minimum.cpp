#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int k = accumulate(arr.begin(), arr.end() , 0);
	vector<bool> next(k+1, false);
    
    next[0] = true;
    
    for (int index = n-1 ; index >= 0 ; index--){
        vector<bool> curr(k+1, false);
        for (int target = k ; target >= 0 ; target--){
            bool pick = false;
            if (target - arr[index] >= 0) {
                pick = next[target-arr[index]];
            }

            bool unpick = next[target];

            curr[target] = pick || unpick;
        }

        next = move(curr);
    }

	// now next array will tell me that 0 to k which target is possible or not

	int mini = INT_MAX;
	for (int idx = 0 ; idx < next.size() ; idx++){
		if (next[idx]) mini = min(abs((k - 2*idx)), mini);
	}

	return mini;
}