// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++



class Solution
{
    long long int sum(int* arr , int n){
        long long int res = 0;
        for (int i = 0 ; i < n ; i++){
            res+= arr[i];
        }
        return res;
    }
    
    
    bool isPossible(int* arr, int n , long long int max_time , int n_painters){
        int painter = 1;
        long long int time = 0;
        
        for (int i = 0 ; i < n ; i++){
            if (arr[i]+time <= max_time){
                time+=arr[i];
            }else{
                painter++;
                if (painter > n_painters || arr[i] > max_time){
                    return false;
                }
                time = arr[i];
            }
        }
        
        return true;
    }
    
    
  public:
    long long minTime(int arr[], int n, int k)
    {
        long long int start = 0;
        long long int end = sum(arr,n);
        long long int ans = -1;
        
        while (start <= end){
            long long int mid = start + (end - start)/2;
            if (isPossible(arr,n,mid,k)){
                ans = mid;
                end = mid -1;
            }else{
                start = mid + 1;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends