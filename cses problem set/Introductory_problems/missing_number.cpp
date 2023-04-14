#include <bits/stdc++.h>
#define int long long 
using namespace std;

signed main(){
    int n,ans = 0; cin >> n; 
    for (int i = 0 ; i  < n-1 ; i++){
        int val; cin >> val;
        ans^= val^(i+1);
    }cout << (ans^n) << endl;
}