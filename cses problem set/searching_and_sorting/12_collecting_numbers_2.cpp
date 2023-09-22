#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    
    int n, q;
    cin >> n >> q;    

    vector<int> posOf(n+1);
    vector<int> valOf(n+1);

    for (int pos = 1 ; pos <= n ; pos++){
        int val = 0;
        cin >> val;

        valOf[pos] = val;
        posOf[val] = pos;
    }

    int cnt = 1;
    for (int val = 2; val <= n ; val++){
        if (posOf[val] < posOf[val-1]){
            cnt++;
        }
    }

    set<pair<int,int>> uniquePairs;

    while (q--){

        int a, b;
        cin >> a >> b;

        // (valOf[a]-1,valOf[a])
        // (valOf[a], valOf[a]+1)
        // (valOf[b]-1, valOf[b])
        // (valOf[b], valOf[b]+1)

        if (valOf[a]-1 >= 1){
            uniquePairs.insert({valOf[a]-1,valOf[a]});
        }

        if (valOf[a] + 1 <= n){
            uniquePairs.insert({valOf[a], valOf[a]+1});
        }

        if (valOf[b]-1 >= 1){
            uniquePairs.insert({valOf[b]-1,valOf[b]});
        }

        if (valOf[b] + 1 <= n){
            uniquePairs.insert({valOf[b], valOf[b]+1});
        }

        for (auto &pair : uniquePairs){
            int x = pair.first;
            int y = pair.second;

            cnt -= posOf[x] > posOf[y];
        }

        swap(valOf[a], valOf[b]);
        swap(posOf[valOf[a]], posOf[valOf[b]]);

        for (auto &pair : uniquePairs){
            int x = pair.first;
            int y = pair.second;

            cnt += posOf[x] > posOf[y];
        }

        cout << cnt << endl; 

        uniquePairs.clear();
    }

    return 0;
}


