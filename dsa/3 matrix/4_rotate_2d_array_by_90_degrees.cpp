class Solution {
#include <bits/stdc++.h>
using namespace std;


public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0 ; i < n ; i++ ){
            for (int j = 0 ;  j< i ; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for (int i = 0 ; i < n ; i++){
            int ptr1 = 0;
            int ptr2 = n-1;
            while (ptr1 < ptr2){
                swap(matrix[i][ptr1],matrix[i][ptr2]);
                ptr1++;
                ptr2--;
            }
        } 
    }
};