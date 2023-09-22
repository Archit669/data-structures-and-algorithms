#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n,x;
    cin >> n >> x;

    vector<int> arr(n);
    for (int idx = 0 ; idx < n ; idx++){
        cin >> arr[idx];
    }

    map<int,int> m;

    bool flag = true;

    for (int idx = 0 ; idx < n ; idx++){
        if (m.count(x - arr[idx])){
            cout << m[x-arr[idx]] << " " << idx+1 << endl;
            flag = false;
            break;
        }else{
            m[arr[idx]] = idx+1;
        }
    }


    if (flag){
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}