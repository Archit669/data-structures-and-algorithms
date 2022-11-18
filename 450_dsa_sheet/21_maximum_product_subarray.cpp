//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

    void swap(long long &a , long long &b){
        long long temp = a;
        a = b;
        b = temp;
    }

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long maxi = arr[0];
	    long long mini = arr[0];
	    long long ans = arr[0];
	    
	    for (int i = 1 ; i < n ; i++){
	        if (arr[i] < 0) swap(mini, maxi);
	        maxi = max(maxi*arr[i],(long long) arr[i]);
	        mini = min(mini*arr[i], (long long) arr[i]);
	        ans = max(ans, maxi);
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends