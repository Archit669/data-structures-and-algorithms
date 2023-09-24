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

    int sum = accumulate(arr.begin(), arr.end(), 0LL);
    int maxi = *max_element(arr.begin(), arr.end());

    cout << max(sum, 2*maxi) << endl;

    return 0;
}


// python code
// n = int(input())
// arr = [int(x) for x in input().split()]
// print(max(2*max(arr) , sum(arr)))
