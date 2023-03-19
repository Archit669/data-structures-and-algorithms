#include <bits/stdc++.h>

class Solution {
    // reverse positive integer
    int reverse(int x){
        int ans = 0;
        int i = 0;
        while(x){
            int digit = x%10;
            if (ans > INT_MAX/10)  break;
            ans= ans*10 + digit;
            i++;
            x = x/10;
        }
        return ans;
    }
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        if (reverse(abs(x)) == x){
            return true;
        }
        
        return false;
    }
};