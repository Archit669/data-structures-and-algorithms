#include<bits/stdc++.h>
using namespace std;
#define int long long


void Archit(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);
    for (int idx = 0; idx < m ; idx++){
        int u , v, wt;
        cin >> u >> v;
        adj[u].push_back({v, wt});
        adj[v].push_back({u , wt});
    }

    
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
        Archit();
    }
    
    // calculate time of execution
    #ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
}