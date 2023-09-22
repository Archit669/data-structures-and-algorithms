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

    map<int,int> m;
    int maxLen = 0;

    for (int i = 0 , j = 0 ;  j < n ; j++){
        m[arr[j]]++;
        while (i <= j && (int)m.size() < j-i+1){
            m[arr[i]]--;
            if (m[arr[i]] == 0){
                m.erase(arr[i]);
            }

            i++;
        }

        if ((int)m.size() == j-i+1){
            maxLen = max(maxLen, j-i+1);
        }
    }

    cout << maxLen << endl;

    return 0;
}