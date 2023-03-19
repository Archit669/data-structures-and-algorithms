// //{ Driver Code Starts
// #include<bits/stdc++.h>
// using namespace std;


// memoization

// // } Driver Code Ends
// class Solution
// {
//     int solve(int W, int* wt, int* val, int n, vector<vector<int>> &dp) 
//     { 
//        // weight is 0 or n is 0 that means knapsack is full or no items to put
//        if (W == 0 || n == 0){
//            return 0;
//        }
       
//        if (dp[W][n] != -1){
//            return dp[W][n];
//        }
       
//        if (wt[n-1] <= W){
//             return dp[W][n] = max( val[n-1] + solve(W-wt[n-1], wt, val, n-1, dp), 
//                     solve(W, wt, val, n-1, dp) );
//        }
       
//        return dp[W][n] = solve(W, wt, val, n-1, dp);
//     }
    
//     public:
//     //Function to return max value that can be put in knapsack of capacity W.
//     int knapSack(int W, int wt[], int val[], int n) 
//     { 
//        vector<vector<int>> dp(W+1, vector<int>(n+1, -1));
//        return solve(W,wt,val,n,dp);
//     }
// };

// //{ Driver Code Starts.

// int main()
//  {
//     //taking total testcases
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         //reading number of elements and weight
//         int n, w;
//         cin>>n>>w;
        
//         int val[n];
//         int wt[n];
        
//         //inserting the values
//         for(int i=0;i<n;i++)
//             cin>>val[i];
        
//         //inserting the weights
//         for(int i=0;i<n;i++)
//             cin>>wt[i];
//         Solution ob;
//         //calling method knapSack()
//         cout<<ob.knapSack(w, wt, val, n)<<endl;
        
//     }
// 	return 0;
// }
// // } Driver Code Ends


// tabulation
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    int solve(int W, int* wt, int* val, int n, vector<vector<int>> &dp) 
    { 
       // weight is 0 or n is 0 that means knapsack is full or no items to put
       for (int i = 0 ; i <= n ; i++){
           dp[i][0] = 0;
       }
       
       for (int i = 0 ; i <= W ; i++){
           dp[0][i] = 0;
       }
       
       
       for (int i = 1 ; i <= n ; i++){
           for (int j = 1 ; j <= W ; j++){
               if (wt[i-1] <= j){
                    dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j] );
               }else{
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       
       return dp[n][W];
    }
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
       return solve(W,wt,val,n,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends