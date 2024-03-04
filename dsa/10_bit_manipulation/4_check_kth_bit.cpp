#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , k;
    cin >> n >> k;

    int mask = (1 << k);
    bool ans = (n & mask);

    cout << ans << endl;

    return 0;
}