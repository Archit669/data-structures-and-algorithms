//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{   
	public:
		string all_longest_common_subsequences(string s, string t)
		{
		    // create an dp table that will store length of lcs till idx1 and idx2
		    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
		    for (int idx1 = s.size()-1 ; idx1 >= 0 ; idx1--){
		        for (int idx2 = t.size()-1 ; idx2 >= 0 ; idx2--){
		            if (s[idx1] == t[idx2]){
		                dp[idx1][idx2] = 1 + dp[idx1+1][idx2+1];
		            }else{
		                dp[idx1][idx2] = max(dp[idx1+1][idx2] , dp[idx1][idx2+1]);
		            }
		        }
		    }
		    
		    int len = dp[0][0];
            string ans; 

            int idx1 = 0 , idx2 = 0 ;

            while (idx1 < s.size() && idx2 < t.size()){
                if (s[idx1] == t[idx2]){
                    ans.push_back(s[idx1]);
                    idx1++; idx2++;
                }

                else if (dp[idx1+1][idx2] >= dp[idx1][idx2+1]){
                    idx1++;
                }

                else{
                    idx2++;
                }
            }

		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	string ans = ob.all_longest_common_subsequences(s, t);
    	cout << ans << endl;
    }
	return 0;
}


// } Driver Code Ends