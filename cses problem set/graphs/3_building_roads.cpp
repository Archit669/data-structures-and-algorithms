#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
vector<vector<int>> adj;
vector<bool> visited;
vector<vector<int>> ans;

int dfs(int vertex){
    visited[vertex] = true;
    int v = vertex;
    for (auto &nei : adj[vertex]){
        if (!visited[nei]){
            v =  dfs(nei);
        }
    }

    return v;
}


void Archit(){

    cin >> n >> m;
    adj = vector<vector<int>>(n+1);
    visited = vector<bool>(n+1);

    for (int idx = 0 ; idx < m ; idx++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    int count = 0;
    int prevVertex = -1;

    for (int vertex = 1 ; vertex <= n ; vertex++){
        if (!visited[vertex]){
            if (prevVertex != -1){
                ans.push_back({prevVertex, vertex});
            }

            prevVertex = dfs(vertex);
            count++;
            // cout << vertex << endl;
            // for (auto x : visited) cout << x << " "; cout << endl;
        }
    }

    cout << count -1 << endl;
    for (auto &x : ans){
        for (auto &y : x){
            cout << y << " ";
        }cout << endl;
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