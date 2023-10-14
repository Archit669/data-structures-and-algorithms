#include<bits/stdc++.h>
using namespace std;
#define int long long

void dfs(vector<vector<char>>& grid, int row, int col){
    int n = grid.size();
    int m = grid[0].size();
    
    grid[row][col] = '#';
    int xdir[4] = {0 , 0 , -1, 1};
    int ydir[4] = {-1, 1, 0 , 0};

    for (int dir = 0 ; dir < 4 ; dir++){
        int newRow = row + xdir[dir];
        int newCol = col + ydir[dir];

        if (min(newRow, newCol) < 0 || newRow >= n || newCol >= m || grid[newRow][newCol] == '#') continue;

        dfs(grid, newRow, newCol);
    }

}


void Archit(){
    int n,m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int idx = 0 ; idx < n ; idx++){
        for (int jdx = 0 ; jdx < m ; jdx++){
            cin >> grid[idx][jdx];
        }
    }
    
    int count = 0;
    for (int idx = 0 ; idx < n ; idx++){
        for (int jdx = 0 ; jdx < m ; jdx++){
            if (grid[idx][jdx] != '#'){
                dfs(grid, idx, jdx);
                count++;
            }
        }
    }


    cout << count << endl;
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