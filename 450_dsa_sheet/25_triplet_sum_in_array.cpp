//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
        
        for (int i = 0 ; i < n-2 ; i++){
            int k = i+1;
            int j = n-1;
            
            while (k < j){
                int sum = A[i] + A[j] + A[k];
                if (sum == X) return true;
                if (sum < X) k++;
                else j--;
            }
        }
        
        
        return false;
        
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends