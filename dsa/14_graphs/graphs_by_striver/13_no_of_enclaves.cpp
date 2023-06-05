#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        int m = board.size() , n = board[0].size();

        // function for dfs traversal
        function<void(int,int)> dfs = [&](int row, int col){
            board[row][col] = 2;

            int x[] = {1,-1,0,0};
            int y[] = {0,0,1,-1};

            for (int dir = 0 ; dir < 4 ; dir++){
                int nx = row + x[dir];
                int ny = col + y[dir];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || board[nx][ny] != 1) continue;
                dfs(nx,ny);
            }
        };

        // traverse all the O at boundries
        
        // boundary rows
        for (int i = 0 ; i < n ; i++){
            // first row 
            if (board[0][i] == 1){
                dfs(0,i);
            }

            // last row
            if (board[m-1][i] == 1){
                dfs(m-1,i);
            }

        }

        //  boundary cols
        for (int i = 0 ; i < m ; i++){
            // first col
            if (board[i][0] == 1){
                dfs(i,0);
            }

            // last col
            if (board[i][n-1] == 1){
                dfs(i,n-1);
            }
        }

        // capture all the 'O' that are surrounded
        int ans = 0;
        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                if (board[i][j] == 1){
                    ans++;
                }
            }
        }

        return ans;
    }
};