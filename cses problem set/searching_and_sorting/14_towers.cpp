#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector <int> arr(n);
    for (int idx = 0 ; idx < n ; idx++){
        cin >> arr[idx];
    }

    multiset<int> s;

    for (int idx = 0 ; idx < n ; idx++){
        int x = arr[idx];
        auto it = s.upper_bound(x);
        if (it != s.end()){
            s.erase(it);
        }

        s.insert(x);
    }

    cout << s.size() << endl;

    return 0;
}