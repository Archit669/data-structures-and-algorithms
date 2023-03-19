#include <bits/stdc++.h>
using namespace std;

// approach - 1
// using map
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // create an vector ans for result
        vector<int> ans;
        // find no of rows
        int row = mat.size();
        // find no of  columns
        int col = mat[0].size();
        
        // create an map to store all value in vector has equal row+col sum
        map< int, vector<int> > m;
        for (int i = 0 ; i <= row+col ; i++){
            vector<int> temp;
            m[i] = temp;
        }
        
        // push value in vector of having key (row + col)
        for (int i = 0 ; i < mat.size() ; i++){
            for (int j = 0 ; j < mat[0].size() ; j++){
                m[i+j].push_back(mat[i][j]);
            }
        }
        
        // iterate map
        for (auto it : m){
            
            // sum of row and col is even then first reverse vector and then push it value
            if ((it.first & 1) == 0){
                reverse(it.second.begin(),it.second.end());
            }
            
            // push values (for odd reversal not needed)
            
            for (int i = 0 ; i< it.second.size() ; i++){
                ans.push_back(it.second[i]);
            }
        }
         
        // return ans;
        return ans;
    }
};