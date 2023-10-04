#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define MOD 1000000007

multiset<int> lo, hi;
int loSum = 0, hiSum = 0;

void lowToHigh(){
    int val = *lo.rbegin();
    lo.erase(lo.lower_bound(val));
    loSum -= val;
    hi.insert(val);
    hiSum += val;
}

void highToLow(){
    int val = *hi.begin();
    hi.erase(hi.lower_bound(val));
    hiSum -= val;
    lo.insert(val);
    loSum += val;
}

void adjust(){
    int totSize = lo.size() + hi.size();
    if (lo.size() > (totSize + 1)/2) lowToHigh();
    else if (lo.size() < (totSize + 1)/2) highToLow();
}

void insert(int val){
    if (lo.size() == 0){
        lo.insert(val);
        loSum += val;
        return;
    }
        
    int med = *lo.rbegin();
    if (val > med){
        hi.insert(val);
        hiSum += val;
    }else{
        lo.insert(val);
        loSum += val;
    }

    adjust();
}

void erase(int val){
    int med = *lo.rbegin();
    if (val > med){
        hi.erase(hi.lower_bound(val));
        hiSum -= val;
    }else{
        lo.erase(lo.lower_bound(val));
        loSum -= val;
    }

    adjust();
}



vector<int> findMed(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> ans;
    
    // calculate the window of size k
    int idx = 0 , jdx = 0;
    while (jdx < k){
        insert(arr[jdx]);
        jdx++;
    }


    // calculate the median for remaining window
    while (jdx < n){
        int med = *lo.rbegin();
        int cost = med*lo.size() - loSum + hiSum - med*hi.size();
        ans.push_back(cost);
        erase(arr[idx]); idx++;
        insert(arr[jdx]); jdx++;
    }

    int med = *lo.rbegin();
    int cost = med*lo.size() - loSum + hiSum - med*hi.size();
    ans.push_back(cost);

    return ans;
}


void solve(){
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int idx = 0 ; idx < n ; idx++){
        cin >> arr[idx];
    }

    vector<int> ans = findMed(arr, k);

    for (auto &x : ans){
        cout << x << " ";
    }

    cout << endl;
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