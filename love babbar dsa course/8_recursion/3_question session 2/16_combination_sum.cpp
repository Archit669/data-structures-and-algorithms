#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(vector<int> &candidates, int target, vector<int> &output, vector<vector<int>> &result, int count)
    {
        if (target == 0)
        {
            result.push_back(output);
            return;
        }

        if (target < 0 || count > candidates.size())
        {
            return;
        }

        for (int i = count; i < candidates.size(); i++)
        {
            output.push_back(candidates[i]);
            solve(candidates, target - candidates[i], output, result, i);
            output.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> output;

        solve(candidates, target, output, result, 0);

        return result;
    }
};