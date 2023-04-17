//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// memoization
// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       
       vector<vector<int>> dp(n, vector<int>(W+1, -1));
       function<int(int,int)> helper = [&](int W, int idx){
           if (idx == n){
               return 0;
           }
           
           if (dp[idx][W] != -1){
               return dp[idx][W];
           }
           
           int pick = 0;
           if (W - wt[idx] >= 0){
               pick = val[idx]+ helper(W-wt[idx] , idx+1);
           }
           
           int unpick = helper(W, idx+1);
           
           return dp[idx][W] = max(pick, unpick);
       };
       
       return helper(W, 0);
    }
};


// tabulation
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    
        for (int idx = n-1 ; idx >= 0 ; idx--){
            for (int weight = 0; weight <= W ; weight++){
                int pick = 0;
                if (weight - wt[idx] >= 0){
                    pick = val[idx] + dp[idx+1][weight-wt[idx]];
                }
                
                int unpick = dp[idx+1][weight];
                
                dp[idx][weight] = max(pick, unpick);
            }
            
        }
       
       return dp[0][W];
    }
};


// space optimization
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<int> next(W+1, 0);
        for (int idx = n-1 ; idx >= 0 ; idx--){
            
            vector<int> curr(W+1, 0);
            
            for (int weight = 0; weight <= W ; weight++){
                int pick = 0;
                if (weight - wt[idx] >= 0){
                    pick = val[idx] + next[weight-wt[idx]];
                }
                
                int unpick = next[weight];
                
                curr[weight] = max(pick, unpick);
            }
            
            next = move(curr);
        }
       
       return next[W];
    }
};

// space optimization 2
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<int> next(W+1, 0);
        for (int idx = n-1 ; idx >= 0 ; idx--){
            for (int weight = W; weight >= 0 ; weight--){
                int pick = 0;
                if (weight - wt[idx] >= 0){
                    pick = val[idx] + next[weight-wt[idx]];
                }
                int unpick = next[weight];
                next[weight] = max(pick, unpick);
            }
            
        }
       
       return next[W];
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