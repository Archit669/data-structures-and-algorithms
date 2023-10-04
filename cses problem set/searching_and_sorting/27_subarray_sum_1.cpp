#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){

    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for (int idx = 0 ; idx < n ; idx++){
        cin >> arr[idx];
    }

    int sum = 0;
    int ans = 0;

    for (int i = 0 , j = 0 ; j <  n ; j++){
        sum += arr[j];
        while (i <= j && sum > x){
            sum -= arr[i++];
        }

        if (sum == x){
            ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}