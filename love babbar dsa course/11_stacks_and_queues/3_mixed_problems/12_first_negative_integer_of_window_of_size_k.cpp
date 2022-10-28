//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


// time complexity - O(N*k)
// space complexity - O(1)
vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int N, long long int K) {
                                                 
    vector<long long> ans;
    int i = 0;
    int j = K-1;
    
    while (j < N){
        bool flag = 1;
        for (int k = i ; k <= j; k++){
            if (arr[k] < 0) {
                ans.push_back(arr[k]);
                flag = 0;
                break;
            }
        }
        
        if (flag) ans.push_back(0);
        
        i++;  j++;
    }
    
    
    return ans;
 }