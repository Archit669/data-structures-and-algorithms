#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> nse(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n,n);
        stack<int> s;
        for (int i = n-1 ; i >= 0 ; i--){
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()){
                ans[i] = s.top();
            }
            s.push(i);
                
        }
        return ans;
    }
    
    vector<int> pse(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int> s;
        s.push(-1);
        for (int i = 0 ; i < n ; i++){
            while (s.top() != -1 && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    int findArea(vector<int> arr){
        vector<int> prev = pse(arr);
        vector<int> next = nse(arr);
        int maxi = 0;
        
        int area = 0;
        for (int i = 0 ; i < arr.size() ; i++){
            int length= next[i] - prev[i] - 1;
            int bredth = arr[i];
            area = length*bredth;
            maxi = max(maxi,area);
        }
        
        return maxi;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> mat(m,vector<int>(n));
        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                mat[i][j] = matrix[i][j] - '0';
            }
        }
        
        int max_area = 0 ;
        
        int area = findArea(mat[0]);
        max_area = max(area, max_area);
            
        for (int i = 1 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                mat[i][j] = mat[i][j] ? (mat[i][j] + mat[i-1][j]) : 0;
            }
            area = findArea(mat[i]);
            max_area = max(area, max_area);
        }
        
        return max_area;
        
    }
};