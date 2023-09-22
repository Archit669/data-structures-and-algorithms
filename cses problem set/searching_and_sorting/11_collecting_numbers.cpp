#include <bits/stdc++.h>
using namespace std;

// int main(){
//     int n;
//     cin >> n;

//     vector<int> arr(n);
//     // for (int idx = 0 ; idx < n ; idx++){
//     //     cin >> arr[idx];
//     // }

//     // set<int> s;

//     // for (auto &x : arr){

//     //     if (s.find(x-1) != s.end()){
//     //         s.erase(x-1);
//     //     }

//     //     s.insert(x);
//     // }

//     // cout << s.size() << endl;

//     vector<bool> v(n+1);

//     for (auto &x : arr){ 
//         cin >> x;
//         if (v[x-1]) v[x-1] = false;
//         v[x] = true; 
//     }

//     cout << accumulate(begin(v), end(v), 0);

//     return 0;
// }

int main(){
    int n;
    cin >> n;    

    vector<bool> v(n+1);
    int cnt = 0;

    for (int i = 0 ; i < n ; i++){
        int x;  cin >> x;
        // if insert then increment count else only update
        v[x-1] ? v[x-1] = false : cnt++;
        v[x] = true; 
    }

    cout << cnt << endl;

    return 0;
}


