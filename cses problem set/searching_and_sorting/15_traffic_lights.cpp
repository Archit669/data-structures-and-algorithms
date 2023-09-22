#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, n;
    cin >> x >> n;

    set<int> position;
    multiset<int> length;

    position.insert(0);
    position.insert(x);

    length.insert(x-0);

    while (n-- > 0){
        int pos;
        cin >> pos;

        position.insert(pos);

        auto it = position.find(pos);

        // 0    3(it)    8 

        int prevValue = *prev(it);
        int nextValue = *next(it);

        length.erase(length.find(nextValue - prevValue));

        length.insert(pos - prevValue);
        length.insert(nextValue - pos);

        cout << *(length.rbegin()) << " ";

    }cout << endl;


    return 0;
}