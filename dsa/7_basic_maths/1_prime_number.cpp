// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    // time complexity - O(n)
    // space complexity - O(1)
    // int isPrime(int N){
    //     if (N==0 || N==1){
    //         return false;
    //     }
    //     for (int i = 2 ; i <  N ; i++){
    //         if (N%i==0){
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // time complexity - O(n) (better)
    // space complexity - O(1)
    // int isPrime(int N){
    //     if (N==0 || N==1){
    //         return false;
    //     }
    //     for (int i = 2 ; i <=  N/2 ; i++){
    //         if (N%i==0){
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // time complexity - O(root n)
    // space complexity - O(1)
    int isPrime(int N){
        if (N==0 || N==1){
            return false;
        }
        for (int i = 2 ; i*i <=  N ; i++){
            if (N%i==0){
                return false;
            }
        }
        return true;
    }
    
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isPrime(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends