#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int n,m;
vector<vector<int>> adj;
vector<int> vis;
 
bool flag = true;
 
 
void dfs(int v, int team){
    vis[v] = team;
    for (auto &nei : adj[v]){
 
        if (vis[nei] && vis[nei] == team){
            flag = false;
            return;
        }
 
        else if (!vis[nei]){
            if (team == 1) dfs(nei, 2);
            else dfs(nei, 1);
        }
    }
}
 
 
void Archit(){
 
    cin >> n >> m;
    adj = vector<vector<int>>(n+1);
    vis = vector<int>(n+1);
    flag = true;
 
    for (int idx = 0 ; idx < m ; idx++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    for (int v = 1 ; v <= n ; v++){
        if (!vis[v]){
            dfs(v,1);
            if (flag == false){
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
 
    for (int idx = 1 ; idx <= n ; idx++){
        cout << vis[idx] << " ";
    }cout << endl;
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