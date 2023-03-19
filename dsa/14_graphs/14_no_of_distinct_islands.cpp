//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<vector< pair<int,int>>> s;

        queue<pair<int,int>> q;
        
        // function for bfs traversal
        auto bfs = [&](int row, int col){
            vector<pair<int,int>> v;
            q.push({row, col});
            grid[row][col] = 0;
            
            while (!q.empty()){
                auto front = q.front();
                v.push_back({front.first-row, front.second-col});
                q.pop();
                
                int delrow[] = {1,-1,0,0};
                int delcol[] = {0,0,1,-1};
                
                for (int dir = 0 ; dir < 4 ; dir++){
                    int nrow = front.first + delrow[dir];
                    int ncol = front.second + delcol[dir];
                    
                    if (nrow < 0 || ncol < 0 || nrow >=m || ncol >= n || grid[nrow][ncol] == 0){
                        continue;
                    }
                    
                    q.push({nrow, ncol});
                    grid[nrow][ncol] = 0;
                }
            }
            
            s.insert(v);
        };
        
        
        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                if (grid[i][j] != 0){
                    bfs(i,j);
                }
            }
        }
        
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends