#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        int m = nums.size();
        
        map<int,int> mp;
        
        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < nums[i].size() ; j++){
                mp[nums[i][j]]++;
            }
        }
        
        for (auto i:mp){
            if (i.second == m){
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};