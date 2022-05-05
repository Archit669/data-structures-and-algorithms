// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array

    // time complexity - O(n)
    // space complexity - O(n)
    int majorityElement(int a[], int size)
    {
        
        unordered_map<int,int> m;
        int ans = -1;
        
        for (int i = 0 ; i < size ; i++){
            m[a[i]]++;
        }
        
        for (auto it: m){
            if (it.second > size/2){
                ans = it.first;
            }
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends