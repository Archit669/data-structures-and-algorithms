#include <bits/stdc++.h>
using namespace std;

class Solution {
    void solve(vector<char>& s, int i , int j){
        if (i>=j){
            return;
        }
        swap(s[i++],s[j--]);
        solve(s,i,j);
    }
public:
    void reverseString(vector<char>& s) {
        solve(s,0,s.size()-1);
    }
};