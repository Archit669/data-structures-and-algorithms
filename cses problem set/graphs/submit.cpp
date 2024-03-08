#include<bits/stdc++.h>
using namespace std;
#define int long long

// bfs traversal
int bfs(int &startRow, int &startCol, int &endRow, int &endCol, vector<vector<char>> &grid, vector<vector<char>> &path){

    // calculate rows and cols
    int n = grid.size();
    int m = grid[0].size();

    // create a visited array
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // create a queue
    queue<array<int,3>> que;

    // push the start point and mark it as visited
    que.push({startRow, startCol, 0});
    visited[startRow][startCol] = true;

    // direction arrays 
    int rowdir[4] = {0, 0, 1, -1};
    int coldir[4] = {1,-1, 0, 0};
    char pathDir[4] = {'R', 'L', 'D', 'U'};


    // bfs traversal
    while (que.size() > 0){

        // find front 
        auto [row, col, count] = que.front();
        que.pop();

        // traverse for all 4 directions
        for (int dir = 0 ; dir < 4 ; dir++){

            int newRow = row + rowdir[dir];
            int newCol = col + coldir[dir];

            // remove invalid cell
            if (min(newRow, newCol) < 0 || newRow >= n || newCol >= m || visited[newRow][newCol] || grid[newRow][newCol] == '#'){
                continue;
            }

            // push new Cell , mark it as visited and mark in path that how it came from start
            que.push({newRow, newCol, count+1});
            path[newRow][newCol] = pathDir[dir];
            visited[newRow][newCol] = true;

            // reach destination
            if (newRow == endRow && newCol == endCol){
                return count + 1;
            }

        }
    }

    return -1;
}


void Archit(){

    // take no of rows and cols from user
    int n, m;
    cin >> n >> m;
    
    // take grid from user and along with it find startRow , startCol, endRow, endCol
    int startRow = -1, startCol = -1;
    int endRow = -1, endCol = -1;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int idx = 0 ; idx < n; idx++){
        for (int jdx = 0 ; jdx < m ; jdx++){
            cin >> grid[idx][jdx]; 
            if (grid[idx][jdx] == 'A'){

                startRow = idx;
                startCol = jdx;
            }
 
            if (grid[idx][jdx] == 'B'){

                endRow = idx;
                endCol = jdx;
            }
        }
    }

    // create a matrix path to store the path from start to end
    vector<vector<char>> path(n, vector<char>(m, '.'));

    // calculate len
    int len = bfs(startRow, startCol , endRow, endCol, grid, path);

    // no path found
    if (len == -1){

        cout << "NO" << endl;

        return;
    }
    
    // print the output yes and lenghth of path
    cout << "YES" << endl;
    cout << len << endl;


    // trace back the path
    string ans;

    int row = endRow;
    int col = endCol;

    while (row != startRow || col != startCol){
        ans += path[row][col];
        if (path[row][col] == 'U') row++;          // came from down
        else if (path[row][col] == 'R') col--;     // came from left
        else if (path[row][col] == 'L') col++;     // came from right
        else row--;                                // came from up
    }

    // reverse the path
    reverse(ans.begin(), ans.end());

    // print answer
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
        Archit();
    }
    
    // calculate time of execution
    #ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
}