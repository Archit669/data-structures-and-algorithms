#include <bits/stdc++.h>
#define int long long
using namespace std;



void solve(vector<int> &ticketPrice, vector<int>& maxPrice){
    int totalTickets = ticketPrice.size();
    int totalCust = maxPrice.size();

    map<int,int> m;
    for (auto &x : ticketPrice){
        m[x]++;
    }

    for (int idx = 0 ; idx < totalCust ; idx++){
        int currMaxPrice = maxPrice[idx];
        auto it = m.upper_bound(currMaxPrice);
        if (it != m.begin()){
            --it;
            cout << it->first << endl;
            m[it->first]--;
            if (m[it->first] == 0){
                m.erase(it->first);
            }
        }else{
            cout << "-1" << endl;
        }
    }
}

signed main(){
    int n,m;
    cin >> n >> m;

    vector<int> ticketPrice(n);
    vector<int> maxPrice(m);

    for (int i = 0 ; i < n ; i++){
        cin >> ticketPrice[i];
    } 

    for (int i = 0 ; i < m ; i++) {
        cin >> maxPrice[i];
    }

    // 1, 2, 3, 4,5 ,7
    // lower bound of 6 - > 7
    // upper bound of 6 -> 7

    // 1 , 2, 3, 4, 5, 6, 7
    // lower bound of 6 -> 6
    // upper bound of 6 -> 7

    solve(ticketPrice, maxPrice);
    
}