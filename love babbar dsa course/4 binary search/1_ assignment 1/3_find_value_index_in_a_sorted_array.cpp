// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	vector<int> valueEqualToIndex(int arr[], int n) {
	    vector<int> ans;
	    int start = 0;
        int end = n-1;

        while (start <= end){
            int mid = start + (end - start)/2;
            if (arr[mid] == mid){
                ans.push_back(mid);
                return ans;
            }else if (arr[mid] < mid){
                start = mid + 1;
            }else{
                end = mid -1;
            }
        }

        if (ans.size()==0){
            ans.push_back(-1);
        }
	    
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.valueEqualToIndex(arr, n);
        if (ans.empty()) {
            cout << "Not Found";
        } else {
            for (int x: ans) {
                cout << x << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends