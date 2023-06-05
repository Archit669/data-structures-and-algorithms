#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size() , n = board[0].size();

        // function for dfs traversal
        function<void(int,int)> dfs = [&](int row, int col){
            board[row][col] = '1';

            int x[] = {1,-1,0,0};
            int y[] = {0,0,1,-1};

            for (int dir = 0 ; dir < 4 ; dir++){
                int nx = row + x[dir];
                int ny = col + y[dir];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || board[nx][ny] != 'O') continue;
                dfs(nx,ny);
            }
        };

        // traverse all the O at boundries
        
        // boundary rows
        for (int i = 0 ; i < n ; i++){
            // first row 
            if (board[0][i] == 'O'){
                dfs(0,i);
            }

            // last row
            if (board[m-1][i] == 'O'){
                dfs(m-1,i);
            }

        }

        //  boundary cols
        for (int i = 0 ; i < m ; i++){
            // first col
            if (board[i][0] == 'O'){
                dfs(i,0);
            }

            // last col
            if (board[i][n-1] == 'O'){
                dfs(i,n-1);
            }
        }

        // capture all the 'O' that are surrounded
        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                if (board[i][j] == '1'){
                    board[i][j] = 'O';
                }else{
                    board[i][j] = 'X';
                }
            }
        }

    }
};