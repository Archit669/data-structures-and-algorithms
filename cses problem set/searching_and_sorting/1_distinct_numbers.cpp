#include <bits/stdc++.h>
#define int long long
using namespace std;

// approach-1

// int solve(vector<int> &arr){
//     set<int> s;

//     for (int idx = 0 ; idx < (int)arr.size(); idx++){
//         s.insert(arr[idx]);
//     }

//     return (int)s.size();
// }

// approach-2
int solve(vector<int> &arr){
    sort(arr.begin(), arr.end());
    int count = 1;
    for (int idx = 1 ; idx < (int)(arr.size()) ; idx++){
        if (arr[idx] == arr[idx-1]) continue;
        else count++;
    }

    return count;
}

signed main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int idx = 0 ;idx < n ; idx++){
        cin >> arr[idx];
    }

    cout << solve(arr) <<endl;

    return 0;
}