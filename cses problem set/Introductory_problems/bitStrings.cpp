#include <bits/stdc++.h>
#define M (int)(1e9 + 7)
using namespace std;

int mypow2(int n){

    if (n < 0) return 0;
    if (n == 0) return 1;

    int x = mypow2(n/2)%M;

    if (n&1){
        return((2*1LL*x)*x)%M;
    }else{
        return (x*1LL*x)%M;
    }
}

signed main(){
    int n;
    cin >> n;

    cout << mypow2(n)%M << endl;

    return 0;
}