#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;

    vector<vector<int>> events;
    
    for (int idx = 0 ; idx < n; idx++){
        int a, b;
        cin >> a >> b;
        events.push_back({a, 1});
        events.push_back({b,-1});
    }

    sort(events.begin(), events.end());

    int ans = 0;
    int count = 0;

    for (int idx = 0 ; idx < (int)(events.size()); idx++){
        count += events[idx][1];
        ans = max(ans, count);
    }

    cout << ans << endl;

    return 0;
}