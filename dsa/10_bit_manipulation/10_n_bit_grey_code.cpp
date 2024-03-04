#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 1) return {0,1};
        
        vector<int> ans = grayCode(n-1);
        vector<int> temp = ans;

        reverse(temp.begin(), temp.end());

        for (auto x : temp){
            ans.push_back(x | (1 << (n-1)));
        }

        return ans;
    }
};