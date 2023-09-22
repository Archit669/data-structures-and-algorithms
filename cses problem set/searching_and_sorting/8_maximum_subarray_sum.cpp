#include <bits/stdc++.h>
#define int long long
using namespace std;

int maximumSumSubarray(vector<int> &arr){
    int maxSum = arr[0];
    int sum = 0;

    for (int idx = 0 ; idx < (int)arr.size(); idx++){
        sum += arr[idx];
        maxSum = max(maxSum, sum);
        if (sum < 0) sum = 0;
    }

    return maxSum;
}

signed main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int idx = 0 ; idx < n ; idx++){
        cin >> arr[idx];
    }

    cout << maximumSumSubarray(arr) << endl;

    return 0;
}