#include <bits/stdc++.h>
using namespace std;

class Solution {
    void solve(vector<int> &candidates, int target, vector<int> &output, vector<vector<int>> &result, int count,int k)
    {
        if (target == 0)
        {
            if (output.size()==k)
                result.push_back(output);
            return;
        }

        if (target < 0 || count > candidates.size())
        {
            return;
        }

        for (int i = count; i < candidates.size(); i++)
        {
            
            if (i > count && candidates[i] == candidates[i-1]) continue;
            
            if (candidates[i] > target) break;
            
            
            output.push_back(candidates[i]);
            solve(candidates, target - candidates[i], output, result, i+1,k);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<int> candidates(9);
        for (int i = 1 ; i <= 9 ; i++){
            candidates[i-1] = i;
        }
        vector<vector<int>> result;
        sort(candidates.begin(),candidates.end());
        vector<int> output;

        solve(candidates, target, output, result, 0 , k);

        return result;
    }
};