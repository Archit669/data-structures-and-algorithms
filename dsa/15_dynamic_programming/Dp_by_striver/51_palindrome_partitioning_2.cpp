#include <bits/stdc++.h>
using namespace std;

class Solution {

    bool isPalindrome(string &s, int idx, int jdx){

        while (idx <= jdx){
            if (s[idx] != s[jdx]) return false;
            idx++; jdx--;
        }

        return true;
    }

public:
    int minCut(string s) {
        
        vector<int> dp(s.size(), -1);

        function<int(int)> f = [&](int idx){

            if (idx == s.size()) return 0;

            if (dp[idx] != -1) return dp[idx];

            int ans = INT_MAX;

            for (int jdx = idx ; jdx < s.size() ; jdx++){

                if (isPalindrome(s, idx, jdx)){

                    int cost = 1 + f(jdx+1);

                    ans = min(cost, ans);
                }
            }

            return dp[idx] = ans;
        };

        return f(0)-1;
    }
};