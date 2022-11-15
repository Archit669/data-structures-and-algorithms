#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k;

        // find index k after that array is sorted in decreasing order
        for (k = n-2 ; k >= 0 ; k--){
            if (nums[k] < nums[k+1]) break;
        }

        // it means array is already sorted in descending order
        if (k < 0) reverse(nums.begin(), nums.end());
        // find first greater than element from end than element at index k
        else{
            int l;
            for (l = n-1 ; l > k ; l--){
                if (nums[l] > nums[k]) break;
            }

            swap(nums[l], nums[k]);

            // reverse array after index k to end
            reverse(nums.begin()+k+1, nums.end());
        }
    }
};