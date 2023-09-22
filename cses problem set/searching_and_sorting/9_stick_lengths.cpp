#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int idx = 0 ; idx < n ; idx++){
        cin >> arr[idx];
    }

    sort(arr.begin(),arr.end());
    int baseLen = arr[n/2];

    int cost = 0;
    for (int idx = 0 ; idx < n ; idx++){
        cost += abs(arr[idx]- baseLen);
    }

    cout << cost << endl;
    
    return 0;
}