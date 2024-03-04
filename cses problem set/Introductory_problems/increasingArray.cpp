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

    int moves = 0;
    for (int idx = 1; idx < n ; idx++){
        if (arr[idx-1] > arr[idx]){
            moves += abs(arr[idx]- arr[idx-1]);
            arr[idx] = arr[idx-1];
        }
    }

    cout << moves << endl;

    return 0;
}