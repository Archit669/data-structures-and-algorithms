#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    void solve(vector<int>& nums , vector<vector<int>> &ans, int i=0){
        if (i == nums.size()-1){
            ans.push_back(nums);
            return;
        }
        
        for (int k = i ; k < nums.size() ; k++){
            swap(nums[i],nums[k]);
            solve(nums,ans, i+1);
            swap(nums[i],nums[k]);
            
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,ans);
        return ans;
    }
};