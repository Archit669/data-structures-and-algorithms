#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n,m;
    cin >> n >> m;

    vector<int> ticketPrice(n);
    vector<int> maxPrice(m);

    for (int i = 0 ; i < n ; i++) cin >> ticketPrice[i];
    for (int i = 0 ; i < m ; i++) cin >> maxPrice[i];

    sort(ticketPrice.begin(), ticketPrice.end());

    for (auto &x : maxPrice){


    }
    
}