#include <bits/stdc++.h>
#define int long long
using namespace std;

// the main intuition is that 
// we can always make a number (target) upto
// index i , if number at that index is less than or equal to target
// else we cannot make that target

signed main(){

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int idx = 0 ; idx < n ; idx++){
        cin >> arr[idx];
    }

    sort(arr.begin(), arr.end());
    int target = 1;

    for (int idx = 0 ; idx < n ; idx++){
        if (arr[idx] > target){
            break;
        }
            
        target += arr[idx];
    }

    cout << target << endl;
    
    return 0;
}