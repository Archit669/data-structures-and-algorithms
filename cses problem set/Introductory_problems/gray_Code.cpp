#include <bits/stdc++.h>
using namespace std;

vector<string> grayCode(int n){
    if (n == 1) return {"0","1"};
    vector<string> ans = grayCode(n-1);
    vector<string> temp = ans;

    for (auto &x : ans){
        x = "0" + x;
    }

    reverse(temp.begin(), temp.end());

    for (auto &x : temp){
        ans.push_back("1" + x);
    }

    return ans;
}

int main(){
    int n;
    cin >> n;

    vector<string> ans = grayCode(n);

    for (auto &x : ans){
        cout << x << endl;
    }

    return 0;
}