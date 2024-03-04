#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

bool solve(int a, int b){
    if (a > b) swap(a,b);
    if (2*a < b) return 0;
    a %= 3; b %= 3;
    if ((a == 0 && b == 0) || (a == 1 && b == 2) || (a == 2 && b == 1)){
        return true;
    }
    return false;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--){
        int a, b;
        cin >> a >> b;

        string ans = solve(a,b) ? "YES" : "NO";

        cout << ans << endl;
    }
    return 0;
}