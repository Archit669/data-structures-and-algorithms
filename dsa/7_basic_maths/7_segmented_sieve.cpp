// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    // approach -1 (bruteforce)
    long long primeProduct(long long L, long long R){
        vector<bool> prime(R+1,true);
        prime[0] = prime[1] = false;
        long long prod = 1;

        for (int i = 2 ; i <= R ; i++){
            if (prime[i]){
                if (i >= L) prod*= i;
                for (int j = 2*i ; j<=R ; j+=i){
                    prime[j] = false;
                }
            }
        }
        
        return prod;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends