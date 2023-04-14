#include <bits/stdc++.h>
#define int long long 
using namespace std;
 
signed main(){
    int n;
    cin >> n;
    while (n != 1){
        cout << n << " ";
        n = n&1? (3*n + 1) : n/2;
    }cout << 1 << endl;
}