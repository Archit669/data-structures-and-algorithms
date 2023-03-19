#include <bits/stdc++.h>
using namespace std;

// using bit manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for (int i = 0 ; i < pow(2,nums.size()) ; i++){
            int num = i;
            int count = 0;
            vector<int> tmp;
            while (num){
                if (num&1){
                    tmp.push_back(nums[count]);
                }
                num = num >> 1;
                count++;
            }
            ans.push_back(tmp);
        }
        
        return ans;
    }
};


// using recursion

class Solution {
    
     void solve(vector<int> &nums,int i, vector<int> &output , vector<vector<int>> &ans){
        // base case
        if (i >= nums.size()){
            ans.push_back(output);
            return;
        } 
                       
        // exclude element
        solve(nums,i+1,output,ans);
        
        // include element
        output.push_back(nums[i]);
        solve(nums,i+1, output,ans);
         
        output.pop_back();
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        vector<vector<int>> ans;
        
        solve(nums,0,output,ans);
        return ans;
    }
};



