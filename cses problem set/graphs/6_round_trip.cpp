#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int n,m;
vector<vector<int>> adj;
vector<int> vis;
 
vector<int> path;
bool flag = false;
bool reachStart = false;
int startNode = 0;
 
void dfs(int v, int parent){
    vis[v] = 1;
    
    for (auto &nei : adj[v]){
        if (!vis[nei] && flag == false){
            dfs(nei, v);
        }else if (vis[nei] && nei != parent && flag == false){
            flag = true;
            startNode = nei;
        }
    }
 
    if (reachStart == false && flag){
        path.push_back(v);
        if (v == startNode){
            reachStart = true;
        }
    }
}
 
 
void Archit(){
 
    cin >> n >> m;
    adj = vector<vector<int>>(n+1);
    vis = vector<int>(n+1);
 
    for (int idx = 0 ; idx < m ; idx++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
 
    for (int v = 1 ;v <= n ; v++){
        if (!vis[v]){
            path.clear();
            dfs(v, 0);
            if (flag){
                cout << path.size() + 1 << endl;
                for (auto &x : path){
                    cout << x << " ";
                }
 
                cout << path[0] << endl;
                return ;
            }
        }
    }
 
    cout << "IMPOSSIBLE" << endl;
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
