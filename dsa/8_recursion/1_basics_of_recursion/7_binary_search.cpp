#include <bits/stdc++.h>
using namespace std;

class Solution {
    int binarySearch(vector<int>& nums , int target , int start , int end){
        int ans = -1;
        if (start > end) return ans;
        
        int mid = start + (end - start)/2;
        
        if (nums[mid]==target) return mid;
        else if (nums[mid] < target){
            ans = binarySearch(nums, target , mid + 1 , end);
        }else{
            ans = binarySearch(nums, target, start , mid - 1);
        }
        
        return ans;
    }
public:
    int search(vector<int>& nums, int target) {
        return (binarySearch(nums,target,0,nums.size()-1));
    }
};