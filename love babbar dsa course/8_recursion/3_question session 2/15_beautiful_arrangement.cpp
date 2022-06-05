#include <bits/stdc++.h>
using namespace std;


// solution will give TLE
class Solution {
    
    bool isbeautiful(vector<int> &arr){
        for (int i = 1 ; i <= arr.size() ; i++){
            if (arr[i-1]%(i)==0 || (i)%arr[i-1]==0){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
    
    void solve(vector<vector<int>> &res,vector<int> &arr,int i = 0){
        if(i==arr.size()-1){
            if (isbeautiful(arr)){
                res.push_back(arr);
            }
            return;
        }
        
        for (int j = i ; j < arr.size() ; j++){
            swap(arr[j],arr[i]);
            solve(res,arr,i+1);
            swap(arr[j],arr[i]);
        }
    }
public:
    int countArrangement(int n) {
        vector<int> arr(n);
        for (int i = 0 ; i < n ; i++){
            arr[i] = i+1;
        }
        vector<vector<int>> res;
        solve(res,arr);
        
        return res.size();
    }
};



// approach-2 submitted

class Solution {
    
    
    void solve(vector<vector<int>> &res,vector<int> &arr,int i = 0){
        if(i==arr.size()-1){
            if ((i+1)%arr[i]==0)
                res.push_back(arr);
            return;
        }
        
        for (int j = i ; j < arr.size() ; j++){
            
            if (  (arr[j]%(i+1)==0 || (i+1)%arr[j]==0) )
            {
                swap(arr[j],arr[i]);
                solve(res,arr,i+1);
                swap(arr[j],arr[i]); 
            }
            
        }
    }
public:
    int countArrangement(int n) {
        vector<int> arr(n);
        for (int i = 0 ; i < n ; i++){
            arr[i] = i+1;
        }
        vector<vector<int>> res;
        solve(res,arr);
        
        return res.size();
    }
};