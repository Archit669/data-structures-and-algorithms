// { Driver Code Starts


#include<bits/stdc++.h>

using namespace std;

// time complexity - O(logn)
// space complexity - O(1)
 // } Driver Code Ends
//User function template for C++
class Solution{
    int first_occurence(int* arr, int n , int target){
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
    
    int last_occurence(int* arr, int n , int target){
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
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int first_index = first_occurence(arr,n,x);
	    int last_index = last_occurence(arr,n,x);
	    if (first_index == -1 || last_index == -1){
	        return 0;
	    }
	    return (last_index - first_index + 1);
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends