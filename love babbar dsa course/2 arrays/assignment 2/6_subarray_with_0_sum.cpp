// { Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;

// approach - 1
// time complexity - O(n^2)
// space complexity - O(1)

 // } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        for (int i = 0 ; i < n ; i++){
            int sum = 0;
            for (int j = i ; j < n ; j++){
                if (arr[j] == 0){
                    return 1;
                }
                sum+=arr[j];
                if (sum == 0){
                    return 1;
                }
            }
        }
        return 0;
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}  // } Driver Code Ends