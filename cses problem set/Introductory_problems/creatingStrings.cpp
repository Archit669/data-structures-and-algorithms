#include <bits/stdc++.h>
using namespace std;

void gss(string &s, int idx, set<string> &ans){
    if (idx == (int)s.size()){
        ans.insert(s);
        return;
    }

    for (int i = idx; i < (int)s.size() ; i++){
        swap(s[i], s[idx]);
        gss(s, idx+1, ans);
        swap(s[i], s[idx]);
    }
}

int main(){

    string s;
    cin >> s;

    set<string> ans;

    gss(s, 0, ans);
    cout << ans.size() << endl;

    for (auto &x : ans){
        cout << x << endl;
    }

    return 0;
}