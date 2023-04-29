//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// first intuition (recursion with lcs)
// } Driver Code Ends
class Solution
{
    
    void getLcs(string &s, string &t, string output, vector<string>& ans,vector<vector<int>> &dp,  int idx1, int idx2){
        if (idx1 == s.size() || idx2 == t.size()){
            ans.push_back(output);
            return;
        }
        
        if (s[idx1] == t[idx2]){
            getLcs(s, t, s[idx1] + output, ans, dp, idx1+1, idx2+1);
        }   
        
        else if (dp[idx1][idx2-1] == dp[idx1+1][idx2]){
            getLcs(s,t, output, ans,  dp, idx1, idx2+1);
            getLcs(s,t, output, ans ,dp, idx1+1, idx2);
        }
        
        else if (dp[idx1][idx2-1] > dp[idx1-1][idx2]){
            getLcs(s,t, output, ans, dp,  idx1, idx2+1);
        }
        
        else{
            getLcs(s,t, output, ans , dp, idx1+1, idx2);
        }
    }
    
	public:
		vector<string> all_longest_common_subsequences(string s, string t)
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
		    
		    vector<string> ans;
		    string output;
		    getLcs(s, t, output, ans, dp, 0 , 0);
		    
		    return ans;
		}
};



// memoization
class Solution{
    unordered_map<string, set<string>> memo;
    set<string> getLcs(string &s, string &t, string &output, set<string>& ans,vector<vector<int>> &dp,  int idx1, int idx2){
        
        set<string> st;
        
        string key = to_string(idx1) + "," + to_string(idx2);
        if(memo.count(key)) return memo[key];
        
        if (idx1 == s.size() || idx2 == t.size()){
            st.insert("");
            return st;
        }
        
        
        if (s[idx1] == t[idx2]){
            auto temp = getLcs(s, t, output , ans, dp, idx1+1, idx2+1);
            for(auto& x : temp) {
                st.insert(s[idx1] + x);
            }
        }   
        
        else if (dp[idx1][idx2+1] == dp[idx1+1][idx2]){
            auto temp1 = getLcs(s,t, output, ans ,dp, idx1+1, idx2);
            auto temp2 = getLcs(s,t, output, ans,  dp, idx1, idx2+1);
            
            for(auto& x : temp1) {
                st.insert(x);
            }
            for(auto& x : temp2) {
                st.insert(x);
            }
        }
        
        else if (dp[idx1][idx2+1] > dp[idx1+1][idx2]){
            auto temp = getLcs(s,t, output, ans, dp,  idx1, idx2+1);
            st.insert(temp.begin(), temp.end());
        }
        
        else {
            auto temp = getLcs(s,t, output, ans , dp, idx1+1, idx2);
            st.insert(temp.begin(), temp.end());
        }
        
        return memo[key] = st;
    }
    
	public:
		vector<string> all_longest_common_subsequences(string s, string t){
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
		    
		    set<string> ans;
		    string output;
		    ans = getLcs(s, t, output, ans, dp, 0 , 0);
		    
		    vector<string> res;
		    for (auto &x : ans){
		        res.push_back(x);
		    }
		    

		    return res;
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
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends