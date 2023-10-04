#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    stack<pair<int,int>> s;
    
    for (int idx = 0 ; idx < n ; idx++){
        cin >> arr[idx];
    }

    vector<int> ans(n);

    for (int idx = 0 ; idx < n ; idx++){
        while (!s.empty() && s.top().first >= arr[idx]){
            s.pop();
        }

        if (s.empty()){
            cout << 0 << " ";
        }else{
            cout << s.top().second << " ";
        }

        s.push({arr[idx], idx+1});
    }
    cout << endl;

    return 0;
}