#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define MOD 1000000007

bool isPossible(vector<int> &arr, int largetSum, int partitionCount){
    int count = 1;
    int sum = 0;

    for (int idx = 0 ; idx < arr.size() ; idx++){
        if (sum + arr[idx] <= largetSum){
            sum += arr[idx];
        }else{
            sum = arr[idx];
            count++;
        }
    }

    return count <= partitionCount;
}


void solve(){
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int idx = 0 ; idx < n ; idx++){
        cin >> arr[idx];
    }

    int start = *max_element(arr.begin(), arr.end());
    int end = accumulate(arr.begin(), arr.end(), 0LL);

    int ans = -1;

    while (start <= end){
        int mid = start + (end - start)/2;
        if (isPossible(arr ,mid, k)){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }

    cout << ans << endl;
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