// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
    
    void reverse(vector<long long>& arr, int i , int j){
        while (i<=j){
            swap(arr[i],arr[j]);
            i++; j--;
        }
    }
    
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
        
        if (k <= 1) return;
        
        if (k > n){
            reverse(arr, 0 , n-1);
            return;
        }
        
        int i = 0 ; 
        int j = k-1;
        
        while (true){
            reverse(arr, i , j);
            if (n-j-1 <= k){
                reverse(arr,j+1, n-1);
                break;
            }else{
                i = j+1;
                j = j+k;
            }
        }
    }
};

// { Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
}

  // } Driver Code Ends