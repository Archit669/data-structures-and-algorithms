// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    long long maximumAmount2(int arr[], int n,int i, int j){
        if (i > j) return 0;
        long long choice1 = arr[i] + min(maximumAmount2(arr,n,i+2,j),maximumAmount2(arr,n,i+1,j-1));
        long long choice2 = arr[j] + min(maximumAmount2(arr,n,i,j-2),maximumAmount2(arr,n,i+1,j-1));
        
        return max(choice1,choice2);
    }
    public:
    long long maximumAmount(int arr[], int n){
        return maximumAmount2(arr,n,0,n-1);
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends