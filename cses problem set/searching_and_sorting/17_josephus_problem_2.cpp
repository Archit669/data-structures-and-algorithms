#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key


signed main(){

    int n , k;
    cin >> n >> k;
    
    pbds A;
    for (int num = 1 ; num <= n ; num++){
        A.insert(num);
    }

    int idx = k;
    while (A.size()){
        idx %= A.size();
        int x = *A.find_by_order(idx);
        idx += k;
        A.erase(x);
        cout << x << " ";
    }

    cout << endl;
    return 0;
}