#include <bits/stdc++.h>
#define int unsigned int long long
using namespace std;

signed main(){
    int n;
    cin >> n;

    int power2 = 1;

    while (power2* 2 <= n){
        power2 *= 2;
    }
    
    n = n - power2;

    cout << 2*n + 1 << endl;

    return 0;
}