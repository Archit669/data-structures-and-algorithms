#include <bits/stdc++.h> 
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr, int n){
    stack<int> s;
    vector<int> ans(n,-1);
    s.push(arr[n-1]);
    for (int i = n-2 ; i >=0  ; i--){
        while (!s.empty() && s.top() <= arr[i]){
            s.pop();
        }
        
        if (!s.empty()){
            ans[i] = s.top();
        }
        
        s.push(arr[i]);
    }
    
    return ans;
}