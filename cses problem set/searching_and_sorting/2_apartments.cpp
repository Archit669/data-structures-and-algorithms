#include <bits/stdc++.h>
#define int long long
using namespace std;

// testcase for which sorting is necessary
// 3 5 1
// 4 8 3
// 5 3 7 8 5

int solve(vector<int> &desSz, vector<int>& apart, int k){
    sort(desSz.begin(), desSz.end());
    int n = desSz.size();

    // 60
    // 30 

    // 60 -> 55 to 65 -> yes -> 55 (lower bound) && 65 <= (yes) -> remove from map
    // 45 -> 40 to 50 -> no 
    // 80 -> 75 to 85 -> yes
    // 60 -> 55 to 65 -> no

    // max 2 people

    // create the mapping 
    map<int,int> mp;
    for (auto &x : apart){
        mp[x]++;
    }

    int count = 0;

    for (int idx = 0 ; idx < n ; idx++){
        int currSize = desSz[idx];
        auto it = mp.lower_bound(currSize - k);
        if (it != mp.end() && it->first <= currSize + k){
            count++;
            mp[it->first]--;
            if (mp[it->first] == 0){
                mp.erase(it->first);
            }
        }
    }

    return count;
}

// int solve(vector<int> &desSz, vector<int>& apart, int k){

//     // if we cannot find the candidate appartment for curr candidate then there is no point for finding appartment for the next one
//     sort(desSz.begin(), desSz.end());
//     sort(apart.begin(), apart.end());

//     int idx = 0, jdx = 0;
//     int count = 0;

//     while (idx < desSz.size()){

//         // find the candidate appartment for the curr person
//         while (jdx < apart.size() && apart[jdx] < desSz[idx] - k ){
//             jdx++;
//         }

//         // if it can be assigned then increment count and move to next person
//         if (abs(apart[jdx] - desSz[idx]) <= k){
//             count++;
//             idx++;
//             jdx++;
//         }else{
//             idx++;
//         }
//     }

//     return count;
// }

signed main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desSz(n);
    vector<int> apart(m);

    for (int idx = 0 ; idx < n ; idx++){
        cin >> desSz[idx];
    }

    for (int idx = 0 ; idx < m ; idx++){
        cin >> apart[idx];
    }

    cout << solve(desSz, apart, k) << endl;

    return 0;
}