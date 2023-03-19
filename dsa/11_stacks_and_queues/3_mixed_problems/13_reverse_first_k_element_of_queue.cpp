//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    int size = q.size();
    stack<int> s;
    int count = 0;
    while (count < k){
        s.push(q.front());
        q.pop();
        count++;
    }
    
    while (!s.empty()){
        q.push(s.top());
        s.pop();
    }
    
    while (count < size){
        q.push(q.front());
        q.pop();
        count++;
    }
   
    return q;
}