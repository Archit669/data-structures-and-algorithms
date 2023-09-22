#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){

    int n;
    cin >> n;

    set<int> s;

    for (int num = 1 ; num <= n ; num++){
        s.insert(num);
    }

    auto it = s.begin();
    
    while (s.size() != 1){

        cout << *next(it) << " "; // print
        s.erase(next(it)); // kill
        it = next(it); // next

        if (s.size() == 1) break;

        // when last person is already killed
        if (it == s.end()){
            it = s.begin();
        }

        // when last person has to kill
        else if (next(it) == s.end()){
            cout << *s.begin() << " ";
            s.erase(s.begin());
            it = s.begin();
        }
    }
    
    // print the last member
    cout << *s.begin() << endl;

    return 0;
}