#include <bits/stdc++.h>
using namespace std;

// approach-1
class Solution {
    bool solve(int n,bool ans = 0){
        if (n<=0)   return 0;
        if (n==1)   return 1;
        if (n%4==0){
            n = n/4;
            ans = solve(n,ans);
        }
        
        return ans;
    }
public:
    bool isPowerOfFour(int n) {
        return solve(n);
    }
};

// approach -2

class Solution {
    bool solve(int n,bool ans = 0){
        if (n<=0) return 0;
        return (!(n&(n-1)) && ((n-1)%3==0));
    }
public:
    bool isPowerOfFour(int n) {
        return solve(n);
    }
};