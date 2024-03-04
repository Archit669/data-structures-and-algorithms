//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        
        for (int idx = 0; idx < N-1; idx++){
            string s1 = dict[idx];
            string s2 = dict[idx+1];
            
            int len = min(s1.size(), s2.size());
            
            int ptr1 = 0, ptr2 = 0;
            while (ptr1 < len && ptr2 < len){
                if (s1[ptr1] != s2[ptr2]){
                    adj[s1[ptr1] - 'a'].push_back(s2[ptr2] - 'a');
                    break;
                }
                ptr1++; ptr2++;
            }
        }
        
        vector<int> ans;
        queue<int> q;
        vector<int> indegree(K);
        
        for(int vertex = 0 ; vertex < K ; vertex++){
            for (auto &nei : adj[vertex]){
                indegree[nei]++;
            }
        }
        
        for (int vertex = 0 ; vertex < K ; vertex++){
            if (indegree[vertex] == 0){
                q.push(vertex);
            }
        }
        
        while (!q.empty()){
            int front = q.front();
            q.pop();
            
            ans.push_back(front);
            
            for (auto &nei : adj[front]){
                indegree[nei]--;
                if (indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }
        
        string topoSort;
        for (auto &x : ans){
            topoSort.push_back(x + 'a');
        }
        
        return topoSort;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends