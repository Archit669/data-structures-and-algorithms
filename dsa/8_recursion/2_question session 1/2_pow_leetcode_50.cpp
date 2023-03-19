#include <bits/stdc++.h>
using namespace std;

class Solution {
    double pow(double x, int n){
        if (n<=0) return 1;
        double cp = pow(x,n/2);
        if (n&1) return cp*cp*x;
        else return cp*cp;  
        return -1;
    }
public:
    double myPow(double x, int n) {
        int flag = 0;
        if (n>=0) return pow(x,n);
        if (n != -2147483648)  n = -n;
        else {
            n = -(n+1);
            flag = 1;
        }
        double res = pow(x,n);
        if (flag) res*=x;
        res = 1/res;
        return res;
    }
};