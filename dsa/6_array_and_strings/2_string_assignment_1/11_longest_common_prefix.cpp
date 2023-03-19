// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        sort(arr, arr+N);
        
        int mini = min(arr[0].size() , arr[N-1].size());
        
        int i = 0;
         while (i < mini){
            if (arr[0][i] ==  arr[N-1][i]){
                i++;
            }else{
                break;
            }
        }
        
        if (i == 0) return "-1";
        return arr[0].substr(0,i);
        
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends