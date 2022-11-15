//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
		public:
		string FirstNonRepeating(string A){
		    vector<int> freq(26);
		    string output;
		    queue<char> q;
		    for (int i = 0 ; i < A.size() ; i++){
	            freq[A[i]-'a']++;
	            q.push(A[i]);
	            while (!q.empty() && freq[q.front() -'a'] != 1){
	                q.pop();
	            }
	            
	            if (q.empty())
	                output.push_back('#');
	            else
	                output.push_back(q.front());
	            
		    }
		    
		    return output;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends