//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      int count = 0;
      unordered_set<int> s;
      for (int i = 0 ; i < N ; i++){
         s.insert(arr[i]);
      }
      
      for (auto &x : s){
          if (s.find(x-1) == s.end() ) {
             int curr_count = 1;
             while (s.find(x+curr_count) != s.end()){
                 curr_count+= 1;
             }
             
             count = max(count , curr_count);
             
          }
      }
      
      return count;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends