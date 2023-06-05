//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// recursion + memoization
class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N,-1));

        function<int(int,int)> f = [&](int i, int j)
        {
            // base case 
            // when we have a single matrix so multiplication operation to multiply two matrix will be zero
            if (i == j)
            {
                return dp[i][j] = 0;
            }
            
            if (dp[i][j] != -1) return dp[i][j];
            
            // try all possible paritions
            int ans = 1e9;
            for (int k = i ; k < j ; k++) 
            {
                int steps = f(i , k) + f(k+1 , j) + arr[i-1] * arr[k] * arr[j];
                ans = min(ans, steps);
            }
            
            // return answer
            return dp[i][j] = ans;
        };
        
        return f(1, N-1);
    }
};


// tabulation
class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N,0));
        
        for (int i = N-1 ; i >= 1 ; i--){
            for (int j = i+1; j < N; j++){
                
                int ans = 1e9;
                
                for (int k = i ; k < j ; k++){
                    int steps =  dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                    ans = min(ans, steps);
                }
                
                dp[i][j] = ans;
            }
        }
        
        return dp[1][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends