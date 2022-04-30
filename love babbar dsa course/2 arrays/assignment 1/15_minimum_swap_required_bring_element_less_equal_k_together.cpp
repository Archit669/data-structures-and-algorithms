// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



/*
// brute force approach
// time complexity - O(n)
// space complexity -O(1)
class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int count = 0;
        for (int i =0 ; i < n; i++){
            if (arr[i] <= k){
                count++;
            }
        }
        

        int bad = 0;
        int mini = INT_MAX;
        
        for (int i = 0 ; i < n-count+1 ; i++){
            bad = 0;
            for (int j = i ; j < i+count ; j++){
                if (arr[j] > k){
                    bad++;
                }
            }
            mini = min(bad,mini);
        }
        
        return mini;
    }
};

*/


// approach 2
// time complexity - O(n)
// space complexity - O(1)

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int good = 0;
        int bad = 0;
        for (int i = 0 ; i < n ; i++){
            if (arr[i] <= k){
                good++;
            }
        }
        
        for (int i = 0 ; i < good ; i++){
            if (arr[i] > k){
                bad++;
            }
        } 
        
        
        int i = 0 ; int j = good ; int ans = bad;
        while (j< n){
            if (arr[i] > k){
                bad--;
            }
            if (arr[j] > k){
                bad++;
            }
            ans = min(ans,bad);
            i++;j++;
        }
        
        return ans;
    }
};



// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends