#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> row1(n);
    vector<int> row2(n);

    set<int> s1,s2;
    map<string,int> mp;

    vector<array<int,2>> v;
    for (int idx = 0 ; idx < n ; idx++){
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
        string str = to_string(a) + " " +  to_string(b);
        mp[str] = idx;
    }

    sort(v.begin(), v.end(), [&](auto &a, auto &b){
        if (a[0] == b[0]){
            return a[1] > b[1];
        }

        return a[0] < b[0];
    });


    for (int idx = n-1; idx >= 0 ; idx--){
        auto &[a,b] = v[idx];
        auto it = s1.upper_bound(b);
        if (it != s1.begin()){
            string str = to_string(a) + " " + to_string(b);
            row1[mp[str]] = 1;
        }

        s1.insert(b);
    }
    
    for (int idx = 0 ; idx < n ; idx++){
        auto &[a,b] = v[idx];
        auto it = s2.lower_bound(b);
        if (it != s2.end()){
            string str = to_string(a) + " " +  to_string(b);
            row2[mp[str]] = 1;
        }

        s2.insert(b);
    }

    for (auto &x : row1) cout << x << " "; cout << endl;
    for (auto &x : row2) cout << x << " "; cout << endl;

    return 0;
}