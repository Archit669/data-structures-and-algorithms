#include <bits/stdc++.h>
#define int long long
using namespace std;

bool isPossible(int mid, vector<int> &arr, int t){
    int n = arr.size();
    int count = 0;
    for (int idx =  0; idx < n ; idx++){
        count += (mid / arr[idx]);
        if (count >= t) return true;
    }

    return count >= t;
}

int solve(int n , int t , vector<int> &arr){
    int start = 1;
    int end = arr.back()*t;

    int ans = -1;

    while (start <= end){
        int mid = start + (end - start)/2;
        if (isPossible(mid, arr, t)){
            end = mid - 1;
            ans = mid;
        }else{
            start = mid + 1;
        }
    }

    return ans;
}

signed main(){
    int n, t;
    cin >> n >> t;

    vector<int> arr(n);
    for (int idx = 0 ; idx < n ; idx++){
        cin >> arr[idx];
    }

    cout << solve(n ,t, arr) << endl;

    return 0;
}