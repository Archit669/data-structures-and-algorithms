#include <bits/stdc++.h>
using namespace std;

struct range{
    int arrival, dept, index;
};

int main(){

    // take no of customers
    int n;
    cin >> n;

    // store arrival and dept time of n customers
    vector<range> v(n);
    for (int idx = 0 ; idx < n ; idx++){
        cin >> v[idx].arrival;
        cin >> v[idx].dept;
        v[idx].index = idx;
    }

    // sort each customer acc to arrival and in case arrival time is same , sort acc to dept time.
    sort(v.begin(), v.end(), [&](auto &a, auto &b){
        if (a.arrival == b.arrival){
            return a.dept < b.dept;
        }

        return a.arrival < b.arrival;
    });


    int roomCount = 0;
    vector<int> ans(n);
    multimap<int,int> m;

    for (int idx = 0 ; idx < n ; idx++){

        // get arrival and dept time of customer
        int arrival = v[idx].arrival;
        int dept = v[idx].dept;

        // check if any room free for customer
        if (m.size() > 0 && m.begin()->first < arrival){
            // get room no
            int room = m.begin()->second;
            // assign room
            ans[v[idx].index] = room;
            // erase the entry
            m.erase(m.begin());
            // insert new entry
            m.insert({v[idx].dept , room});
        }else{
            // need new room
            roomCount++;
            // assign room
            ans[v[idx].index] = roomCount;
            // insert new entry
            m.insert({v[idx].dept, roomCount});
        }
    }

    // print the total rooms required
    cout << roomCount << endl;

    // print the room no of each customer
    for (auto &x : ans){
        cout << x << " ";
    }cout << endl;
    
    return 0;
}