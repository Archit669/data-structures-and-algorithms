#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define MOD 1000000007

void solve(){
    int n, k;
    cin >> n >> k;
    
    pbds A;

    vector<int> arr(n);
    for (int idx = 0 ; idx < n ; idx++){
        cin >> arr[idx];
    }
    
    // create a window of size k
    int i = 0, j = 0;   
    while (j < k){
        A.insert(arr[j]);
        j++;
    }

    while (j < n){

        // calculate the median of the window
        if (k&1) cout << *A.find_by_order(k/2) << " ";
        else cout << *A.find_by_order(k/2 - 1) << " ";

        //slide the window
        A.erase(A.upper_bound(arr[i])); i++;
        A.insert(arr[j]); j++;
    }

    // calulate the median of last window
    if (k&1) cout << *A.find_by_order(k/2) << " ";
    else cout << *A.find_by_order(k/2 - 1) << " ";
}

signed main(){
    
    // input output 
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // main
    int t = 1;
    // cin >> t;

    while (t--){
        solve();
    }
    
    // calculate time of execution
    #ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
}