#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> stk;
        for (auto &x : s){
            if (stk.empty() || stk.top().first != x) stk.push({x,1});
            else{
                int val = stk.top().second;
                if (val <= k )
                    stk.push({x,val+1});
            } 
            
            if (!stk.empty() && stk.top().second == k)
                for (int i = 0 ; i < k ; i++) stk.pop();
        }
        
        string ans;
        while (!stk.empty()) {
            ans+= stk.top().first;
            stk.pop();
        }
        
        reverse(begin(ans),end(ans));
        
        
        return ans;
    }
};