// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    int first_occurence(vector<int> arr, int n , int target){
        int ans = -1;
        int start = 0;
        int end = n-1;
        while (start <= end){
            int mid = start + (end - start)/2;
            if (arr[mid] == target){
                ans = mid;
                end = mid - 1;
            }else if (arr[mid] > target){
                end = mid -1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
    
    int last_occurence(vector<int> arr, int n , int target){
        int ans = -1;
        int start = 0;
        int end = n-1;
        while (start <= end){
            int mid = start + (end - start)/2;
            if (arr[mid] == target){
                ans = mid;
                start = mid + 1;
            }else if (arr[mid] > target){
                end = mid -1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
  public:
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        vector<int> ans;
        int first = first_occurence(arr,n,x);
        int last = last_occurence(arr,n,x);
        
        if (first == -1){
            ans.push_back(-1);
            return ans;
        }
        
        ans.push_back(first);
        ans.push_back(last);
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}
  // } Driver Code Ends