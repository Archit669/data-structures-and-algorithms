#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    int n, k;
    cin >> n >> k;
 
    vector<int> arr(n);
    for (int idx = 0 ; idx < n ; idx++){
        cin >> arr[idx];
    }
 
    map<int,int> s;
    int count = 0;
 
    for (int idx = 0 , jdx = 0 ; jdx < n ; jdx++){
        
        s[arr[jdx]]++;

        while (idx <= jdx && s.size() > k){
            s[arr[idx]]--;
            if (s[arr[idx]] == 0){
                s.erase(arr[idx]);
            }
            idx++;
        }
 
        int size = jdx - idx + 1;
        count += size;
    }
 
    cout << count << endl;
 
    return 0;
}
 