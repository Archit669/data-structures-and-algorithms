//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q;
        q.push({start , 0});
        vector<int> dist(100000, INT_MAX);
        dist[start] = 0;
        
        while (!q.empty()){
            auto front = q.front();
            q.pop();
            
            int frontVal = front.first;
            int steps = front.second;
            
            for (int idx = 0; idx < arr.size() ; idx++){
                
                int val = (frontVal* arr[idx])%100000;
                if (steps + 1 < dist[val]){
                    dist[val] = steps  + 1;
                    if (val == end) return steps + 1;
                    q.push({val, steps+1});
                }
                
            }
        }
        
        return dist[end] == INT_MAX ? -1 : dist[end];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends