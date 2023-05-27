//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        
        // variable to store no of walls and no of colors
        int n = costs.size();
        int k = costs[0].size();
        
        // edge cases
        if (n < 1 || (n >= 2 && k <= 1)) return -1;
        
        // create an dp array in which each index (1 based) signifies total minimum cost 
        // to paint the ith wall with kth color given all the previous walls are already colored 
        // as no two adjacent walls have same color
        vector<vector<int>> dp(n, vector<int>(k,-1));
        
        // create two variables to store the first minimum and second minimum of last row
        int firstMin = INT_MAX,  secondMin = INT_MAX;
        
        // traverse the first wall and for first wall and fill dp array 
        // for first wall dp array is same as cost array
        for (int color = 0 ; color < k ; color++){
            
            dp[0][color] = costs[0][color];
            
            // when upcoming cost is less then firstMin 
            if (costs[0][color] < firstMin){
                
                secondMin = firstMin;
                firstMin = costs[0][color];
            }
            
            // when upcoming cost is lie between firstMin and secondMin
            else if (costs[0][color] < secondMin){
                
                secondMin = costs[0][color];
            }
            
        }
        
        // traverse from second wall to last wall and for each color calculate their respective
        // minimum cost end at wall of that color
        for (int wall = 1 ; wall < n ; wall++){
            
            // variable to store new FirstMin and secondMin of current wall
            int newFirstMin = INT_MAX , newSecondMin = INT_MAX;
            
            for (int color = 0 ; color < k ; color++){
                
                dp[wall][color] = costs[wall][color];
                
                if (dp[wall-1][color] != firstMin){
                    
                    dp[wall][color] += firstMin;
                    
                }else{
                    
                    dp[wall][color] += secondMin;
                }
                
                // when upcoming cost is less then firstMin 
                if (dp[wall][color] < newFirstMin){
                    
                    newSecondMin = newFirstMin;
                    newFirstMin = dp[wall][color];
                }
                
                // when upcoming cost is lie between firstMin and secondMin
                else if (dp[wall][color] < newSecondMin){
                    
                    newSecondMin = dp[wall][color];
                }
            }
            
            // update firstMin and secondMin
            firstMin = newFirstMin;
            secondMin = newSecondMin;
        }
        
        return firstMin;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends