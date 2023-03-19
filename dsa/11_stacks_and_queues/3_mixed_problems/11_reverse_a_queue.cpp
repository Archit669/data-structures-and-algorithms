//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends

/*

// approach -1 using recursion
// time complexity - O(N)
// space complexity - O(N)

//function Template for C++
void solve(queue<int> &q){
    if (q.empty()){
        return;
    }
    int val = q.front();
    q.pop();
    solve(q);
    q.push(val);
}

//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
     solve(q);
     return q;
}

*/


// using stack
// time complexity - O(N)
// space complexity - O(N)


//function Template for C++

//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
     stack<int> s;
     while (!q.empty()){
         s.push(q.front());
         q.pop();
     }
     
     while (!s.empty()){
         q.push(s.top());
         s.pop();
     }
     
     return q;
}
