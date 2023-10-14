/*
// approach - 1 -> (tle)
#include<bits/stdc++.h>
using namespace std;
#define int long long
 
class quad{
    public:
    int row;
    int col;
    int len;
    string path;
 
    quad(int row, int col, int len, const string &path){
        this->row = row;
        this->col = col;
        this->len = len;
        this->path = path;
    }
 
};
 
void bfs(vector<vector<char>>& grid, int row, int col){
    int n = grid.size();
    int m = grid[0].size();
 
    queue<quad> q;
    q.push({row, col,0 , ""});
    grid[row][col] = '#';
 
    int xdir[4] = {0 , 0 , -1, 1};
    int ydir[4] = {-1, 1, 0 , 0};
    string label[4] = {"L", "R", "U", "D"};
 
    while (!q.empty()){
        auto front = q.front();
        q.pop();
 
        
        for (int dir = 0 ; dir < 4 ; dir++){
            int newRow = front.row + xdir[dir];
            int newCol = front.col + ydir[dir];
 
            if (min(newRow, newCol) < 0 || newRow >= n || newCol >= m || grid[newRow][newCol] == '#') continue;
 
            if (grid[newRow][newCol] == 'B'){
                cout << "YES" << endl;
                cout << front.len + 1 << endl;
                cout << front.path + label[dir] << endl;
                return;
            }
 
 
            q.push({newRow, newCol, front.len + 1 , front.path + label[dir]});
            grid[newRow][newCol] = '#';
        }   
 
    }
 
    cout << "NO" << endl;
 
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
            if (grid[idx][jdx] == 'A'){
                 bfs(grid, idx, jdx);
                 return;
                
            }
        }
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

*/

// approach-2 
#include<bits/stdc++.h>
using namespace std;
#define int long long
 
class triplet{
    public:
    int row;
    int col;
    int len;
 
    triplet(int row, int col, int len){
        this->row = row;
        this->col = col;
        this->len = len;
    }
 
};
 
 
void bfs(vector<vector<char>>& grid, int row, int col){
    int n = grid.size();
    int m = grid[0].size();
 
    vector<vector<char>> direction(n, vector<char>(m));
 
    string path;
 
    queue<triplet> q;
    q.push({row, col,0});
    grid[row][col] = '#';
 
    int xdir[4] = {0 , 0 , -1, 1};
    int ydir[4] = {-1, 1, 0 , 0};
    char label[4] = {'L', 'R', 'U', 'D'};
 
    while (!q.empty()){
        auto front = q.front();
        q.pop();
 
        
        for (int dir = 0 ; dir < 4 ; dir++){
            int newRow = front.row + xdir[dir];
            int newCol = front.col + ydir[dir];
 
            if (min(newRow, newCol) < 0 || newRow >= n || newCol >= m || grid[newRow][newCol] == '#') continue;
 
            if (grid[newRow][newCol] == 'B'){
                cout << "YES" << endl;
                cout << front.len + 1 << endl;
                string path;
                direction[newRow][newCol] = label[dir];
                int a = newRow, b = newCol;
                while (a != row || b != col){
                    path.push_back(direction[a][b]);
                    if (direction[a][b] == 'L'){
                        b++;
                    }
                    else if (direction[a][b] == 'R'){
                        b--;
                    }
                    else if (direction[a][b] == 'U'){
                        a++;
                    }
                    else if (direction[a][b] == 'D'){
                        a--;
                    }
                }
 
                reverse(path.begin(), path.end());
 
                cout << path << endl;
 
                return;
            }
 
 
            q.push({newRow, newCol, front.len + 1});
 
            grid[newRow][newCol] = '#';
            direction[newRow][newCol] = label[dir];
        }   
 
    }
 
    cout << "NO" << endl;
 
}
 
 
void Archit(){
    int n,m;
    cin >> n >> m;
 
    int row = 0;
    int col = 0;
 
    vector<vector<char>> grid(n, vector<char>(m));
    for (int idx = 0 ; idx < n ; idx++){
        for (int jdx = 0 ; jdx < m ; jdx++){
            cin >> grid[idx][jdx];
            if (grid[idx][jdx] == 'A'){
                row = idx;
                col = jdx;
            }
        }
    }
    
    bfs(grid, row, col);
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