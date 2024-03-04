#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    
    int ans = 0;
    int i = 5;

    while (n/i > 0){
        ans += n/i;
        i *= 5;
    }

    cout << ans << endl;
    
    return 0;
}