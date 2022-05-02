// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

 /*
 // approach 1
 // time complexity - O(n)
 // space complexity - O(1)
class Solution {
  public:
    int setBits(int N) {
        int count = 0;
        while (N){
            if (N&1)  count++;
            N>>=1;
        }
        return count;
    }
};
*/

// approach 2 - Brian Kernighan’s Algorithm
// time complexity - O(n)
// space complexity - O(1)


class Solution {
  public:
    int setBits(int N){
        int count = 0;
        while (N){
            // will unset rightmost set bit
            N = N & (N-1); 
            count++;
        }
        return count;    
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}
  // } Driver Code Ends