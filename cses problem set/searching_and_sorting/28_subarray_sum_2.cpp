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
    map<int,int> m;

    for (int j = 0 ; j <  n ; j++){
        sum += arr[j];
       
        if (sum == x){
            ans++;
        }

        if (m.find(sum-x) != m.end()){
            ans += m[sum-x];
        }

        m[sum]++;
    }

    cout << ans << endl;
    
    return 0;
}