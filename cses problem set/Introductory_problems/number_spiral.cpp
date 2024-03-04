#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int x, y;
    cin >> x >> y;

    int ans = 0;

    if (x < y){
        if (y %2 != 0){
            ans = (y*y) - x  + 1;
        }else{
            ans = (y-1)*(y-1) + x;
        }
    }else{
        if (x%2 != 0){
            ans = (x-1)*(x-1) + y;
        }else{
            ans = (x*x)- y + 1;
        }
    }

    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;

    while (t--){
        solve();
    }

    return 0;
}