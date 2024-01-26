#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
vector<vector<int>> adj;
vector<bool> visited;

void bfs(int vertex){
    vector<int> parent(n+1);
    queue<pair<int,int>> q;
    int count = 0;

    q.push({vertex, 1});
    parent[vertex] = -1;
    visited[vertex] = true;

    while (q.size() > 0){
        auto [front, len] = q.front();
        q.pop();


        if (front == n){

            cout << len << endl;

            int x = front;

            vector<int> temp;

            while (x != -1){
                temp.push_back(x);
                x = parent[x];
            }

            reverse(temp.begin(), temp.end());

            for(auto &x : temp){
                cout << x << " ";
            }cout << endl;


            return;
        }

        for (auto &nei : adj[front]){
            if (!visited[nei]){
                visited[nei] = true;
                q.push({nei, len+1});
                parent[nei] = front;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    
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

    bfs(1);
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